#!/usr/bin/env python3
"""Rename an object's sections so the linker places them by address.

usage: tail_obj.py OBJCOPY IN OUT TEXT DATA

TEXT and DATA are addresses (or `-`). The object's .text sections are renamed
.tail.<TEXT> and its .data/.rodata/.sdata sections .tail.<DATA> (8 hex
digits). The linker script collects everything named .tail.* with
SORT_BY_NAME after the code, so these sections land in address order
whatever the object's position on the command line (configure.py,
docs/data_split.md). OUT is rewritten only when it changes, so the rule can
use ninja's restat.
"""
import os
import subprocess
import sys

TEXT_KINDS = (".text",)
DATA_KINDS = (".data", ".rodata", ".sdata")


def tail_name(addr):
    return f".tail.{addr:08X}"


def rename(objcopy, src, dst, text=None, data=None):
    args = []
    if text is not None:
        args += ["--rename-section", f".text={tail_name(text)}"]
    if data is not None:
        for k in DATA_KINDS:
            args += ["--rename-section", f"{k}={tail_name(data)}"]
    subprocess.check_call([objcopy] + args + [src, dst + ".tmp"])
    with open(dst + ".tmp", "rb") as f:
        new = f.read()
    old = None
    if os.path.exists(dst):
        with open(dst, "rb") as f:
            old = f.read()
    if old == new:
        os.unlink(dst + ".tmp")
    else:
        os.replace(dst + ".tmp", dst)


def main():
    objcopy, src, dst, text, data = sys.argv[1:6]
    addr = lambda v: None if v == "-" else int(v, 0)
    rename(objcopy, src, dst, addr(text), addr(data))


if __name__ == "__main__":
    main()