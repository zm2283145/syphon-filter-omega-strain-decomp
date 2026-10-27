#!/usr/bin/env python3
"""Shared helpers: ELF function loading and MIPS (R5900) normalisation."""
import os, struct, subprocess, hashlib, json, pickle

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
# outputs (private, gitignored)
P1 = os.environ.get('SFOS_P1_DIR', os.path.join(REPO, 'build', 'agents', 'P1'))
os.makedirs(P1, exist_ok=True)
PROTO_DIR = os.environ.get('SFOS_PROTO_DIR', os.path.join(REPO, 'orig', 'prototypes'))
PROTOS = {
    'earlier': os.path.join(PROTO_DIR, 'SCUS_972.64_earlier_proto.elf'),
    'early': os.path.join(PROTO_DIR, 'SCUS_973.97_early_proto.elf'),
}
BIN = os.path.join(REPO, '.tools', 'binutils', 'mips-ps2-decompals-')
CACHE = os.path.join(P1, 'cache')
os.makedirs(CACHE, exist_ok=True)


def demangle_all(names):
    names = list(names)
    if not names:
        return {}
    p = subprocess.run([BIN + 'c++filt'], input='\n'.join(names) + '\n', capture_output=True, text=True)
    out = p.stdout.split('\n')
    return {n: (out[i] if i < len(out) and out[i] else n) for i, n in enumerate(names)}


def load_main(path):
    """Return (vaddr, bytes) of the code segment 'main' (section 5)."""
    from elftools.elf.elffile import ELFFile
    f = ELFFile(open(path, 'rb'))
    for s in f.iter_sections():
        if s['sh_addr'] == 0x100000 and s['sh_size'] > 0x100000:
            return 0x100000, s.data()
    raise RuntimeError('no main section')


def elf_symbols(path):
    from elftools.elf.elffile import ELFFile
    f = ELFFile(open(path, 'rb'))
    st = f.get_section_by_name('.symtab')
    out = []
    for s in st.iter_symbols():
        out.append((s.name, s['st_value'], s['st_size'], s['st_info']['type'], s['st_info']['bind'], s['st_shndx']))
    return out


# ---------------------------------------------------------------- MIPS ----
BRANCH_OPS = {0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
GPR_LOADS = set(range(0x20, 0x28)) | {0x37, 0x1e, 0x1a, 0x1b}
MEM_OPS = set(range(0x20, 0x40)) | {0x1a, 0x1b, 0x1e, 0x1f}


def opkey(w):
    """Opcode identity (no operands)."""
    op = w >> 26
    if op == 0:
        return 0x100 | (w & 63)
    if op == 1:
        return 0x200 | ((w >> 16) & 31)
    if op in (0x10, 0x11, 0x12):
        rs = (w >> 21) & 31
        if op == 0x11 and rs in (0x10, 0x14):
            return (op << 12) | 0x800 | (rs << 6) | (w & 63)
        if op == 0x12 and rs >= 0x10:
            return (op << 12) | 0x800 | (w & 0x7ff) >> 0
        return (op << 12) | (rs << 6)
    if op == 0x1c:
        f = w & 63
        if f in (0x08, 0x09, 0x28, 0x29):
            return 0x1c000 | (f << 5) | ((w >> 6) & 31)
        return 0x1c000 | (f << 5)
    return op


def normalise(code, base):
    """Return (h0tokens, h1tokens, h2tokens, calls, hiaddrs).
    h0: exact except jal targets and %hi/%lo / gp-relative immediates.
    h1: opcode + register fields (+branch offsets, shift amounts).
    h2: opcode only.
    calls: list of absolute jal targets in order.
    refs: list of absolute data addresses formed by lui/lo pairs (in order).
    """
    n = len(code) // 4
    ws = struct.unpack_from('<%dI' % n, code)
    h0, h1, h2, calls, refs = [], [], [], [], []
    hi = {}
    for i, w in enumerate(ws):
        op = w >> 26
        k = opkey(w)
        rs = (w >> 21) & 31; rt = (w >> 16) & 31; rd = (w >> 11) & 31
        h2.append(k)
        if op in (2, 3):
            tgt = ((base + i * 4) & 0xf0000000) | ((w & 0x3ffffff) << 2)
            if op == 3:
                calls.append(tgt)
            h0.append(k); h1.append(k)
            continue
        if op == 0x0f:  # lui
            hi[rt] = (w & 0xffff) << 16
            h0.append((k, rt)); h1.append((k, rt))
            continue
        if op in (0x09, 0x0d) or op in MEM_OPS:
            imm = w & 0xffff
            if rs in hi:
                v = hi[rs] + (imm - 0x10000 if imm & 0x8000 and op != 0x0d else imm)
                refs.append(v & 0xffffffff)
                h0.append((k, rs, rt, 'A'))
            elif rs == 28:
                h0.append((k, rs, rt, 'G'))
            else:
                h0.append((k, rs, rt, imm))
            h1.append((k, rs, rt))
            # destination register overwritten?
            if op in (0x09, 0x0d) or op in GPR_LOADS:
                hi.pop(rt, None)
            continue
        if op in BRANCH_OPS or op == 1:
            h0.append((k, rs, rt, w & 0xffff)); h1.append((k, rs, rt, w & 0xffff))
            continue
        if op == 0:
            h0.append((k, w & 0x3ffffff)); h1.append((k, w & 0x3ffffff))
            if rd in hi and (w & 63) not in (8, 9, 0x18, 0x19, 0x1a, 0x1b, 0x11, 0x13):
                hi.pop(rd, None)
            continue
        if op < 0x10:  # other immediates (slti, andi, xori, addi, daddiu...)
            h0.append((k, w & 0x3ffffff)); h1.append((k, rs, rt))
            hi.pop(rt, None)
            continue
        h0.append((k, w & 0x3ffffff)); h1.append((k, w & 0x3ffffff))
        if op == 0x1c:
            hi.pop(rd, None)
    return h0, h1, h2, calls, refs


def hsh(seq):
    return hashlib.blake2b(repr(seq).encode(), digest_size=10).hexdigest()


def strip_trailing_nops(code):
    while len(code) >= 4 and code[-4:] == b'\0\0\0\0':
        code = code[:-4]
    return code


def cstring_at(blob, base, addr, maxlen=200):
    o = addr - base
    if o < 0 or o >= len(blob):
        return None
    e = blob.find(b'\0', o, o + maxlen)
    if e <= o or e - o < 4:
        return None
    s = blob[o:e]
    if all(32 <= c < 127 or c in (9, 10, 13) for c in s):
        return s.decode()
    return None
