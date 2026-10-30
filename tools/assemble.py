#!/usr/bin/env python3
"""Assemble one file and lower its .text alignment to 4 bytes.

GNU as aligns .text to 16 bytes, but splat's assembly chunks may start right
after an 8-byte aligned GCC function. The original layout is fully described
by the objects' order, so the section alignment must not add padding.

usage: assemble.py [--relative-jumptables] AS OBJCOPY ALIGN OUT IN [ASFLAGS...]

ALIGN is the largest power of two (<= 16) dividing the chunk's start address,
so the padding in front of the chunk is the same as in the retail layout.

--relative-jumptables (objdiff targets of C units that link their data):
jump-table entries `.word .L00123458` are rewritten as `.word func + 0x48`,
the form the compiler emits (R_MIPS_32 against the function with the offset
in place), so objdiff compares equal data and relocations.

config/asm_literal_offsets.json scopes reviewed array-stride constants to a
single comparison target. Spurious %hi/%lo symbol annotations are replaced by
the original literal operands only after validating instruction words, the
encoded value and a dynamic-base addition. Other references are unchanged.
"""
import json
import re
from pathlib import Path
import subprocess
import sys

GLABEL = re.compile(r"\s*glabel (\S+)")
ADDR = re.compile(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")
WORD = re.compile(r"(\.word\s+)\.L([0-9A-F]{8})\b")


def relative_jumptables(text):
    funcs, pending = [], None
    for line in text.splitlines():
        m = GLABEL.match(line)
        if m:
            pending = m.group(1); continue
        if pending:
            m = ADDR.match(line)
            if m:
                funcs.append((int(m.group(1), 16), pending)); pending = None
    funcs.sort()

    def repl(m):
        a = int(m.group(2), 16)
        owner = [f for f in funcs if f[0] <= a]
        if not owner:
            return m.group(0)
        start, name = owner[-1]
        return f"{m.group(1)}{name} + {a - start:#x}"
    return WORD.sub(repl, text)


ROOT = Path(__file__).resolve().parent.parent
INSN = re.compile(r"^\s*/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\*/")


def literal_offsets(text, pairs):
    """Remove only explicitly reviewed false address relocations on array strides.

    Require original instruction words to encode the configured constant and an
    intervening addition of a dynamic base. Never change instruction opcodes,
    registers or original instruction values; the full linked hash remains the final gate.
    """
    lines = text.splitlines(keepends=True)
    records = {}
    for index, line in enumerate(lines):
        match = INSN.match(line)
        if match:
            addr = int(match[1], 16)
            word = int.from_bytes(bytes.fromhex(match[2]), "little")
            records[addr] = (index, word)
    for pair in pairs:
        hi, lo, value = (int(pair[k], 0) for k in ("hi", "lo", "value"))
        if hi not in records or lo not in records:
            raise ValueError(f"literal offset pair {hi:#x}/{lo:#x}: instruction missing")
        hi_index, hw = records[hi]
        lo_index, lw = records[lo]
        if not (hi_index < lo_index and hw >> 26 == 15 and (hw >> 16) & 31 == 1
                and (hw >> 21) & 31 == 0 and lw >> 26 == 43
                and (lw >> 21) & 31 == 1 and (lw >> 16) & 31 == 0):
            raise ValueError(f"literal offset pair {hi:#x}/{lo:#x}: expected lui at / sw zero")
        low = ((lw & 0xFFFF) ^ 0x8000) - 0x8000
        if not 0 <= value <= 0xFFFFFFFF or (((hw & 0xFFFF) << 16) + low) & 0xFFFFFFFF != value:
            raise ValueError(f"literal offset pair {hi:#x}/{lo:#x}: encoded value differs")
        dynamic_base = False
        for index, word in records.values():
            if hi_index < index < lo_index and word >> 26 == 0 and word & 63 == 33:
                rs, rt, rd = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31
                if rd == 1 and ((rs == 1 and rt not in (0, 1)) or (rt == 1 and rs not in (0, 1))):
                    dynamic_base = True
        if not dynamic_base:
            raise ValueError(f"literal offset pair {hi:#x}/{lo:#x}: no dynamic-base addition")
        high_reloc = "%hi(" in lines[hi_index]
        low_reloc = "%lo(" in lines[lo_index]
        if high_reloc != low_reloc:
            raise ValueError(f"literal offset pair {hi:#x}/{lo:#x}: incomplete relocation pair")
        if high_reloc:
            lines[hi_index] = re.sub(r"%hi\([^)]*\)", hex(hw & 0xFFFF), lines[hi_index], count=1)
            lines[lo_index] = re.sub(r"%lo\([^)]*\)", str(low), lines[lo_index], count=1)
    return "".join(lines)


def literal_offset_pairs(source):
    try:
        unit = Path(source).resolve().relative_to((ROOT / "asm").resolve()).with_suffix("").as_posix()
    except ValueError:
        return []
    config = ROOT / "config" / "asm_literal_offsets.json"
    if not config.exists():
        return []
    return json.loads(config.read_text()).get(unit, {}).get("pairs", [])


def main():
    args = sys.argv[1:]
    rel = args[0] == "--relative-jumptables"
    if rel:
        args = args[1:]
    as_, objcopy, align, out, src, *flags = args
    pairs = literal_offset_pairs(src)
    if rel or pairs:
        tmp = out + ".s"
        with open(src, errors="replace") as f:
            text = f.read()
        if pairs:
            text = literal_offsets(text, pairs)
        if rel:
            text = relative_jumptables(text)
        with open(tmp, "w") as f:
            f.write(text)
        src = tmp
    subprocess.check_call([as_] + flags + ["-o", out, src])
    subprocess.check_call([objcopy, "--set-section-alignment", f".text={align}", out])


if __name__ == "__main__":
    main()