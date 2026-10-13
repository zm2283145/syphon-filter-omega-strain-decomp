#!/usr/bin/env python3
"""Apply the function names in config/symbol_addrs.txt to the C sources.

splat already uses the names for the assembly; matched C still defines and
calls functions as func_<ADDRESS>. This replaces every func_<ADDRESS> token in
src/ and include/ with the name configured for that address.

`merge_units: begin/end func_<ADDRESS>` markers keep their address labels,
because tools/merge_units.py and tools/clone_match.py read the address from
them; markers renamed by older versions of this script are restored. Line
endings are preserved.
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
names = {}
for line in (ROOT / "config" / "symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;\s*//.*type:func", line)
    if m and not m.group(1).startswith("func_"):
        names[f"func_{int(m.group(2), 16):08X}"] = m.group(1)
addr_of = {v: k for k, v in names.items()}
MARKER = re.compile(r"^(/\* merge_units: (?:begin|end) )(\S+)( \*/)", re.M)
TOKEN = re.compile(r"\bfunc_[0-9A-F]{8}(?=\b|_)")


def rename(text):
    out, pos = [], 0
    for m in MARKER.finditer(text):
        out.append(TOKEN.sub(lambda t: names.get(t.group(0), t.group(0)), text[pos:m.start()]))
        out.append(m.group(1) + addr_of.get(m.group(2), m.group(2)) + m.group(3))
        pos = m.end()
    out.append(TOKEN.sub(lambda t: names.get(t.group(0), t.group(0)), text[pos:]))
    return "".join(out)


changed = 0
for p in list((ROOT / "src").rglob("*.c")) + list((ROOT / "include").rglob("*.h")):
    with open(p, newline="") as f:
        text = f.read()
    new = rename(text)
    if new != text:
        with open(p, "w", newline="") as f:
            f.write(new)
        changed += 1
print(f"{len(names)} names, {changed} files updated")