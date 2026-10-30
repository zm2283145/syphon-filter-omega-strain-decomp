param([string[]]$Lanes)
# Re-check every build\pending\<lane>\<kind>_<ADDR>.c with check_match before a round.
# Prints OK/FAIL per file. FAIL includes any UNDEF other than __dl__FPv (invented callee names).
# usage: tools\workflow\verify_pending.ps1 -Lanes r157   (or -Lanes l1,l2,...)
$RepoRoot = (Resolve-Path "$PSScriptRoot\..\..").Path; Set-Location $RepoRoot
if (-not $env:CW38_DIR) { $env:CW38_DIR = 'D:\Claude\cw_builds\mwcps2-3.0b38-030307' }
if (-not $env:CW50_DIR) { $env:CW50_DIR = 'D:\Claude\cw_builds\mwcps2-3.0b50-030527' }
if (-not $env:CW304_DIR) { $env:CW304_DIR = 'D:\Program Files (x86)\Metrowerks\CodeWarrior3.04\PS2_Tools\Command_Line_Tools' }
foreach ($L in $Lanes) { Get-ChildItem "build\pending\$L\*.c" | % {
  $kind = ($_.BaseName -split '_')[0]
  $o = & .venv\Scripts\python.exe tools\check_match.py $_.FullName -c $kind 2>&1 | Out-String
  $bad = ($o -split "`n" | ? { $_ -match '\b(DIFF|MISSING|NONMATCH|MISMATCH)\b' -or ($_ -match 'UNDEF' -and $_ -notmatch '__dl__FPv') })
  if ($bad -or $o -notmatch 'MATCH') { "FAIL $L\$($_.Name)"; $bad | Select -First 3 } else { "OK   $L\$($_.Name)" } } }
