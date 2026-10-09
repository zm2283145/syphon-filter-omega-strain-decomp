#!/usr/bin/env python3
"""Download the build tools into .tools/ (git-ignored).

  * MIPS binutils for the PS2 (decompals/binutils-mips-ps2-decompals)
  * Metrowerks CodeWarrior PS2 compiler builds as archived by decomp.me
    (decompme/compilers). These are proprietary Metrowerks tools; only fetch
    them if you are entitled to use them. They are never committed.
  * EE-GCC 2.95.3 (decompme/compilers, ps2_compilers archive) for library code
  * objdiff-cli (encounter/objdiff)
  * wibo (Linux only, runs the Windows compiler)
"""
import argparse
import io
import platform
import stat
import sys
import tarfile
import urllib.request
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / ".tools"
BINUTILS_VER = "v0.10"
OBJDIFF_VER = "v3.8.2"
WIBO_VER = "1.2.0"
COMPILERS = ["mwcps2-3.0.3-020716"]


def fetch(url):
    print("downloading", url)
    with urllib.request.urlopen(url) as r:
        return r.read()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--compiler", action="append", help="extra decomp.me compiler id(s)")
    a = ap.parse_args()
    sysname = platform.system()
    TOOLS.mkdir(exist_ok=True)

    host = {"Windows": "windows-x86-64.zip", "Linux": "linux-x86-64.tar.gz",
            "Darwin": "macos-arm64.tar.gz"}[sysname]
    if not (TOOLS / "binutils").exists():
        data = fetch("https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/"
                     f"{BINUTILS_VER}/binutils-mips-ps2-decompals-{host}")
        dest = TOOLS / "binutils"
        if host.endswith(".zip"):
            zipfile.ZipFile(io.BytesIO(data)).extractall(dest)
        else:
            tarfile.open(fileobj=io.BytesIO(data)).extractall(dest)
        for f in dest.iterdir():
            f.chmod(f.stat().st_mode | stat.S_IEXEC)

    for comp in COMPILERS + (a.compiler or []):
        dest = TOOLS / "mwcc" / comp
        if dest.exists():
            continue
        data = fetch(f"https://github.com/decompme/compilers/releases/download/compilers/{comp}.tar.gz")
        dest.mkdir(parents=True)
        tarfile.open(fileobj=io.BytesIO(data)).extractall(dest)

    # EE-GCC for the SDK/middleware units (src/lib); GPL compiler, Windows build
    # from decomp.me's archive (runs through wibo on Linux).
    if not (TOOLS / "eegcc" / "ee-gcc2.95.3-136").exists():
        data = fetch("https://github.com/decompme/compilers/releases/download/compilers/ps2_compilers.tar.xz")
        with tarfile.open(fileobj=io.BytesIO(data)) as t:
            members = [m for m in t.getmembers() if m.name.startswith("ee-gcc2.95.3-136/")]
            t.extractall(TOOLS / "eegcc", members=members)

    exe = {"Windows": "objdiff-cli-windows-x86_64.exe", "Linux": "objdiff-cli-linux-x86_64",
           "Darwin": "objdiff-cli-macos-arm64"}[sysname]
    out = TOOLS / ("objdiff-cli.exe" if sysname == "Windows" else "objdiff-cli")
    if not out.exists():
        out.write_bytes(fetch(f"https://github.com/encounter/objdiff/releases/download/{OBJDIFF_VER}/{exe}"))
        out.chmod(out.stat().st_mode | stat.S_IEXEC)

    if sysname == "Linux" and not (TOOLS / "wibo").exists():
        w = TOOLS / "wibo"
        w.write_bytes(fetch(f"https://github.com/decompals/wibo/releases/download/{WIBO_VER}/wibo-x86_64"))
        w.chmod(w.stat().st_mode | stat.S_IEXEC)
    print("tools ready in", TOOLS)


if __name__ == "__main__":
    sys.exit(main())
