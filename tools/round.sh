#!/usr/bin/env bash
# Coordinator round (Linux): integrate build/pending/<round>, full build, verify, report, test, commit, push.
# usage: bash tools/round.sh <round> "<subject>" [--no-push]
#        <round> may be "-" to skip integration (e.g. a naming-only commit).
set -uo pipefail
cd "$(dirname "$0")/.."
ROUND="$1"; MSG="$2"; PUSH="${3:-push}"
PY=.venv/bin/python; NINJA=.venv/bin/ninja; LOG=build/round.log
SHA=9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6
say(){ echo "$(date +%H:%M:%S) $*" | tee -a "$LOG"; }
: > "$LOG"; [ -f ~/sfos-env.sh ] && source ~/sfos-env.sh  # sets CW38_DIR, CW50_DIR, CW304_DIR
F=(--compiler-dir "cwps2-3.0b38=$CW38_DIR" --compiler-dir "cwps2-3.0b50=$CW50_DIR" --compiler-dir "cwps2-3.04=$CW304_DIR")
mkdir -p build/agents; touch build/agents/HOLD
trap 'rm -f build/agents/HOLD' EXIT
[ "$(git rev-parse --abbrev-ref HEAD)" = main ] || { say "not on main"; exit 1; }
git fetch -q origin main
[ "$(git rev-parse HEAD)" = "$(git rev-parse origin/main)" ] || { say "origin/main moved; pull/rebase first"; exit 1; }
$PY tools/data_gen.py release --all > build/dg_release.log 2>&1 || { say "data_gen release failed"; exit 1; }
# regenerate asm/ for the current splat.yaml so the integrator sees the real function starts
$PY configure.py --elf orig/SCUS_972.64 "${F[@]}" > build/cfg0.log 2>&1 || { say "configure 0 failed"; exit 1; }
BATCH=""
if [ "$ROUND" != "-" ]; then
  BATCH="build/pending/${ROUND}_batch$(date +%H%M%S)"; mv "build/pending/$ROUND" "$BATCH"; mkdir -p "build/pending/$ROUND"
  say "integrating $(ls "$BATCH" | wc -l) files from $BATCH"
  $PY tools/integrate_pending.py . "$BATCH" 2>&1 | tee -a "$LOG" | tail -5
  [ ${PIPESTATUS[0]} -eq 0 ] || { say "integration failed"; exit 1; }
  if grep -q "no function start in asm" "$LOG"; then say "WARNING: some files skipped (no function start); they stay in $BATCH"; fi
fi
$PY tools/apply_names.py >> "$LOG" 2>&1 || { say "apply_names failed"; exit 1; }
say "configure"
$PY configure.py --elf orig/SCUS_972.64 "${F[@]}" > build/cfg1.log 2>&1 || { say "configure 1 failed"; exit 1; }
$PY tools/data_gen.py > build/datagen.log 2>&1 || { say "data_gen failed"; exit 1; }
$PY configure.py "${F[@]}" > build/cfg2.log 2>&1 || { say "configure 2 failed"; exit 1; }
# ninja does not track header dependencies: rebuild every C file when a header changed
if [ -n "$(git status --porcelain -- include)" ]; then find src -name "*.c" -exec touch {} +; say "headers changed: rebuilding all C"; fi
say "ninja"
$NINJA -j3 > build/ninja.log 2>&1
if ! grep -q "^OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 $SHA)" build/ninja.log; then
  say "BUILD DOES NOT MATCH"; grep -E "FAILED|error|MISMATCH" build/ninja.log | head -10 | tee -a "$LOG"; exit 1
fi
say "OK line printed"
$NINJA report > build/report.log 2>&1 || { say "report failed"; exit 1; }
$PY tools/publish_report.py >> "$LOG" 2>&1 || { say "publish_report failed"; exit 1; }
$PY -m unittest discover -s tests -p 'test_*.py' -q > build/tests.log 2>&1 || { say "tests failed (build/tests.log)"; tail -20 build/tests.log; exit 1; }
LINE=$($PY -c "import json;m=json.load(open('progress/report.json'))['measures'];print(f\"{m['matched_functions']:,} / {m['total_functions']:,} functions, {float(m['matched_code_percent']):.2f}% code, {float(m.get('matched_data_percent',0)):.2f}% data\")")
say "$LINE"
git add -A src config include progress tools tests
if git diff --cached --name-only | grep -Eiq '(^orig/|^asm/|^build/|^\.tools/|\.rom$|\.elf$|\.exe$|\.dll$|SCUS_)'; then say "STOP: private/generated file staged"; exit 1; fi
git diff --cached --quiet && { say "nothing to commit"; exit 0; }
printf '%s\n\nThe build prints the OK line (SHA-256 9924da91...31dc6).\n%s.\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\nClaude-Session: https://claude.ai/code/session_01Uqack8zNUGjdqTDiYfZ6mk\n' "$MSG" "$LINE" > build/msg.txt
git commit -q -F build/msg.txt || { say "commit failed"; exit 1; }
say "committed $(git rev-parse --short HEAD)"
if [ -n "$BATCH" ]; then
  # files the integrator skipped go back to the pending queue
  grep -oE "^  - [A-Za-z0-9_]+\.c" "$LOG" | awk '{print $2}' | while read f; do [ -f "$BATCH/$f" ] && mv "$BATCH/$f" "build/pending/$ROUND/"; done
  mkdir -p build/integrated && mv "$BATCH" build/integrated/
fi
if [ "$PUSH" = push ]; then git push -q origin main 2>&1 | tee -a "$LOG"; say "pushed $(git rev-parse --short HEAD)"; fi
exit 0
