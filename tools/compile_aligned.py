#!/usr/bin/env python3
"""Run a compiler, then set the object's .text alignment.

usage: compile_aligned.py OBJCOPY ALIGN OUT IN -- COMPILER [ARGS...]

Used for EE-GCC units: GCC aligns .text to 8 bytes, but a unit that follows
a 16-byte padded Metrowerks unit must start on the address the retail layout
gives it, so the alignment is set from the unit's start address.
"""
import subprocess
import sys

objcopy, align, out, src, sep, *cmd = sys.argv[1:]
assert sep == "--"
subprocess.check_call(cmd + ["-o", out, src])
subprocess.check_call([objcopy, "--set-section-alignment", f".text={align}", out])
