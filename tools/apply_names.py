#!/usr/bin/env python3
"""Apply the function names in config/symbol_addrs.txt to the C sources.

splat already uses the names for the assembly; matched C still defines and
calls functions as func_<ADDRESS>. This replaces every func_<ADDRESS> token in
src/ and include/ with the name configured for that address.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
names = {}
for line in (ROOT / "config" / "symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;\s*//.*type:func", line)
    if m and not m.group(1).startswith("func_"):
        names[f"func_{int(m.group(2), 16):08X}"] = m.group(1)
changed = 0
for p in list((ROOT / "src").rglob("*.c")) + list((ROOT / "include").rglob("*.h")):
    text = p.read_text()
    new = re.sub(r"\bfunc_[0-9A-F]{8}\b", lambda m: names.get(m.group(0), m.group(0)), text)
    if new != text:
        p.write_text(new)
        changed += 1
print(f"{len(names)} names, {changed} files updated")
