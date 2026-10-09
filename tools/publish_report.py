#!/usr/bin/env python3
"""Copy the locally generated objdiff report into progress/report.json.

CI cannot build this project without the retail executable, which is never
uploaded. Instead, after a verified local build (`ninja` prints OK) run:

    ninja report
    python tools/publish_report.py

and commit progress/report.json. The GitHub workflow uploads that file as the
`SCUS_972.64_report` artifact that decomp.dev reads. The report holds only
unit/function names, sizes and match percentages - no game code or data.
"""
import json
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "build" / "report.json"
OK = ROOT / "build" / "SCUS_972.64.ok"
DST = ROOT / "progress" / "report.json"


def main():
    if not OK.exists() or not SRC.exists():
        sys.exit("Run `ninja` (must print OK) and `ninja report` first.")
    if OK.stat().st_mtime > SRC.stat().st_mtime + 1:
        sys.exit("build/report.json is older than the last verified build; run `ninja report`.")
    m = json.loads(SRC.read_text())["measures"]
    DST.parent.mkdir(exist_ok=True)
    shutil.copyfile(SRC, DST)
    print(f"progress/report.json: {m.get('matched_functions')}/{m.get('total_functions')} functions, "
          f"{float(m.get('matched_code_percent', 0)):.2f}% code")


if __name__ == "__main__":
    main()
