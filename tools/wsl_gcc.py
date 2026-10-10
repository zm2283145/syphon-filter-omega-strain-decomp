#!/usr/bin/env python3
"""Run a Linux-only EE-GCC build (such as ee-gcc2.96) from Windows through WSL.

usage: python tools/wsl_gcc.py COMPILER_DIR [gcc arguments ...]

The decomp.me EE-GCC 2.96 is a 32-bit Linux program. Under WSL it cannot
stat files on a Windows drive (EOVERFLOW from 64-bit inode numbers), so the
compiler directory is copied once into the WSL home (~/.cache/sfos-eegcc/), and
each compilation runs in a fresh WSL temporary directory: the source file and
the headers of every -I directory are sent in as a tar stream and the object file is copied
back. Arguments are passed through unchanged apart from paths.
"""
import io
import os
import shlex
import subprocess
import sys
import tarfile
from pathlib import Path


def wsl_path(p):
    p = Path(p).resolve()
    drive, rest = p.drive, p.as_posix()[len(p.drive):]
    return f"/mnt/{drive[0].lower()}{rest}" if drive else p.as_posix()


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    cdir = Path(sys.argv[1]).resolve()
    args = sys.argv[2:]
    if args and args[0] == "--":
        args = args[1:]
    buf = io.BytesIO()
    out, new = None, []
    with tarfile.open(fileobj=buf, mode="w") as tar:
        i = 0
        while i < len(args):
            a = args[i]
            if a == "-o":
                out = args[i + 1]
                new += ["-o", "out.o"]
                i += 2
                continue
            if a.startswith("-I"):
                d = a[2:]
                name = f"inc{len(new)}"
                if Path(d).is_dir():
                    tar.add(d, arcname=name, filter=lambda t: t if t.isdir() or t.name.endswith((".h", ".inc")) else None)
                new.append(f"-I{name}")
            elif not a.startswith("-") and Path(a).is_file():
                name = "src_" + Path(a).name
                tar.add(a, arcname=name)
                new.append(name)
            else:
                new.append(a)
            i += 1
    if out is None:
        sys.exit("wsl_gcc.py: -o OUTPUT is required")
    cache = f"$HOME/.cache/sfos-eegcc/{cdir.name}"
    script = (
        "set -e\n"
        f"C={cache}\n"
        f'if [ ! -x "$C/bin/ee-gcc" ]; then mkdir -p "$C" && cp -r {shlex.quote(wsl_path(cdir))}/. "$C"/; fi\n'
        'T=$(mktemp -d); trap \'rm -rf "$T"\' EXIT; cd "$T"; tar -mxf -\n'
        f'"$C/bin/ee-gcc" {" ".join(shlex.quote(x) for x in new)}\n'
        f"cp out.o {shlex.quote(wsl_path(Path(out).parent.resolve() / Path(out).name))}\n"
    )
    Path(out).parent.mkdir(parents=True, exist_ok=True)
    r = subprocess.run(["wsl", "-e", "bash", "-c", script], input=buf.getvalue())
    sys.exit(r.returncode)


if __name__ == "__main__":
    main()
