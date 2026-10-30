#!/usr/bin/env bash
# WSL half of round_wsl.ps1: mirror the Windows checkout into ~/sfos-decomp, integrate,
# build, report, then mirror src/config/include and progress/report.json back.
# usage: bash wsl_round.sh <windows repo as /mnt/... path> <batch dir relative to repo, or ->
set -uo pipefail
source ~/sfos-env.sh; cd ~/sfos-decomp
W="$1"; B="$2"; PY=.venv/bin/python
SHA=9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6
F=(--compiler-dir "cwps2-3.0b38=$CW38_DIR" --compiler-dir "cwps2-3.0b50=$CW50_DIR" --compiler-dir "cwps2-3.04=$CW304_DIR")
say(){ echo "$(date +%H:%M:%S) $*"; }
for d in src config include tests; do rsync -a --delete "$W/$d/" "$d/" || exit 1; done
rsync -a "$W/tools/" tools/ && rsync -a "$W/configure.py" "$W/progress" ./ || exit 1
$PY tools/data_gen.py release --all > /tmp/dg0.log 2>&1 || { say "data_gen release failed"; exit 1; }
$PY configure.py --elf orig/SCUS_972.64 "${F[@]}" > /tmp/cfg0.log 2>&1 || { say "configure 0 failed"; exit 1; }
if [ "$B" != "-" ]; then
  rm -rf /tmp/batch && cp -r "$W/$B" /tmp/batch
  say "integrating $(ls /tmp/batch | wc -l) files"
  $PY tools/integrate_pending.py . /tmp/batch > /tmp/integ.log 2>&1 || { say "integration failed"; tail /tmp/integ.log; exit 1; }
  cat /tmp/integ.log
fi
$PY tools/apply_names.py > /tmp/names.log 2>&1 || { say "apply_names failed"; exit 1; }
tail -1 /tmp/names.log
$PY configure.py --elf orig/SCUS_972.64 "${F[@]}" > /tmp/cfg1.log 2>&1 || { say "configure 1 failed"; exit 1; }
$PY tools/data_gen.py > /tmp/datagen.log 2>&1 || { say "data_gen failed"; exit 1; }
$PY configure.py "${F[@]}" > /tmp/cfg2.log 2>&1 || { say "configure 2 failed"; exit 1; }
# ninja does not track headers: rebuild all C when include/ differs from the last good build
H=$(find include -type f -print0 | sort -z | xargs -0 md5sum | md5sum | cut -c1-32)
if [ "$H" != "$(cat ~/.inc_hash 2>/dev/null)" ]; then find src -name "*.c" -exec touch {} +; say "headers changed: rebuilding all C"; fi
say ninja
.venv/bin/ninja > /tmp/ninja.log 2>&1
if ! grep -q "^OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 $SHA)" /tmp/ninja.log; then
  say "BUILD DOES NOT MATCH"; grep -E "FAILED|error|MISMATCH|undefined" /tmp/ninja.log | head -15; exit 1; fi
echo "$H" > ~/.inc_hash; say "OK line printed"
.venv/bin/ninja report > /tmp/report.log 2>&1 || { say "report failed"; exit 1; }
$PY tools/publish_report.py | tail -1
$PY -m unittest discover -s tests -p 'test_*.py' -q > /tmp/tests.log 2>&1 || { say "tests failed"; tail -20 /tmp/tests.log; exit 1; }
for d in src config include; do rsync -a --delete "$d/" "$W/$d/" || exit 1; done
cp progress/report.json "$W/progress/report.json"
say "WSL_ROUND_OK"
