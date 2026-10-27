#!/usr/bin/env python3
"""Rename func_XXXXXXXX tokens in agent drafts to the names now in config/symbol_addrs.txt.
usage: .venv/bin/python tools/rename_drafts.py <dir-or-file> [...]   (edits .c/.h files in place, LF kept)"""
import re, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
names = {}
for line in (ROOT / "config" / "symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;\s*//.*type:func", line)
    if m and not m.group(1).startswith("func_"):
        names[f"func_{int(m.group(2),16):08X}"] = m.group(1)
TOK = re.compile(r"\bfunc_[0-9A-F]{8}\b")
n = 0
for arg in sys.argv[1:]:
    p = Path(arg); files = [p] if p.is_file() else [f for f in p.rglob("*") if f.suffix in (".c", ".h")]
    for f in files:
        t = f.read_bytes().decode("latin-1"); u = TOK.sub(lambda m: names.get(m.group(0), m.group(0)), t)
        if u != t: f.write_bytes(u.encode("latin-1")); n += 1
print(n, "files renamed")
