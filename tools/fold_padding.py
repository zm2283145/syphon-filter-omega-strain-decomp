#!/usr/bin/env python3
"""Fold alignment padding into the code in front of it.

usage: python tools/fold_padding.py [REPO] [--check]

Retail places every function on a 16-byte boundary (8 or 4 for some library
code) and fills the gap after the previous function with zero words. When a
C unit is followed by an asm subsegment, splat's subsegment used to start
right after the C function, on those zero words: spimdisasm must open a
subsegment with a function, so it labelled the first `nop` func_<ADDR> (size
4) and objdiff counted it as an unmatched function. A lone nop is not a
function.

This rewrites config/splat.yaml so that such an asm subsegment starts at the
first real instruction instead, or is dropped when it holds nothing but the
padding. The padding bytes then belong to the range of the unit in front
(splat writes them after the last function's endlabel, so they are not part
of any function) and the build reproduces them as link alignment: the next
object's .text alignment is the largest power of two (<= 16) dividing its
address (tools/assemble.py, tools/compile_aligned.py; Metrowerks emits 16)
and the link script fills with zeros. A run is folded only when that is
exactly what the linker will produce:

- the words are all zero and follow a code subsegment (c, asm or hasm);
- the run ends at a code start: inside the same asm subsegment, or at the
  start of the next subsegment if that is code (asm, hasm, c);
- aligning the run's start up to the alignment of its end gives its end.

The rewrite is idempotent; tools/integrate_pending.py applies it after every
integration, so new C units never leave a padding subsegment behind.
--check only reports how many subsegments would change (exit 1 if any).
"""
import sys
from pathlib import Path

BASE = 0x100000
CODE = ("c", "asm", "hasm")


def alignment(addr):
    """Alignment the build gives an object that starts at addr (configure.py)."""
    return next(a for a in (16, 8, 4) if addr % a == 0)


def fold(segs, end, rom, rom_base=0):
    """Fold padding in segs = [[start, type, name, comments], ...] (ROM offsets).

    end: ROM offset where the subsegment list ends. rom: the ROM image, whose
    byte 0 is ROM offset rom_base. Returns (new segs, [(old start, new start or
    None)]) - None meaning the subsegment held only padding and was dropped.
    """
    out, changes = [], []
    for i, seg in enumerate(segs):
        start, typ, name, comments = seg
        nxt = segs[i + 1] if i + 1 < len(segs) else None
        stop = nxt[0] if nxt else end
        prev = out[-1] if out else None
        if typ != "asm" or prev is None or prev[1] not in CODE:
            out.append(seg); continue
        x = start
        while x < stop:
            word = rom[x - rom_base:x - rom_base + 4]
            if len(word) < 4 or any(word):
                break
            x += 4
        if x == start:
            out.append(seg); continue
        if x == stop and (nxt is None or nxt[1] not in CODE):
            out.append(seg); continue
        a = alignment(x + BASE)
        if (start + BASE + a - 1) // a * a != x + BASE:
            out.append(seg); continue
        if x == stop:
            # only padding: the next subsegment keeps the comments
            if comments and nxt is not None:
                nxt[3] = comments + nxt[3]
            changes.append((start, None))
            continue
        if name and name == f"sinit_{start + BASE:X}":
            name = f"sinit_{x + BASE:X}"
        out.append([x, typ, name, comments])
        changes.append((start, x))
    return out, changes


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    check = "--check" in sys.argv[1:]
    repo = Path(args[0] if args else Path(__file__).resolve().parent.parent).resolve()
    sys.path.insert(0, str(repo / "tools"))
    import integrate_pending  # noqa: E402

    yp = repo / "config" / "splat.yaml"
    y = yp.read_text().split("\n")
    i0, i1, segs, indent = integrate_pending.load_segments(y)
    end = integrate_pending.end_of_segments(y, i1)
    rom = (repo / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    segs, changes = fold(segs, end, rom)
    moved = sum(1 for _, x in changes if x is not None)
    dropped = len(changes) - moved
    print(f"padding: {moved} asm subsegments moved to their first instruction, "
          f"{dropped} padding-only subsegments dropped")
    if check:
        sys.exit(1 if changes else 0)
    if changes:
        y[i0:i1] = integrate_pending.dump_segments(segs, indent)
        yp.write_text("\n".join(y), newline="\n")


if __name__ == "__main__":
    main()
