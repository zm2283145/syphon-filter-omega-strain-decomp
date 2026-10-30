#!/usr/bin/env bash
# One-time setup of the WSL build copy used by round_wsl.ps1 (run as root in the distro).
# usage: bash setup_wsl.sh /mnt/d/Claude/syphon-filter-omega-strain-decomp
# Edit the three compiler paths below to where the Metrowerks compilers live on Windows.
set -e
W="$1"
export DEBIAN_FRONTEND=noninteractive
apt-get update -qq >/dev/null && apt-get install -y -qq python3-venv python3-pip rsync >/dev/null
mkdir -p ~/sfos-decomp
rsync -a --exclude build/ --exclude .venv/ --exclude .tools/ --exclude asm/ --exclude .git/ --exclude '*.o' "$W/" ~/sfos-decomp/
cat > ~/sfos-env.sh <<'EOF'
export CW38_DIR=/mnt/d/Claude/cw_builds/mwcps2-3.0b38-030307
export CW50_DIR=/mnt/d/Claude/cw_builds/mwcps2-3.0b50-030527
export CW304_DIR="/mnt/d/Program Files (x86)/Metrowerks/CodeWarrior3.04/PS2_Tools/Command_Line_Tools"
EOF
cd ~/sfos-decomp
python3 -m venv .venv && .venv/bin/pip install -q -r requirements.txt
.venv/bin/python tools/setup_tools.py 2>&1 | tail -5
# setup_tools only fetches two EE-GCC versions; the library units need all of them,
# otherwise they silently fall back to asm and the report loses ~470 functions.
mkdir -p .tools/eegcc && cp -rn "$W/.tools/eegcc/." .tools/eegcc/
ls .tools .tools/eegcc
