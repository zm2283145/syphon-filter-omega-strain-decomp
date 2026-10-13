#!/usr/bin/env python3
"""Run a compiler, then set the object's .text alignment.

usage: compile_aligned.py [--pool ROM GP VRAM] OBJCOPY ALIGN OUT IN -- COMPILER [ARGS...]

Used for EE-GCC units: GCC aligns .text to 8 bytes, but a unit that follows
a 16-byte padded Metrowerks unit must start on the address the retail layout
gives it, so the alignment is set from the unit's start address.

With --pool (EE-GCC units; VRAM is the unit's retail address), gp-relative
literals in .lit4/.lit8 are pointed at the retail literal pool and the
sections dropped (tools/lit_pool.py); objects without them are unchanged.
"""
import subprocess
import sys

import lit_pool

args = sys.argv[1:]
pool = None
if args[0] == "--pool":
    pool, args = args[1:4], args[4:]
objcopy, align, out, src, sep, *cmd = args
assert sep == "--"
# ee-gcc under wibo occasionally hangs at 0% CPU on a busy machine; a normal
# compile takes well under a second, so retry after a generous timeout.
for attempt in range(3):
    try:
        subprocess.check_call(cmd + ["-o", out, src], timeout=120)
        break
    except subprocess.TimeoutExpired:
        print(f"compile_aligned: {src} timed out, retrying", file=sys.stderr)
else:
    sys.exit(f"compile_aligned: {src} timed out 3 times")
extra = []
if pool:
    for name in lit_pool.resolve(out, pool[0], int(pool[1], 0), int(pool[2], 0)):
        extra += ["--remove-section", name]
subprocess.check_call([objcopy, "--set-section-alignment", f".text={align}", *extra, out])