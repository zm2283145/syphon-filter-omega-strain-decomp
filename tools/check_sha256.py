#!/usr/bin/env python3
"""Compare a built file with the expected SHA-256 and write a stamp on success."""
import hashlib
import sys

path, expected, stamp = sys.argv[1:4]
h = hashlib.sha256(open(path, "rb").read()).hexdigest()
if h != expected.lower():
    print(f"MISMATCH: {path}\n  got      {h}\n  expected {expected}")
    sys.exit(1)
open(stamp, "w").write(h + "\n")
print(f"OK: {path} matches retail SCUS_972.64 (SHA-256 {h})")
