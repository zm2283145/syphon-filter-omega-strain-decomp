#!/usr/bin/env python3
"""Assemble one file and lower its .text alignment to 4 bytes.

GNU as aligns .text to 16 bytes, but splat's assembly chunks may start right
after an 8-byte aligned GCC function. The original layout is fully described
by the objects' order, so the section alignment must not add padding.

usage: assemble.py AS OBJCOPY ALIGN OUT IN [ASFLAGS...]

ALIGN is the largest power of two (<= 16) dividing the chunk's start address,
so the padding in front of the chunk is the same as in the retail layout.
"""
import subprocess
import sys

as_, objcopy, align, out, src, *flags = sys.argv[1:]
subprocess.check_call([as_] + flags + ["-o", out, src])
subprocess.check_call([objcopy, "--set-section-alignment", f".text={align}", out])
