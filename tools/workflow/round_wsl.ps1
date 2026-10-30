param([string]$Round, [string]$Msg, [string]$Push = 'push', [string]$Distro = 'sfos3')
# One integration round: integrate build\pending\<Round>\*.c, build and report in WSL
# (see wsl_round.sh), then commit (and push) on Windows. Use '-' as Round to rebuild only.
# usage: tools\workflow\round_wsl.ps1 r157 "Match N more functions incl. ... (R157)" [nopush]
$ErrorActionPreference = 'Continue'
$RepoRoot = (Resolve-Path "$PSScriptRoot\..\..").Path
Set-Location $RepoRoot
$PY = '.venv\Scripts\python.exe'; $LOG = 'build\round.log'
function say($m) { $l = "$(Get-Date -f HH:mm:ss) $m"; $l; Add-Content $LOG $l }
Set-Content $LOG ''
if ((git rev-parse --abbrev-ref HEAD) -ne 'main') { say 'not on main'; exit 1 }
git fetch -q origin main
if ((git rev-parse HEAD) -ne (git rev-parse origin/main)) { say 'origin/main moved; pull first'; exit 1 }
$BATCH = '-'
if ($Round -ne '-') {
  $BATCH = "build/pending/${Round}_batch$(Get-Date -f HHmmss)"; Move-Item "build\pending\$Round" $BATCH; New-Item -ItemType Directory "build\pending\$Round" | Out-Null }
$wslRepo = '/mnt/' + $RepoRoot.Substring(0, 1).ToLower() + ($RepoRoot.Substring(2) -replace '\\', '/')
wsl -d $Distro -u root -e bash "$wslRepo/tools/workflow/wsl_round.sh" $wslRepo $BATCH 2>&1 | % { say $_ }
if (-not (Select-String $LOG -Pattern 'WSL_ROUND_OK' -Quiet)) { say 'WSL round failed (batch left in place; Windows src untouched)'; exit 1 }
$LINE = & $PY -c "import json;m=json.load(open('progress/report.json'))['measures'];print(f`"{m['matched_functions']:,} / {m['total_functions']:,} functions, {float(m['matched_code_percent']):.2f}% code, {float(m.get('matched_data_percent',0)):.2f}% data`")"
say $LINE
git add -A src config include progress tools tests configure.py docs README.md
if (git diff --cached --name-only | Select-String -Pattern '(^orig/|^asm/|^build/|^\.tools/|\.rom$|\.elf$|\.exe$|\.dll$|SCUS_)') { say 'STOP: private/generated file staged'; exit 1 }
git diff --cached --quiet; if (-not $LASTEXITCODE) { say 'nothing to commit'; exit 0 }
"$Msg`n`nThe build prints the OK line (SHA-256 9924da91...31dc6).`n$LINE." | Set-Content -NoNewline build\msg.txt
git commit -q -F build\msg.txt; if ($LASTEXITCODE) { say 'commit failed'; exit 1 }
say "committed $(git rev-parse --short HEAD)"
if ($BATCH -ne '-') {
  # files integrate_pending skipped go back to build\pending\<Round> for another try
  Select-String $LOG -Pattern '^\S+ +- ([A-Za-z0-9_]+\.c)' | % { $f = $_.Matches[0].Groups[1].Value; if (Test-Path "$BATCH\$f") { Move-Item "$BATCH\$f" "build\pending\$Round\" } }
  New-Item -ItemType Directory build\integrated -Force | Out-Null; Move-Item $BATCH build\integrated\ }
if ($Push -eq 'push') { git push -q origin main 2>&1 | % { say $_ }; say "pushed $(git rev-parse --short HEAD)" }
exit 0
