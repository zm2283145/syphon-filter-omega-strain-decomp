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
"""
import re
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


def main():
    args = sys.argv[1:]
    rel = args[0] == "--relative-jumptables"
    if rel:
        args = args[1:]
    as_, objcopy, align, out, src, *flags = args
    if rel:
        tmp = out + ".s"
        with open(src, errors="replace") as f:
            text = relative_jumptables(f.read())
        with open(tmp, "w") as f:
            f.write(text)
        src = tmp
    subprocess.check_call([as_] + flags + ["-o", out, src])
    subprocess.check_call([objcopy, "--set-section-alignment", f".text={align}", out])


if __name__ == "__main__":
    main()