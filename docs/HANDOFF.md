# Handoff: continuing the matching decompilation

This is the working state and the routine for whoever continues this project
(person or AI agent). Read [README.md](../README.md) for setup,
[PROGRESS.md](../PROGRESS.md) for the evidence and history, and
[MATCHING_TECHNIQUES.md](MATCHING_TECHNIQUES.md) before matching any function.

## Resume here (2026-10-30, Codex R172 automatic continuation) - START HERE

- Consolidated **infobar** from three source units into one original source
  file (13 source blocks). TextArea declarations consistently use opaque object
  pointers; SetText takes const char*. D_004BE220 is consistently a char array,
  removing a generated int* cast. Whole-unit comparison and retail hash pass.
- **13,983 / 14,347 functions; 90.33% code; 364 remaining.** No new function
  claimed this consolidation round. All135 tests pass; WSL_ROUND_OK confirms final synchronization.
- Another ready held draft: c151nm/work/best_001479D0.c strictly checks as three
  MATCH with explicit16/16/8byte boundaries: PointLightComp_Start,1479E0 virtual
  slot30 wrapper,1479F0 float getter. Current asm lumps them as one40-byte body.
  Dossier has no direct prototype mapping; established containing TU is weapon.cc.
  Correct boundaries, integrate and fold into weapon parts before full verification.
- Private evidence: build/agents/r172/NOTES.md and dossiers. Root scratch files
  preserved; no push/subagents. Automation remains active.

## Previous continuation (2026-10-30, Codex R171 automatic continuation)

- **13,983 / 14,347 functions; 90.33% code; 364 remaining.** Full retail
  SHA-256 unchanged; all **135 tests** pass. No new function claimed this round.
- Reduced **tremor** from four source units to two, combining its first five
  source blocks into tremor.c. The manager destructor remains separate as
  tremor_2.c. Tagged CameraShake declaration preserves its original typed
  definition; iterator declarations now agree with existing Word/Iter/Tree
  helper definitions and use explicit caller casts. push_back keeps its int
  arguments with caller-side address casts. Whole-unit and full retail checks pass.
- Final single-file merge remains blocked: adding the manager destructor grows
  compiled code from 0x810 to 0x824 bytes. Normalizing its own iterator prototypes
  did not fix this; those trials were reverted. Inspect the extra 20 bytes in
  actual merged compiler output before retrying; do not force the last boundary.
- Fresh remaining-candidate inventory: build/agents/r171/inventory.json. Private
  notes: r171/NOTES.md. Next consolidation candidate: infobar, whose generated
  adapters refer to unavailable Text_9E60; or use the fresh inventory for matching.
- Root scratch candidates preserved; no pushes/subagents. Final WSL_ROUND_OK
  includes retail hash, report, regression checks and synchronization.

## Previous continuation (2026-10-30, Codex R170 automatic continuation)

- **13,983 / 14,347 functions; 90.33% code; 364 remaining.** Full retail
  SHA-256 unchanged; all **135 tests** pass. No new function claimed this round.
- Consolidated **Rumble** from three parts into one original source file
  (four source blocks). D_004FEED0 now has one opaque byte-array declaration;
  both existing typed slot views retain the 28-byte stride and field operations.
  cJoyPad_SetVibration declarations consistently return int and take void* as
  their first parameter. Whole-unit comparison and full WSL retail build pass.
- Byte-swap 00357178 remains two scheduling differences (offsets4/8). A fresh
  32-variant sweep of half types, expressions, scheduling/optimizer pragmas
  and three empty-barrier forms produced no improvement. No C candidate added.
  Prototype dossier has no mapping; do not repeat this sweep without new evidence.
- tremor local-alias pointer-signature trials changed code and were reverted.
  Possible new approach: tagged CameraShake forward declaration preserving the
  original typed definition, and original int push_back signature with caller
  casts. Not tested. infobar can merge its first two units but later generated
  adapters refer to unavailable Text_9E60. Other reviewed units have separated data.
- Private details: build/agents/r170/NOTES.md and scratch sweep sources. Root
  scratch files preserved, no pushes/subagents; WSL_ROUND_OK completed.

## Previous continuation (2026-10-30, Codex R169 automatic continuation)

- **13,983 / 14,347 functions; 90.33% code; 364 remaining.** Full retail
  SHA-256 unchanged; all **135 tests** pass. Three C routines (40 bytes) matched.
- Revived c49ty's held draft at 00364780: two independent 16-byte virtual
  tailcall wrappers at 00364780/00364790, followed by an 8-byte return-zero
  routine at 003647A0. They were incorrectly grouped as one 40-byte assembly
  function. Added explicit starts/sizes. Total function count therefore rises
  by two, matched count rises by three, remaining count drops by one.
- Strict current WSL check reports all three MATCH, with no undefined symbols
  or new data. The full retail hash remains
  9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6.
- New C was folded into **SFOGame/Source/GuiAgentInfo_10.c**, following the
  established GuiAgentInfo.cc range 003604D0..00367ADC. The adjacent span
  003643A0..003647B0 consolidated from three units into one (19 source blocks).
  Both pre- and post-consolidation full retail builds pass. Section has other asm.
  Dossiers have no direct prototype mapping for these bodies; no original
  names/types are claimed. Existing header helpers were not moved.
- R168 also saved NetCalloutMsg consolidation as local commit d84bfc45.
  Private evidence: build/agents/r168 and r169/NOTES.md. No pushes/subagents;
  root scratch candidates preserved. WSL_ROUND_OK completed before saving.

## Previous continuation (2026-10-30, Codex R168 automatic continuation)

- Consolidated **NetCalloutMsg** from three parts into one original source file
  (five source blocks). Message handle is int and registered by address. Its
  payload-copy helper's declaration incorrectly returned void; it now agrees
  with the definition's pointer return, using opaque parameters and local typed
  payload views. Whole-unit comparison and full retail hash pass.
- **13,980 / 14,345 functions; 90.33% code; 365 remaining.** No new function
  claimed this consolidation round. All 135 tests pass; WSL_ROUND_OK confirms final synchronization.
- Ready historical candidate: c49ty/work/ready_00364780.c has three independent
  bodies at 00364780/00364790/003647A0 (16/16/8 bytes), currently lumped as one
  40-byte assembly function. Strict compare with explicit starts/ends gives
  three MATCH and no undefined symbols. Two virtual tailcalls followed by a
  return-zero routine; no direct pointer words found in retail. Prototype
  dossier has no mapping, so do not assign original .cc ownership speculatively.
  Next: correct boundaries, integrate, verify full retail and report counts.
- Private evidence: build/agents/r168/NOTES.md and captured merged candidates;
  prototype dossiers use the private SFOS_PROTO_DIR. Root scratch preserved.

## Previous continuation (2026-10-30, Codex R167 automatic continuation)

- Consolidated **DamageMsg** from two parts into one original source file
  (eight source blocks). Callback registration now declares its actual int
  return and four parameters; the callback uses an opaque packet parameter
  and a local view of its existing payload type. Whole-unit comparison and
  retail SHA-256 verification pass. All **135 tests** pass; final synchronization
  completed with WSL_ROUND_OK.
- **13,980 / 14,345 functions; 90.33% code; 365 remaining.** No new function
  claimed in this consolidation round.
- New KM_GetSoftwareID experiment tested c218nm's unsplit-address hypothesis:
  -mno-split-addresses produces the desired v0 address register, but leaves
  lw before jr and adds nop (16 bytes versus retail 12). Same on GCC 991111,
  991111a, 2.96 and 990721. Assembler -O2 and ISA options do not fix the slot.
  No compiler profile or candidate integrated. Do not repeat without new evidence.
- Review-only: BeamMsg, NetAimWeapon and DisableMsg have nonadjacent data;
  NetCalloutMsg has conflicting handle declarations and a later merged-copy
  helper error; NetLabelMsg has callback conflicts and a final compiler/size split.
- Private evidence and scratch experiments: build/agents/r167/NOTES.md, id.c;
  compiler output objects remain private in WSL build/agents/r167.
- Root scratch candidates untouched; no pushes or subagents. Automation active.

## Previous continuation (2026-10-30, Codex R166 automatic continuation)

- **13,980 / 14,345 functions; 90.33% code; 365 remaining.** Full retail
  SHA-256 unchanged; all **135 tests** pass. No new function claimed this round.
- Consolidated **NetPlayer** from three parts into one original source file,
  covering nine source blocks. Both whole-unit comparison and the full retail
  rebuild pass; verified WSL round completed including report and synchronization.
- The constructor-bearing V4 reconstruction in the aiming code clashed with the
  earlier plain vector view. It is now named NetPlayerAimVec4; existing layouts
  and code are preserved. Matrix helper structs have tags so forward declarations
  can agree with the definitions. Vtable declarations now have the actual Team,
  HandleMessage, NextFrame and func_002D7E50 signatures.
- SFOLobby_Lobby remains blocked: explicit GetSlot casts and a compatible SetError
  definition resolve compile errors, but combining the units changes code in the
  first large function at 0x0044FD13. All those trials were reverted. Inspect
  cross-function effects / merged output before retrying; no call args changed.
- Private evidence: build/agents/r166/NOTES.md. R165 data-relocation/report targets
  remain available below. Root scratch files untouched; no push or subagents.

## Previous continuation (2026-10-30, Codex R165 automatic continuation)

- **13,980 / 14,345 functions; 90.33% code; 365 remaining.** Full retail
  SHA-256 unchanged; all **135 tests** pass. No new function claimed this round.
- Consolidated **SFOLobby_Games** from two parts into its single original source
  file (11 source blocks). Corrected the conflicting Libc_Strcpy declaration to
  return char* with a const char* source, matching later uses of its return value.
  Both whole-unit comparison and the full retail rebuild pass.
- Reviewed the three remaining data-report discrepancies using actual WSL object
  diffs. libc_124D30 and 989snd_4 comparison targets contain numeric pointer words
  where compiled C correctly has relocations to existing extra.ld aliases
  D_0048943C and D_00542940. medius_30AB20's .rodata is 96.21% equal: its string
  pointer array relocates against individual labels in the target, but against
  the .rodata section plus offsets in C. Its jump table already matches; the
  leading colon-string symbol also has different padding extent (8 versus 2).
  No data/tooling changes made. Canonicalization needs explicit linked-byte and
  relocation validation; do not suppress differences or claim C translation gains.
- Private evidence: build/agents/r165/NOTES.md and libc.json, medius.json, snd.json.
  Next consolidation candidate: SFOLobby_Lobby, whose GetSlot return adapters
  conflict when merged. Its existing one-argument calls rely on current codegen;
  inspect retail call semantics before changing argument declarations.
- Changes saved locally; no push. Root scratch files untouched; automation active.

## Previous continuation (2026-10-30, Codex R164 automatic continuation)

- **13,980 / 14,345 functions; 90.33% code; 365 remaining.** Full retail
  SHA-256 unchanged. All **135 tests** pass (Windows and WSL).
- Resolved R163's extra C-owned non-match: **voBufCreate / mp_vobuf now reports
  100%**, all eight functions exact. This corrects comparison metadata for an
  already byte-identical C implementation; no new algorithm was translated.
- Splat misidentified four unrolled VoTag array-stride multiples (4..7 times
  0x4CE40) as absolute symbol addresses, including cNextFrameMsg_dtor. Actual
  instructions add these constants to the runtime buffer base. The compiler
  emitted literals, while the target assembly emitted spurious HI16/LO16 relocations.
- `config/asm_literal_offsets.json` records only the four reviewed pairs in
  mp_vobuf. `tools/assemble.py` validates their original instruction words,
  signed HI/LO values, opcode/register pattern and dynamic-base addition, then
  restores literal operands. Other references stay intact. Ninja depends on
  the configuration and normalizer so edits trigger reassembly.
- Verification included native assemble/link byte-equivalence tests and an
  independent retail comparison of every normalized mp_vobuf target function
  (8 MATCH, no undefined symbols), in addition to the full retail build check.
  Details: `build/agents/r164/NOTES.md`, vobuf_diff.json and verify_target.py.
- **Remaining data comparison discrepancies:** C-owned `lib/libc/libc_124D30`
  (4 bytes), `lib/medius/medius_30AB20` (264 bytes), `Libs/989snd/ee/989snd_4`
  (4 bytes). Inspect their actual object differences before making changes;
  no blanket suppression of relocation differences is appropriate.
- Source ownership is unchanged; remaining function count now agrees with the
  fresh 365-unowned-function inventory from R163. Verified WSL rebuild-only round;
  changes saved locally, no push. Root scratch candidates untouched; automation active.

## Previous continuation (2026-10-30, Codex R163 automatic continuation)

- **13,979 / 14,345 functions; 90.33% code; 366 reported non-matches.** No new
  function is claimed in this consolidation round. Full retail hash exact;
  all 130 tests pass.
- Consolidated **NetGeneratorDelete**, **NetScoreMsg**, and **SFOLobby_Contact**
  into their single original `.c` files (7 parts -> 3 files; 17 source blocks).
  Unified network callback argument/return declarations and message-handle types;
  retained typed packet views inside callbacks. Corrected conflicting reconstructed
  memset/GuiCallback/Poll prototypes in the contact unit. Merged bytes verified.
- **Important inventory finding:** current `rank_candidates` inventory is complete
  with no warnings and offers **365 unowned assembly functions**, not 366. The extra
  reported non-match is **voBufCreate (0x003F6040)** in already C-owned `mp_vobuf`:
  fuzzy 99.5%, size 320 bytes. The full executable is byte-identical, so inspect
  object relocation/symbol comparison before treating it as another C target.
  Both prototypes map to it hash-exactly. A fresh dossier is available locally.
- Fresh inventory: `build/agents/r163/inventory.json`; dossiers for 0x003F6040 and
  FftSumCosOlAdd (0x0031FC28) in that round's dossier directory, with SFOS_PROTO_DIR set.
  FFT prototype is hash-exact but records no locals. Im-base register-pin/wrapper
  experiments did not improve the baseline 8 differences; do not repeat them blindly.
- Old held entry **0x286570/0x286590 is already integrated** as cTurret_Stop and
  cTurret_NextFrame in `SFOGame/Source/tank_15.c`; both check as MATCH. Other old held
  drafts at 0x306C60, 0x3D1B60 and 0x1519A0 already have C definitions as well.
  Always check current source ownership before retrying historical held notes.
- Details and failed experiments: `build/agents/r163/NOTES.md`, merge_review.log.
  Verified WSL rebuild-only round; local commit, no push. Root scratch files untouched.
  Automatic continuation stays active; do not start overlapping writers/builds.

## Previous continuation (2026-10-30, Codex R162 automatic continuation)

- **13,979 / 14,345 functions; 90.33% code; 366 unmatched.** Full build is
  byte-identical to retail; all 130 tests pass.
- Matched **_sceMcFatInit** (0x002B69A0, 92 bytes, gcc296g0), previously held
  because its root-directory literal overlapped _make_path's C-owned rodata.
  `memcpy(cwd, D_004AC1C8, 2)` retains the exact two-byte copy emitted for
  `strcpy(cwd, "/")` while reusing the existing shared literal, including NUL.
  It emits no new data; the existing linker already provides D_004AC1C8.
  No data split or change to _make_path was needed. Do not retry this held item.
- Consolidated **six original source sections**, each from two parts into one:
  `SFOGame/Source/Env`, `GameSky`, `NetPathMsg`, `NetWeaponMsg`, and
  `Libs/SFOLib/Source/NetSetGobjMsg`, `NetTerrainActivation`.
  All 23 source blocks passed the merged-code check before the full build.
- Env's swap definition now agrees with the vector helper's declared pointer
  type, using local PtrVec views for its existing body. Network registration
  and packing use consistent int message handles and registration addresses.
  NetPathMsg/NetWeaponMsg callback declarations now match their definitions;
  NetPathMsg's opaque packet parameter is viewed through its existing payload
  type internally. No payload layouts or generated instruction bytes changed.
- Review-only blockers: RestoreBody, USBKeybd and NetQuickChatMsg have separated
  data blocks; mwUtils_PS2 and DeactivateMsg change code when combined. Details
  and reviewed modules are in `build/agents/r162/NOTES.md` and merge_review.log.
- Four MW compiler variants for KM_GetSoftwareID stayed at the same two
  register-allocation differences. No candidate for that function was integrated.
- Verified batch `r162` through the WSL workflow. Changes saved locally; no push.
  Existing root scratch candidates untouched. Automatic continuation stays active;
  coalesce wakeups arriving while a round is active instead of starting a second writer.

## Previous continuation (2026-10-30, Codex R161 automatic continuation)

- **13,978 / 14,345 functions; 90.32% code; 367 unmatched.** This was a
  source-consolidation round; no additional function is claimed as matched.
  Full build remains byte-identical to retail; all 130 tests pass.
- Consolidated **Libs/SFOLib/Source/SFOini.c** from two parts into one, covering
  all seven source blocks. Shared the existing 12-byte MSL string representation
  in `include/sfoini_string.h`, used it for operator[] and both find helpers, and
  made the find(string) forward declaration agree with the const-qualified definition.
  This removes the old incompatible flat-struct/union declarations that blocked merging.
- `NetIRequestCreateRemoteNamedObject` (0x002E2250) is still one differing branch
  instruction away. New branch-probability / unsigned guard forms did not help.
  The cleaned candidate is `build/agents/r161/callee1.c`: R0-style baseline with
  a discarded label anchor, current callee names, and a correct `Libc_Strcpy` call
  decoded from the retail jal. `check_match` reports only DIFF at 0x5c, with no
  undefined symbols or data diagnostics. **Not integrated.**
- Preserve these failed experiments in the local notes: `__builtin_expect` variants
  enlarged the function; unsigned zero/one guards stayed at one difference except
  the subtract/compare form, which was worse. Details in `build/agents/r161/NOTES.md`.
- Used the established WSL rebuild-only round after merge_units verified the complete
  SFOini section. Changes saved locally; no push. The automatic continuation remains
  active. Existing root scratch candidates untouched.

## Previous continuation (2026-10-30, Codex R160)

- **13,978 / 14,345 functions; 90.32% code; 367 unmatched.** Full build remains
  byte-identical to retail. All 130 tests pass.
- Matched `KM_GetSoftwareKeyPair` (0x004769A4, 280 bytes), previously held by the
  checker. `check_match` now caches the explicit sizes in splat's `nonmatching`
  annotations and accepts an exactly sized function body even when the next
  function lies beyond padding/data. All instruction and relocation checks remain.
  Tests reject incorrect sizes, overlapping function boundaries and changed bytes.
- Integration split the padding at 0x00476ABC into a false one-instruction function.
  Reclassified the zero-fill region through 0x00476B00 as data and rebuilt; the
  total is back to **14,345 real functions**. Do not count that padding as a target.
- Consolidated **SFOGame/Source/NetHuman.c** from two parts into one, covering all
  ten source blocks. Unified callback declarations and the D_005723C8 byte flag.
  The shared replicated-record and field-parameter layouts now live in
  `include/net_human_fields.h`; the cAimWeapon/cTargetInfo field-registration
  functions use the same record types as their caller. Merged bytes verified.
- **Source-layout clarification requested by the owner:** `src/main/GameGOBJ/`
  is not duplicate GameGOBJ game code. Those trailing helpers have only header
  CU attribution (GameGOBJ.hh / standard-library vector), or no debug attribution.
  Direct inspection of both prototype ELFs found no STT_FILE object-boundary
  symbols. No confirmed original `.cc` owner was recovered; no speculative move
  was made. README now explains this exception. Keep merging confidently assigned
  code into the original layout, but do not promise every header helper can be
  assigned to one original `.cc` from the surviving evidence.
- `KM_GetSoftwareID` (0x00476998) remains assembly. Simple C is two register-allocation
  differences away (address in v1 instead of retail v0); compiler/profile, return-type
  and local pointer-pin attempts in `build/agents/r160/` did not match.
- Details: `build/agents/r160/NOTES.md`. Verified matching batch `r160`, followed by
  a rebuild-only round for the padding correction. Changes saved locally; no push.
  Existing root scratch candidates untouched.

## Previous continuation (2026-10-30, Codex R159)

- **13,977 / 14,345 functions; 90.31% code, 99.92% data; 368 unmatched.**
  The full build still reproduces retail byte for byte. All 129 tests pass.
- Matched `rt_msg_client_process_connect_result` (0x002FF868, 736 bytes). Its held
  R156 draft was code-exact but owned unused `.sdata`. The address-taken label anchor
  now lives in `.dtors_drop`, which the linker discards. The match checker explicitly
  ignores this exact discarded section; regression coverage still rejects unknown
  custom data sections. No linked retail data was omitted.
- **Owner instruction:** preserve original source layout recovered from the prototypes;
  merge completed source sections into a single `.c` when byte-identical compilation
  permits it. Continue folding new per-function files into their original part files.
- Consolidated `Libs/SFOLib/Source/viewport` from two parts into **one `viewport.c`**.
  `XLib_GetFullscreenWindow` now returns `float*`, agreeing with its caller; address
  arithmetic and generated code are unchanged.
- Folded `SFOGame/Source/gameGobjController` from seven parts into five, including the
  R157 match at 0x0022F5B0, and `SFOGame/Source/GuiObjectives` from six into four,
  including 0x00367B20. Both sections are fully matched but cannot yet become single
  files: remaining blockers include conflicting declarations and nonadjacent data
  subsegments. `build/agents/r159/merge_review.log` lists the observed blockers.
- Both private prototype executables are present under
  `D:\Claude\Syphon Filter Omega Strain\local\prototypes`. Always set
  `SFOS_PROTO_DIR` before generating dossiers. January 2004 SCUS_973.97 is preferred;
  October 2003 SCUS_972.64 is the other reference. Never commit the binaries or dumps.
- Regenerated dossiers for 0x003CD260, 0x00219820, 0x00166840 with prototype disassembly.
  Constructor 0x00219820 remains at 12 differences after accessor/copy/helper/constraint
  experiments. rFft_vu4 remains at two real instruction differences after source-order,
  address-expression and barrier experiments. **Its correct address is 0x00322FC0**;
  the old near-miss table listed a different address. No near-miss drafts were integrated.
- Local experiment details: `build/agents/r159/NOTES.md`. Batch `build/pending/r159`
  was verified through `wsl_round.sh`, then a rebuild-only round verified the extra
  source consolidations. Changes saved locally; no push. Root scratch candidates untouched.

## Previous continuation (2026-10-30, Codex R158)

- Continued from the Copilot R157 handoff below. The active Windows checkout is
  `D:\Claude\syphon-filter-omega-strain-decomp`; the older `sfos-decomp-helper` path is absent.
- Integrated three previously held matches: `operator_delete` (0x00100740), the MW
  exception-specification handler (0x00101250), and `_printf` (0x0010ED58), including its
  292-byte jump table. This replaces 2,132 bytes of assembly with C.
- Added `__unexpected` and `__end__catch` linker aliases. `check_match.symbols()` now reads
  absolute definitions in `config/extra.ld` and invalidates its cache when that file changes,
  so compiler-generated calls are checked against their actual retail targets.
- Added the `gcc29a` compiler kind to check_match and integrate_pending, selecting the
  installed `ee-gcc2.9-991111a` compiler and its original assembler with `-O2 -G0`.
  Its assembler reproduces `_printf`'s floating-point hazard padding.
- Final full WSL build remains byte-identical to retail (SHA-256
  `9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6`).
  **13,976 / 14,345 functions; 90.29% code, 99.92% data; 369 functions remain.**
- Validation: all three candidates MATCH (including `_printf` data); 128 tests pass.
  New regression coverage checks linker-alias cache invalidation and gcc29a selection/flags.
- Used `tools/workflow/wsl_round.sh` directly for two verified batches, `r158` and
  `r158_printf`, with a WSL keepalive. Changes are saved locally; no push was performed.
- The first two rows of the older held-items table below are resolved. Other held items
  and near misses remain available. Existing root-level untracked scratch candidates were
  left untouched. No lane agents were launched in this continuation.

## Previous handoff (2026-10-30, Copilot session)

The Copilot session that ran R150-R157 has stopped. Every lane agent finished; nothing is pending.

### State

**13,973 / 14,345 functions (90.24% code, 99.92% data).** The build is still byte-identical.

| Round | Commit | Matches |
|---|---|---|
| R153 + R154 | `a8234987`, `628c7fcc` | 25 |
| R155 | `b2551e5a` | 8 |
| R156 | `2a3ff850` | 52 |
| R157 | `258b47d4` | 5 |

### What is left (372)

- **About 150 stay as asm by policy.** These are 16-24-byte kernel syscall stubs and other
  hand-written SDK asm; see "Open decisions" below. Hand-written routines include: the bignum
  routines IsSmaller, lint*, MODIP, MULT and XMOD; DotProd; ScrambleSeed; SHAtoByte; md5Encode.
- **Everything else has been tried by at least one lane, most of them five or more times.** The
  closest state of each function is in `build/agents/<lane>/NOTES.md`. That folder is local and
  gitignored; the best ones are copied into the near-miss table below.

### Running a round

The scripts live in `tools/workflow/`.

1. **One-time WSL setup.** Run `wsl -d sfos3 -u root -e bash /mnt/d/Claude/syphon-filter-omega-strain-decomp/tools/workflow/setup_wsl.sh /mnt/d/Claude/syphon-filter-omega-strain-decomp`.
   Read the script header first. It creates `~/sfos-decomp` and a venv, and copies every
   `.tools/eegcc` compiler from the Windows checkout. Without those compilers the report silently
   loses about 470 functions.
2. **Keepalive.** While working, keep a background
   `wsl -d sfos3 -u root -e bash -c "while true; do sleep 3600; done"` running. If the distro
   idles out or restarts, a round in progress dies; that happened once in R155.
3. **Collect the matched files** into `build\pending\rNNN\`.
   **Wildcard gotcha:** `Get-ChildItem build\pending\l? -Filter *.c` returns nothing. Loop over
   the lane names explicitly instead:

   ```powershell
   foreach($l in 'l1','l2'){ Get-ChildItem "build\pending\$l" -Filter *.c }
   ```

4. **Verify.** Run `tools\workflow\verify_pending.ps1 -Lanes rNNN`. Every file must say `OK`,
   meaning every line is MATCH and there is no UNDEF except `__dl__FPv`.
5. **Run the round.** `tools\workflow\round_wsl.ps1 rNNN "Match N more functions incl. ... (RNNN)<newline><newline>Co-authored-by: ..."`.
   - This integrates the batch and builds it in WSL (about 4 minutes), mirrors the results back,
     then commits and pushes on Windows.
   - If it fails, the batch is left in `build\pending\rNNN_batchHHMMSS` and Windows `src` is
     untouched. Fix the problem, move the files back and rerun.
   - Files that `integrate_pending` skips are moved back to `build\pending\rNNN`.
   - The `.sh` files must keep LF line endings. If they come out as CRLF, bash fails with
     `set: pipefail: invalid option`.

### Running lanes (parallel matching agents)

1. **Build the candidate list.** Take the unmatched functions from `progress/report.json` or the
   asm left in `asm/`. Drop the syscall stubs.
2. **Generate a dossier per function:**

   ```powershell
   $env:SFOS_PROTO_DIR='D:\Claude\Syphon Filter Omega Strain\local\prototypes'
   .venv\Scripts\python.exe tools\proto\dossier.py build\agents\<lane>\dossier <ADDR>
   ```

   Without `SFOS_PROTO_DIR`, the dossier silently leaves out the symbolised prototype disassembly,
   which is its most useful part. Most R156/R157 lane dossiers were missing it, so regenerating
   them may unblock some near misses.
3. **Fill in `tools/workflow/lane_prompt_template.md`.** Replace `<LANE>`, the focus line, the
   candidates and the deadline. Launch up to 8 agents with one prompt each.
4. **Re-verify every delivered file yourself.**
   - Lanes invent callee names, for example `Event_Send`. check_match then prints MATCH next to
     `UNDEF X: called as a function`.
   - Fix invented names with `tools\rename_drafts.py <dir>` (handles stale `func_` names), or map
     them by hand. Decode the jal target as `(word & 0x3FFFFFF) << 2` in
     `build\agents\asm\<ADDR>.s`, then look the address up in `config\symbol_addrs.txt`.

### Held items (matched or nearly matched, blocked by tooling or config)

| Item | Problem | Fix needed |
|---|---|---|
| `build\agents\l1\held\gcc29a_0010ED58.c` (`_printf`) | Matches only with the ee-gcc 2.9-991111a assembler (reproduces retail's float-compare nops) | Add the compiler kind to `check_match` and to the OVR map in `integrate_pending` |
| `build\agents\l1\held\mw38_00100740.c`, `mw38_00101250.c` | Reference `__unexpected` and `__end__catch` | Add `__unexpected = 0x00101250;` and `__end__catch = 0x00100D20;` to `config/extra.ld` |
| KM_GetSoftwareKeyPair | Resolved in R160: explicit function extent and separate zero-fill data | Integrated and full-build verified |
| viBufGetTs | Needs a config split | |
| sceSifInitRpc | Really starts at 0x10FBC0; the current split is wrong | Correct the split |
| gcc296_002FF868 | Its .sdata is not referenced from code, so `integrate_pending` skips it | Draft in `build\integrated\lanes_r156\l2\` |
| longReverse | Held by policy | |
| l4 dmaman 375A30, 375AC0, 375C30 | Match, but the tag helper is inline asm | Awaiting review in `build\agents\l4\asm_review\` |
| Fft, InverseFft, InverseUnpack (R157) | Integrated, but they use file-scope global register variables | Keep them in their own file; `build\agents\l3\work\comb3.c` has all three together |

### Near misses (closest first; differing lines; draft paths under `build\agents\`)

| Addr | Function | Diff | Draft | What differs |
|---|---|---|---|---|
| 002E2250 | NetIRequestCreateRemoteNamedObject | 1 | `l2\work\e2250\L3.c` | branch target 0x200 vs 0x204 |
| 00322FC0 | rFft_vu4 | 2 | `l3\work\fc0_b.c` | |
| 00370CC0 | XLib_DrawDma | 4 | `l4\work\best_370CC0_4.c` | `li fp,12` hoist order |
| 003CD260 | cGOBJ_GetCenterOfMass | 4 | `l8\work\cm0.c` | two stack slots swapped |
| 00166840 | loadingThread | 5 | `l8\work\lt3.c` | a1/a2 for `show` |
| 0038D720 | gunList_GunCalcBBox | 7 | `l4\work\best_0038D720_7.c` | lq/addiu scheduling |
| 0037B5C0 | XLib_DisplayLastFrame | 7 | `l4\work\lf_0.c` | t0/t1 swap |
| 000D0780 | (l5 human IK) | 8 | `l5\work\h_best8.c` | one copy's scheduling |
| 0037D9A0 | XLib_UpdateCompMat | 8 | `l4\work\best_37D9A0_8.c` | copy-ctor register choice |
| 002DF290 | NetIInitialize | 8 | `l2\work\df290_a0.c` | |
| | FftSumCosOlAdd | 8 | `l3\work\fs_b.c` | |
| 0036B3B0 | cMemMan_Init | 9 | `l4\work\mi_0.c` | |
| 00385240 | cMan_GetGunBarrelMatrix | 9 | `l4\work\best_385240_9.c` | register allocation |
| 001DD6A0 | cAimComponent_NextFrame | 11 | `l8\work\d6a.c` | 3 extra sign-extension pairs |
| 00219820 | cPathedGOBJ_ctor | 12 | `l7\work\pg_b.cpp` | prototype disassembly not used yet |
| 003BB360 | cTexture_UploadBoth | 13 | `l4\work\ub_m1.c` | |
| | nemAgcMeanEngLevel | 14 | | |
| 000BD450 | (l6 particles) | 16 | `l6\work\BD450_p16.c` | temp slots swapped |
| | UpdatePlayers | 16 | | |
| 00394AD0 | cVUM_GOBJ_Render | 17 | `l4\work\best_394AD0_17.c` | |
| 00180580 | cSplinedMotion_QuaternionLERP_1_UpdateVelocity | 17 | `l7\work\sq_a.c` | v1/a3 colours |
| 00131540 | cGameSystem_PushWeaponCam | 17 | `l7\work\w_a.c` | |
| 0025F930 | cVisionFxMan_DeactivateFx | 18 | `l8\work\vf0.c` | one cvt and three mfc1 |
| | strcmp | 18 | | blocked: `pnor` in a delay slot |
| 000D1140 | (l5) | 20 | `l5\work\k_best20.c` | |
| 00405660 | Monster_ctor | 21 | `l7\work\mo_n.c` | |
| 00102B40 | sceGsSetDefDispEnv | 24 | | |
| 000ED120 | (l5) | 24 | `l5\work\e11.c` | register choice only |
| 00153870 | cNPC_Follow_cMessageR | 26 | `l8\work\fo3.c` | a0 use in two blocks |
| | sceCdInit | 31 | | |
| 000BBDC0 | cSKYBOX_GOBJ_Load | 32 | `l6\work\BBDC0_p32.c` | |

### New techniques (R154-R157 lane reports)

**General**
- Hill-climb statement and declaration order against check_match's diff score.
- Copy inline helpers that already match elsewhere verbatim.
- Name the lerp denominator in a local.
- Declaring a local at its point of use changes FPR priority.

**Metrowerks (mw38)**
- Use `=&r` early-clobber temporaries for `qmfc2`.
- **Expression temporaries.** If the prototype has no local for a message or vector argument,
  write an expression temporary. Construct it via the real ctor declared extern returning the
  struct by value; the hidden return pointer in a0 is the ctor's `this`.
  - Give that struct the weak dtor kept in `.dtors_drop` (see `alloc_guard.h`).
  - Temporaries created later get lower stack addresses, so put the temporary inside the call's
    argument list.
- **Default-argument result wrappers** (`F(a, k, V r = V())`) move a result into the caller's
  temporary area.
- **Inline nesting-depth wrappers** reorder the stack slots of inline-function locals.
- **A dead `void* xx = &v;`** keeps a dead `addiu`.
- **Constructors:** call `X::operator new` and then the ctor symbol explicitly, instead of
  `new X(n)`, which leaves an UNDEF for the mangled ctor.
- **Float-to-double:** call `SoftFloat_FloatToDouble` explicitly to avoid the implicit UNDEF.
- An empty `asm volatile("" ::: "memory")` has no effect on code that touches only registers.

**gcc29**
- goto loops avoid strength reduction.
- For a switch: explicit hole case ranges plus `default: goto oor`.
- Loading a value before a branch lets it fill the delay slot.

**gcc296**
- Use file-scope global register variables for values that are only stored; block-local pins get
  deleted as dead.
- Write the instruction that should issue second first.
- Integer pins in loops disable strength reduction.

**Tools in `build\agents\`**
- `l5\work\seqdiff.py`: instruction-sequence diff that ignores registers and offsets.
- `spmap.py` / `spsort.py`: where each stack temporary lands compared with retail.
- `#pragma schedule off` shows the code order before scheduling.
- `l2\work` has the GCC 2.95.3 haifa/reorg scheduler sources and a tracing approach.

## Resume here (2026-10-29, Copilot session)

- **R153 (`a8234987`), R154 (`628c7fcc`), R155 (`b2551e5a`) added 33 more matches.** Now
  13,916 / 14,345, 88.75% code. Rounds run with a WSL round script: integrate + build + report
  in `sfos3` (~4 min), then commit/push on Windows.
- **Check for invented callee names.** check_match can print MATCH next to `UNDEF X: called as a
  function`; that file is not acceptable (only `__dl__FPv` may be undefined). Lane drafts sometimes
  name callees themselves (`Event_Send`); replace them with the `symbol_addrs.txt` name of the jal
  target, decoded as `(word & 0x3FFFFFF) << 2` from the little-endian word in
  `build/agents/asm/<ADDR>.s`. R154's first build failed to link on exactly this.
- **What is left (428):** ~150 are 16–24-byte kernel syscall stubs and other hand-written SDK asm
  (stay as asm, see "Open decisions"); the rest have all been attempted at least once, many 5+
  times. Their closest states are in `build/agents/*/NOTES.md`.
- **R152 (`067bb3b4`) added 52 matches** from dossier lanes (incl. cBox_Transform, the cHuman
  ctor, `cHumanCollisionRoutine_HandleAnyLethalCollisions`, memcpy). Now 13,883 / 14,345, 88.09% code.
- **Build in WSL, not Windows.** On this machine every Windows process start costs 1–10 s
  (endpoint security), so Windows ninja ran ~17–28 steps/min (a full rebuild took 6–10 h).
  The same build in WSL takes ~2 min. Setup (distro `sfos3`, root): `apt install python3-venv
  rsync`; copy the repo (minus build/.venv/.tools/asm/.git) to `~/sfos-decomp`; make a venv,
  `pip install -r requirements.txt`, `python tools/setup_tools.py`; then **copy every
  `.tools/eegcc/*` compiler from the Windows checkout** (setup_tools only fetches 2.95.3-136
  and 2.96; without the others the lib units fall back to asm and the report drops ~470 functions
  while the SHA still matches). `~/sfos-env.sh` sets `CW38_DIR`/`CW50_DIR`/`CW304_DIR` to the
  `/mnt/d/...` compiler folders. A round = mirror src/config/include/tests/tools in, run the
  round.sh steps, mirror src/config/include + `progress/report.json` back, commit on Windows.
- **Windows ninja has no header deps:** after a header rename, stale objects can still link
  against old names. Delete `<x>.o`, `.link.o`, `.raw.o`, `.o.ld` for each object named in the
  link error (the WSL round touches all C files when the include/ hash changes).
- **WSL distros wedge** when idled out (`Wsl/Service/CreateInstance/0xd0000035`); keep one alive
  with `wsl -d sfos3 -u root -e sleep infinity`.

## Resume here (2026-10-28 night, Copilot session)

- **R150 (`71adec89`) and R151 (`3cd37d22`) added 44 matches** with prototype "dossiers" (below);
  `25ab2b41` folded them into their original files. Now 13,831 / 14,345, 86.13% code.
- **Dossier workflow:** `tools/proto/rank_proto.py` ranks every unmatched function by
  normalised similarity between retail and its prototype twin (`proto_rank.tsv`; 339 are ≥0.95).
  `tools/proto/dossier.py <outdir> <addr...>` (run from the repo root) writes one text file
  per function: the `map.tsv` row, prototype params/locals in declaration order, the class and
  struct layouts, the prototype's own disassembly with symbols, and a retail-vs-prototype diff.
  Lanes given a dossier matched 44 of ~120 game functions in one 2.5-hour pass.
- **Near misses with drafts** (score = differing instructions): 001A7080 (1), 003A5C50 (3),
  00188D80 (4), 003A5F20 (5), 0022D3C0 (6, mw50), 0037B5C0 / 003AF400 / 001E8760 (7),
  001DD6A0 (8), 00287540 (10), 00385240 / 0038FEA0 / 003BD0A0 / 00224330 (11), 00224180 (12),
  0028CB20 (13), 00389FA0 / 001D29F0 / 00278460 (16), 003F9E60 (17), 00219820 / 00131540 (19),
  004073C0 (23). Drafts are in each lane's `build/agents/<lane>/work/`; see its `NOTES.md`.
- **Blocked:** see "Known blocked work" for the dead-`div` DMA wait loops in `man.cc`.

## Resume here (2026-10-26 evening)

This is the state as the last Claude session stopped (usage limit).

**On `main`:** everything listed in Status. The build reproduces retail byte for byte.

- **Original names applied:** 11,790 functions, about 82%, use their real names from the two
  prototype builds (`c4e49eb`, `3a4a2d3c`). See "Prototype builds with debug symbols" below.
- **Prototype tools committed:** `tools/proto/` (DWARF v1 parser, Metrowerks demangler,
  prototype→retail matcher). Its README explains how to regenerate the private outputs in
  `build/agents/P1/`: `map.tsv`, `layout.txt`, `types.txt`, `locals.tsv`, `names_*.txt`. This
  needs the two prototype ELFs from the owner; never commit them or the outputs.
- **Original source layout: done** (`bb957776` .. `6a19a268`; see "Source layout" below).
  `src/` mirrors the original tree (`src/SFOGame/Source/`, `src/Libs/SFOLib/Source/`,
  `src/Libs/SFOLobby/SFOLobby/`, `src/Libs/989snd/ee/`, `src/CW_PS2Support/`): 269 original
  files in 2,525 part files, 30 of them already a single file. SDK code stays in `src/lib/`.

**Not on `main` (work in progress in the last cloud workspace only):**

1. **Staged matches.** These were verified by `check_match` but not yet integrated. They lived in
   the last workspace's gitignored `build/pending/r113/`, so redo them if that workspace is gone:
   - cScene_UpdateActivation 0x13DB30
   - cPlayerCamera_GetAngleToTarget 0x280070
   - cNPC_RecommendAIMode 0x1570B0
   - GameIni_GetString 0x3CBA90 (built from the prototype's locals)

**Next steps, in order:**

1. Keep matching. Remaining work by size: 48 functions over 3 KB (258 KB) and 93 of
   1.2–3 KB (173 KB). For every target:
   - look it up in `build/agents/P1/map.tsv`;
   - write it with the prototype's locals in declaration order and its real class layout;
   - diff retail against the **prototype's own disassembly** of the same function. Its code is
     often identical apart from a source change (GuiEquipmentPane_Cycle went from 84 to 6 diff
     lines that way).

   The prototypes were built with MW 2.4.1 = our `mw304`, so a draft can be calibrated against the
   prototype first.
2. Closest open near misses (2–6 diff lines, all register allocation):
   - GuiObjectives_SetTab
   - func_00400F20: last function of the AgentPacking unit; stage the whole unit `0x400990`
   - Bone_FinalizeRotation
   - HudTicker_Update
   - Heap_AllocSlot
   - GuiEquipmentPane_Cycle
   - GuiAgentCreate_RandomLook
   - TargetVis_Test (1 line)
   - func_002B9108 (gcc, 2)

   Each lane's `build/agents/M*/FINAL_REPORT.md` in the last workspace had the drafts; they are
   gitignored, so treat these as known-close targets.
3. Owner review is still open for 976 medium-confidence prototype names
   (`build/agents/P1/names_review.txt`). 325 high-confidence names were held back on purpose:
   - C library and runtime names (`memcpy`, `__throw`; renaming can change codegen);
   - GCC built-ins;
   - names that collide with other identifiers;
   - self-referencing aliases.

**Naming-round pitfalls hit today (avoid them):**

- A libgcc alias line `dptoul = func_X` became `dptoul = dptoul` and hung the old assembler forever.
- Macros paste the function name into type names (`NAME##_V`, `_E`, `_Construct`, ...). Renaming a
  name means renaming those pasted identifiers too, but never a suffixed token that is itself a
  real symbol.
- Two functions can swap names. Apply renames in one pass, never chained.
- `rename_map.tsv` (gitignored) drove the existing-name rename;
  `tools/rename_drafts.py <dir>` renames `func_` tokens in drafts to current names.

**Routine for a round** (see "Integrating a round"): stage verified files in `build/pending/<round>/`,
then run `bash tools/round.sh <round> "<subject>"`. It integrates, applies names, configures,
builds, requires the OK line, then reports, tests, commits and pushes;
its steps are listed under "Integrating a round".


**Folding new matches into original files (2026-10-27):** `merge_units.py --all` currently stops
on an EE-GCC library group ("pooled literal .lit4 ... differ from the retail pool") and changes
nothing. Run it on the original files that received new `func_*.c` units instead:
`python tools/merge_units.py --jobs 2 $(find src/SFOGame src/Libs src/CW_PS2Support -name 'func_*.c' | sed 's|^src/||; s|/func_[0-9A-F]*\.c$||' | sort -u)`
then `bash tools/round.sh - "<subject>"`. R149's 22 matches were folded this way (`d8455590`).

## Status

| | |
|---|---|
| Functions matched | 13,973 of 14,345 |
| Code matched | 90.24% |
| Data matched | 99.92% |
| Full build | reproduces the retail executable byte for byte |

The total rose from 14,331 to 14,344 when R138 split the `0x416830` thunk unit. That split
briefly cost 224 bytes of data credit: the vtables in `func_00416A00.c` and
`guiManager_417AE0.c` still listed the thunks as raw addresses (`(void*)0x416850`), while the
target now has relocations to `func_00416850` etc. Naming them restored 99.92% (`aa3e99f`).
**After adding `// type:func` symbols, grep `src/` for `(void*)0x<addr>` table entries and name them.**

The ten r139 matches staged on the Windows checkout were verified and integrated in R139 (`6fabca5`).


The objdiff report undercounts `func_0038A800`: its full 2,328-byte body and the
linked executable match retail, but target-only relocations on scratchpad
constants (`D_70000040` and `D_70000008`) produce a 99.93% symbolic comparison.
The status above follows the generated report without manually changing totals.

What is left (from `progress/report.json`):

| Function size | Unmatched | Bytes |
|---|---|---|
| under 100 bytes | 180 | 3 KB |
| 100–1,200 bytes | 342 | 212 KB |
| 1,200–3,000 bytes | 107 | 195 KB |
| over 3,000 bytes | 48 | 258 KB |

Almost every remaining function under 1,200 bytes has been attempted at least once,
most of them by several workers. Code percentage is by bytes, so the large functions
are where the percentage moves.
The ones under 100 bytes are mostly hand-written assembly (`plzcw`, quadword copies
through temporaries) that C cannot express. The cheapest remaining gains are:

1. **Near misses.** Drafts that are a few instructions off (register swaps, delay-slot
   choice, stack-slot order). See "Near-miss techniques" below.
2. **Functions of 1,200–3,000 bytes**, which have barely been attempted.
3. **Families of similar functions.** `tools/clone_match.py` turns one matched function
   into matches for every function with the same instruction shape.

## Ground rules

- A match counts only when the full build prints
  `OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6)`.
- Never commit game content: no executable, `asm/`, `build/`, `orig/`, `.tools/`,
  disassembly or extracted data. Never commit the licensed compilers.
- Per-file acceptance with `tools/check_match.py`: every function line MATCH, no UNDEF
  line except `__dl__FPv`, any DATA line MATCH, one function per file, and the file
  covers the full size of its retail unit.
- Inline asm only for instructions C cannot express. A scheduling barrier, weak stub or
  fake `x++; x--;` pair needs a one-line comment saying why it is there.
- Never use CodeWarrior 3.03J. Never force-push or rewrite published history.
- Register pinning (`register T x asm("$n")`) is allowed only as a last resort in EE-GCC
  library code (`src/lib/`), after declaration order, temporaries and types have failed,
  with a one-line comment saying why. Never in Metrowerks game code. It emits no
  instructions but forces register choice, so the original source almost certainly did
  not contain it.
- Keep line endings LF.

## Tools you need

The build needs three licensed CodeWarrior PS2 installs, named by environment variables:
`CW38_DIR` (3.0 build 38), `CW50_DIR` (3.0 build 50) and `CW304_DIR` (3.04 build 22,
its `PS2_Tools/Command_Line_Tools` directory). EE-GCC 2.9-ee-991111, 2.95.3 and 2.96
are also used. Their Linux binaries run natively on Linux and through WSL on Windows.
`tools/setup_tools.py` downloads the freely available tools.

On Linux the CodeWarrior compilers run through wibo. A 4-core GitHub codespace does a
full round build (configure, data generation, configure, ninja, report) in about
6–7 minutes. A local WSL (Ubuntu) tree with `ninja -j8` works as well and takes
about 10–13 minutes. It needs `tools/setup_tools.py` run inside WSL, which creates the
`ee-gcc2.9-991111-as296` hybrid compiler. Without the hybrid, libcdvd/libmpeg units
drop out of the report while the executable still matches.

**EE-GCC 2.96 is nondeterministic across CPUs.** Its 32-bit `cc1` reads uninitialized
memory, so its output depended on which CPU-specific glibc string routines ran and on
the environment size. `tools/compile_aligned.py`, `check_match.py`, `merge_units.py`
and `wsl_gcc.py` set
`GLIBC_TUNABLES=glibc.cpu.hwcaps=-SSSE3,-SSE4_1,-SSE4_2,-AVX,-AVX2,-ERMS,-FSRM,-BMI1,-BMI2,-POPCNT,-LZCNT,-MOVBE`,
which makes it match on both Intel and AMD hosts. Any new script that runs `cc1` must do
the same.

## Matching one function

1. **Pick a candidate.** `python tools/rank_candidates.py --report progress/report.json --json`
   lists unmatched functions with their owner unit and size. Read the function in
   `asm/` (search for its `glabel`; the file name in the ranking can be stale).
2. **Decide the compiler** from the code's shape (see the table in
   MATCHING_TECHNIQUES.md). Game code is usually `mw38`; library code is EE-GCC.
3. **Write the C** in a scratch file named `<kind>_<ADDR>.c`. Copy the style of nearby
   matched units in `src/` for declarations and types. `m2c` gives a first draft.
4. **Check it.** `python tools/check_match.py FILE.c -c mw38,mw50,mw304,mw` (or
   `-c gcc296g0,gcc296,gcc29,gcc` for library code). The output shows each compiler's
   per-function result and an instruction diff. `tools/try_match.py` runs pragma
   experiments (`#pragma opt_propagation off`, `peephole off`, ...) without editing the
   file.
5. **Stage** each accepted file as `<kind>_<ADDR>.c` in a staging directory (by
   convention `build/pending/<round>/`).

## Integrating a round

```
python tools/data_gen.py release --all           # give data back to the units that own it
python tools/integrate_pending.py . build/pending/<round>
python tools/apply_names.py                      # apply config/symbol_addrs.txt names to C
python configure.py --compiler-dir "cwps2-3.0b38=$CW38_DIR" --compiler-dir "cwps2-3.0b50=$CW50_DIR" --compiler-dir "cwps2-3.04=$CW304_DIR"
python tools/data_gen.py
python configure.py ...same flags...
ninja                                           # must print the OK line
ninja report && python tools/publish_report.py
git add src config include progress && git commit && git push
```

`integrate_pending.py` prints `+` for each added unit and the reason for each skipped one.
If the build fails, find the first differing byte (`cmp -l build/SCUS_972.64 orig/SCUS_972.64`),
map it to a unit, move that file out of the round and rebuild. Commit messages follow the
existing ones: what was matched, the OK line, and the new totals.

`tools/merge_units.py --all-complete` merges per-function files of fully matched modules
into translation units. Run it occasionally; see [merge_units.md](merge_units.md).

## Pitfalls already hit

- `tools/data_obj.py` used to pad an odd-sized data block with `objcopy --update-section`,
  which silently dropped the block's relocations (jump tables then scored < 100% in the
  report while the executable still matched). It now pads inside the `ld -r` link script
  (`tests/test_data_obj_pad.py`). If a unit's data section scores below 100% with the build
  matching, check its relocations first.

- Never give a function a C library or compiler-runtime name (`abort`, `sscanf`, `strncat`,
  `toupper`, `__moddi3`, `_calloc_r`, `memcpy`, `sqrtf`, ...) in `config/symbol_addrs.txt`.
  GCC treats such names as builtins: naming 0x00121B60 `abort` made the caller a no-return
  tail jump and shrank the executable by 16 bytes. Use a prefixed name (`Math_Sqrtf`) or
  leave it `func_`.
- After `tools/apply_names.py` renames functions in `include/`, rebuild every C file
  (`find src -name '*.c' -exec touch {} +`); otherwise stale objects keep the old
  `func_` references and the link fails.

- `merge_units: begin/end func_<ADDR>` markers must keep their address labels:
  `merge_units.py` and `clone_match.py` parse them. `apply_names.py` leaves them alone.
- GCC 2.96 accepts string literals that span lines. A trailing space before such a line
  break is part of the string, so never strip trailing whitespace across the tree.
- Ninja does not track header dependencies here. After editing a header, touch every
  `.c` file that includes it, including through another header. A fresh source rebuild
  exposed a duplicate `HumanColPreset` definition hidden by the incremental cache;
  `humanCollision_types.h` now owns that type and the preset setter uses its fields.
  When taking over an existing build cache, rebuild all C sources before trusting it.
- Naming a data symbol in `config/symbol_addrs.txt` makes splat redo its whole split.
- Python and some editors on Windows write CRLF; convert back to LF before committing.
- When several workers match in parallel, give each one a disjoint candidate list,
  generated from the current `progress/report.json` and excluding everything already
  staged. Overlapping lists wasted a full round of work twice.
- The `asm=` path that the candidate ranking prints can be stale after a re-split;
  search `asm/` for the `glabel` instead.
- Readability edits (names, struct types, comments) are free, but changing a type's
  width or signedness, expression shape or declaration order can change code
  generation. Rebuild after each batch.

## Prototype builds with debug symbols (2026-10-26)

The maintainer has two unstripped prototype executables of the game, kept privately (never
commit them or raw dumps of them; using their names, types and source layout in this repo is
approved):

- **SCUS_973.97**, the online beta (January 2004). Closest to retail; prefer it.
- **SCUS_972.64**, an October 2003 build.

Both were built with "MW MIPS C Compiler (2.4.1.01)", the compiler our `mw304` kind already
uses (retail game code mostly matches build 38). Each has a full symbol table with mangled C++
names, relocations, and Metrowerks DWARF v1 debug info: compile units with original source paths
(`C:\SFO\Code\SFOGame\Source\*.cc`, `Libs\SFOLobby\...`), struct/class layouts with member
names, and every function's parameters and locals in declaration order. The game uses PS2 SDK 2.8.

A matcher maps prototype functions to retail: 12,114 of 14,343 retail functions with high
confidence (estimated error about 1%), 976 medium. Its outputs live under the gitignored
`build/agents/P1/` (rerun instructions in its README): `map.tsv`, `layout.txt` (original source
file per splat unit), and per prototype `types.txt`, `locals.tsv`, `globals.tsv`.

- **Applied:** 6,617 high-confidence names for functions that were `func_XXXXXXXX` (`c4e49eb`),
  in the repo's C-identifier form (`Class_Method`, `_ctor`/`_dtor`).
- **Held back** (`build/agents/P1/names_held.txt`): runtime helper names starting with `__`
  (the compilers call them implicitly), GCC built-ins (`copysign`, `isinf`), `dptoul` (a libgcc
  alias line would become `dptoul = dptoul` and hang the old assembler), and names already used
  as other identifiers in `src/` (e.g. `block`, `GetState`). **Screen new names for all of these
  before a naming round.**
- **Awaiting owner review:** 4,606 functions whose existing name differs from the prototype's
  (`renames.tsv`), and 493 medium-confidence mappings (`names_review.txt`).
- **For matching:** look a target up in `map.tsv` and write it with the prototype's locals in
  their declaration order and the real class layout. Code can still differ (the prototypes are
  2–5 months older and use an older compiler). In `locals.tsv`, "register 2" means the value is
  still in its incoming argument register.

## Near-miss techniques (newest)

From the R153–R155 lanes (2026-10-29):

- **mw38 scheduling barrier:** a GCC-style `asm volatile("" ::: "memory")` stops mw38 from sharing
  constants and loads across it, unlike a CW `asm {}` block (loadingThread went from 44 to 6
  differing lines).
- **C++ shape from the prototype:** return structs by value through an inline constructor; use the
  prototype's real template types (`cArray_FixedSize<...>::operator[]`) and reference-returning
  member chains (`a.b().c()`) instead of flattened pointer arithmetic (0x1E8760).
- **`#pragma opt_common_subs off` alone**, plus GCC `lq` / MW `sq` asm for quadword moves, closed
  `cQuatVec_GetUnit`.
- **gcc29 (ee-gcc2.9-991111)** builds the insock code and the MMI string functions (memcpy, memcmp,
  strcpy, strlen). Use if/else chains rather than `switch` (no jump table); a loop label that is not
  8-byte aligned means the original used `goto`.
- **gcc296 voice codec:** pinning registers (`register float x asm("$fN")`) is fine in GCC code.
- **Netcode (gcc296g0):** store through a block-local copy of the pointer; write
  `e = call() ? K : 0;` in each arm; share one `goto fail` exit.

From the R152 lanes (2026-10-29):

- **One-byte enums:** `#pragma enumsalwaysint off` plus an enum with a `0x7F` max, compared
  through an enum-typed local, gives retail's `lbu; bne` with the pointer still live.
- **Pragmas:** `#pragma schedule off` works on mw38 (shows pre-scheduling order);
  `#pragma unsigned_char on` makes `(unsigned char)` casts no-ops; `(unsigned char)(char)field`
  puts an `andi` on just one compare; `opt_common_subs off` stops float-constant hoisting.
- **Register/stack order:** declare pointer locals before an `asm volatile` block and assign them
  after it; pass an inline float argument by pointer to control creation order; block-scoped loop
  counters, or reusing an earlier pointer variable for a later loop, change s-register order.
- **CSE:** a GCC `__asm__ volatile("lq ...")` load blocks MW address CSE; `x=&pt; x=&pt;` gives two
  `addiu` into one register. MW asm has no `"0"` constraint; use `"+r"`.
- **Value-returning operators:** `V r; Helper(&r, ...); return r;` with the VU0 asm one inline
  level deeper.
- **newlib string functions** are built with ee-gcc 2.9-991111 (kind gcc29). Its short-loop pass
  leaves the delay slot empty for loops of ≤7 instructions; an empty `__asm__ volatile("")` in the
  body counts as an instruction but emits nothing. `goto` loops avoid loop-alignment nops; a tied
  empty asm `__asm__("" : "=r"(m) : "0"(k))` forces a copy CSE would turn into `li`; write
  `if (n > 0) { i = n; do … while (--i); }` for retail's `blez`. gcc29 has no MMI types, so MMI
  must be inline asm on 128-bit values. Write work files with LF endings for the WSL compilers.

From the R150–R151 dossier lanes (2026-10-28):

- **Declaration-order search:** register colouring follows the declaration order of locals,
  including pointer locals used in inline asm. Several lanes scored every permutation with
  parallel compiles (0023A5A0 226 → 28, 39EF90 253 → 87; 00400F20 matched only in 1 of 7 orders).
- **Inline depth moves stack slots:** temporaries get slots by inline depth, then source order.
  Extra pass-through `static inline` wrappers (with `#pragma inline_depth(8)`) move a temp to
  retail's slot. MW evaluates call and constructor arguments right to left, and gives the first
  written argument the highest slot.
- **Dead `addiu` of `this`:** `void* xx = this;` inside an inline copy constructor or method
  survives only next to GCC-style `__asm__ volatile` lq/sq copies; MW `asm {}` blocks let it be
  removed. Put it only where retail shows the instruction.
- **GCC `__asm__ volatile` with operands** disables MW's global CSE and constant propagation for
  the whole function and changes argument evaluation order; MW `asm volatile {}` blocks the
  delay-slot fill. Pick the copy idiom per function.
- **Bool shapes:** `bool ok = true; return ok;` gives retail's `andi v0,0xff` tail;
  `#pragma opt_rebuildlogicals off` (undocumented, found in `mwccps2.exe`) keeps inline bool
  results as branches; assigning 1/0 in an `if` with explicit `== 0` tests avoids `sltu`.
- **Float scheduling:** declare float locals first, then assign them in retail order; compute
  all products into locals before storing to get retail's multiply operand order.
- **Misc:** `*(int*)&f = 0` gives `sw zero`; a union with a `u64` member forces reloads after
  64-bit stores; hoisting block-scoped locals to the function top fixes stack layout; MW vtable
  slot offset is 8 + 4 × index.

- **Quad copy split at the call site (M16):** writing a 16-byte copy as a volatile asm `lq` plus
  a C `sq` (instead of a class `operator=` or a full asm block) changes MW's register pairing; it
  closed cNIEventOBJ_v01 and PlayerCamera_ComputeSlopePitch. `build/agents/M16/tools/splitlq.py`
  tries it at every quad-copy site of a draft.
- **Local message structs:** a destructor can match the inlined teardown yet still emit a weak
  out-of-line `__dt__…` that check_match counts as an extra function; call an explicit teardown
  method (`m.Done()`) instead. `#pragma exceptions off` does not stop it.
- **Below 0x300000, fresh targets and sibling twins are exhausted (2026-10-26).** Remaining small
  near misses (TargetVis_Test 1 line, Actor_GetEyeNode, ZoneMgr_DeactivateObject,
  LosRegion_GetCollection, func_0022D3C0, GuiAgentCreate_UpdateCount 4 each) are listed with
  drafts in `build/agents/M16/FINAL_REPORT.md`; the large functions are now the main lever.

- **MW `asm volatile {}` and float constants (2026-10-26):** after a volatile asm block (MW or
  gcc `__asm__ volatile`), float constants later in the same basic block are stored from FPRs
  (`mtc1` + `swc1`) instead of as integer stores (`sw zero`). Non-volatile MW asm does not do this.
  MW asm blocks are scheduled with the surrounding code, so an `sq` can land in a call delay slot.
- **A non-empty GCC-style `__asm__` switches MW to a less-optimised mode for the whole function:**
  bool temporaries stay as `move/daddiu` pairs, pointer ternaries stay as branches (no `movz`),
  and `x == a || x == b` stays a compare chain. If retail shows these, write the quad copies with
  gcc asm. An empty `__asm__("")`, MW `asm {}` blocks and pragmas do not trigger it.
- **mw38 frame layout:** named function locals first (first declared at the highest address),
  then function temporaries, then inline locals by nesting depth. Moving an object between those
  classes is the main lever. By-value inline parameters are built straight into the parameter's
  slot; a conversion constructor `V(M m)` builds its result in place.
- **Small levers:** an empty weak destructor on a stack object (in `.dtors_drop`) reproduces a
  branch to the end of the block; a `volatile` cast on one read reproduces one retail reload;
  a float constant held in a local keeps `mul.s` operand order; `if (f && ...)` gives
  `c.eq.s f,zero` while `f != 0.0f` swaps the operands; MW's small-set bit test is
  `(unsigned)(c - 3) < 8 && ((1 << (c - 3)) & mask)`.
- **Whole-function `asm void` is not accepted:** hand-written functions (e.g. 0x3020A8, which
  keeps a total in `$at`, and Sha1_ByteSwapWords 0x4B3320) stay as assembly; drafts are held in
  `build/agents/held/`. Sha1_StoreDigest 0x4B3350 is instruction-identical, but check_match sizes it
  up to the next function start past the island's trailing data (0x74 vs 0x160).

- **Splitting a packed asm unit (2026-10-21):** when one splat unit holds several functions
  (thunk tables, for example `0x416830`), add each unnamed function to
  `config/symbol_addrs.txt` as `func_XXXXXXXX = 0xXXXXXXXX; // type:func` and write all of them
  in one file in retail order. Any `symbol_addrs` change invalidates `check_match`'s symbol
  cache, so the next run rescans every asm file (10+ minutes on Windows).
- **mw38 argument scheduling:** where a float parameter sits among the int parameters of a
  callee's prototype changes which instruction fills the call's delay slot (0x19D950).
- **mw50 stack slots** appear to be ordered by size rather than declaration order; a named
  handle local or moving an `int` into a nested inline can fix slot offsets (0x22C720).
- **mw38 stack slots:** function locals, then temps, then inline locals, then nested-inline
  locals. Plain `asm { sq zero, 0(d) }` blocks keep retail's unfolded `addiu` + `sq`. An
  `asm { .set reorder }` changes how later asm blocks in the same function compile.
- **Open near misses** (drafts under `build/agents/<lane>/work/best_*.c`): 0x0026C570 (3 diffs,
  f2 zero-load placement around an asm block), 0x00143DF0 (3, delay-slot source),
  0x00234110 (4), 0x003C5EA0 (3), 0x00476998 (3, `lui; jr; lw %lo` form), 0x0015C390
  (23, s0/s1 swap), 0x00190060 (28, lq/sq temp registers), 0x00179620 (41), 0x003ADA60 (42),
  0x001B0A50 (61), 0x001D3AD0 (85).

- **mw38 value-returning vector operators:** write `operator-` etc. as `V r; SubV(&r, this, &o); return r;`
  with the VU0 asm in its own inline one level deeper; this removes an extra return-slot
  address and improved every draft it was tried on.
- **mw38 misc (newest):** zero float struct fields through an int view to stop MW CSE-ing the
  field address; an `(unsigned)` index cast blocks strength reduction; route a call result through
  a temp to load a field after the call; an unconditional multiply before a ternary gives retail's
  speculative `mul` in the delay slot; `(T*)(int)&x` stops constant-address folding; a one-iteration
  copy loop keeps a separate source register; `i = 0; goto test;` enters a loop at its test; when
  every delay slot in a function is unfilled, look for an asm copy macro.
- **Fresh targets:** with most callees named, functions no earlier lane has drafted (grep the
  address under `build/agents/`) have been the most productive targets.

- **gcc 2.96 calls are cross-jumped too:** jump2 merges a call into a shared `jalr` when at
  least two trailing instructions match, so write each arm as its own call followed by its
  own copy of the cleanup tail to get retail's single shared call (unit 0x30C780).
- **gcc 2.96 delay slots and calls:** the delay-slot pass stops its liveness scan at any call
  that might throw; a call counts as non-throwing only if the callee was defined earlier in
  the same source file. A weak `.dtors_drop` stub of that callee (commented) reproduces it
  and fixes wrongly annulled `beqzl`/`bnezl` slots (RtUdp_SendPump, RtUdp_UpdateTransport,
  RtUdp_ParsePacket).
- **gcc 2.96 `return 0`:** directly after `if (r) return r;` it is deleted (v0 known zero),
  which shifts later registers; route it through one shared final `return 0`. Nested ifs keep
  `k < 8 && k >= 0` as two branches instead of one unsigned compare. Units with short
  literals that would go to `.sdata` under -G8 are -G0 (`gcc296g0`).

- **mw38 stack slots of memory-resident locals:** MW splits a local that must stay in memory
  into one live range per reassignment; every live range after the first gets its own
  4-byte slot at the bottom of the frame (below the temporaries, ascending in program order),
  and the value is re-read every pass. One function-scope `union { LNode* p; }` iterator
  shared by all list loops (first loop assigns the member, later loops assign the whole
  union, a block move) reproduces it (`func_00436380`).
- **mw38 table-walking pointers** come from MW strength-reducing plain int indexes
  (`tbl[row][col]`); explicit pointer locals put the setup before the loop guard instead.
- **mw38 float constants through integer registers:** route only one constant through a
  float local (`float ka = 0.5235988f; c->fov = ka; c->f2E4 = 1.0000001f; ...`) to get
  retail's load order (`002A2590`, `GuiScoresEquip_UpdateFigures`).
- **mw38 misc (newest):** `#pragma optimize_for_size on` changes delay-slot filling; a weak
  destructor on RAII helpers suppresses the out-of-line `__dt__`; byte-offset element
  addressing fixes `addu` operand order; never name an MW asm operand `s1`/`s2`;
  `asm volatile { .set noreorder ... }` is a real barrier; `ok = !(s <= zero)` with an
  unsigned zero local gives `sltu; xori; xori`.
- **gcc 2.96 (newest):** declare callees `int` rather than `void` early (stores move in and
  out of call delay slots); `return 0` right after `if (ret) return ret;` lets gcc reuse
  the known-zero v0, so send it through a single final `return 0`; volatile fields fix
  store order; store zeros as `0.0f`. Register pinning: see Ground rules.
- **Multi-function retail units:** write one file with every function of the unit in
  retail order; `integrate_pending.py` now sizes the new C unit from all of the object's
  `.text` sections (it used to take the first function's size only).

- **mw38 asm blocks and scheduling:** any MW `asm {}` block in a function stops MW filling
  branch delay slots from the fall-through path; write the instruction as gcc-style
  `__asm__ volatile` instead. A non-volatile MW `asm {}` is not a scheduling barrier;
  `__asm__ volatile` and MW `asm volatile` are. `else { asm { .set reorder } }` keeps an
  empty else block.
- **mw38 address CSE:** fields read through `template<int O, class T> struct At { char pad[O]; T v; };`
  are not CSE'd into a saved address register. An inline returning `&e->sub` keeps a
  `+off` base unfolded. `(T*)((char*)base + n*sizeof(T))` with a fresh loop variable stops
  strength reduction.
- **mw38 floats:** float registers are assigned in declaration order but loaded in
  assignment order (declare `ax, ay, az`, assign z, y, x). `cvt.w.s` needs inline asm
  (a C cast gives a different conversion; objdump spells it `trunc.w.s`). A float passed
  to varargs gets `SoftFloat_FloatToDouble` automatically; double compares can call
  `SoftFloat_FloatToDouble` / `SoftFloat_DoubleGreaterEqual` explicitly.
- **mw38 misc:** a `bool` local gives `daddiu` where `int` gives `addiu`; copies of the
  parameters as the first locals order the s-registers; an unused `const T* rr = &r;`
  reproduces a dead address load; a dead address-taken local reserves a scalar slot;
  `*(volatile int*)&x` (commented) reloads a value every pass; initialize a matrix where
  it is declared to avoid temporary copies; a value-initialised default argument
  (`const T& v = T()`) on an inline wrapper gives the zero-fill loop with a null check;
  `#pragma bool off` with `r = c1; r = r ? c2 : r;` materializes test results;
  `{ p = Alloc(); if (p) p = ctor(); n = p; }` keeps the switch join block.
- **Sibling search:** comparing instruction shapes against every matched function finds
  templates for most large matches (`clone_match.py`, and the ROM-based finders used this
  round). objdump folds zero words into `...` unless given `-z`, hiding padding nops in
  diffs; and it prints `move`/`li`, so compare bytes with relocations masked rather than
  mnemonics (addiu vs daddiu, ori vs addiu).

## Earlier near-miss techniques

- **gcc 2.96 types:** changing the declared type of a pointer field (`void*` vs struct
  pointer) or a callee's return type (`int` vs `void`) shifts scheduling and register
  choice; it finished `003177D0`, `003041B0` and `002E6F40`. Weak `.dtors_drop` stubs for
  both callees of an `||` condition turned a stray `bnel` into `bnez` (`002F0E60`).
- **gcc 2.96 shared error exit:** route every later `return N` to one `err:` label placed
  after the first check (`002FF308`). `memcpy(&dst, p, N)` reproduces retail's unaligned
  `ldl/ldr` copies where struct assignment does not.
- **mw38 loop trampoline:** to keep retail's extra jump to the loop test, start the loop
  with `goto tramp;` and put `tramp: asm { nop } goto test;` after the final `return`
  (`ShadowMgr_Construct`).
- **mw38 misc:** `#pragma opt_strength_reduction off` plus a `volatile` read of the count
  (`0032D0D0`); `#pragma opt_arithtransformation off` with an explicit if/else for a
  0/1 result (`002D2BD0`); a trivial `T() {}` constructor on a returned struct makes MW
  build it straight into the local's slot; gcc-style `__asm__` copies stop mw38 from
  unrolling a copy loop, MW `asm{}` blocks do not. Never write an empty `asm {}` block:
  it hangs mwcc.
- **mw38 scheduling barrier:** an empty `asm { .set noreorder; .set reorder }` (or
  gcc's `__asm__ __volatile__("")`) emits nothing but stops instructions moving across
  it. Several committed files already use it.
- **mw38 register order:** the order function-scope locals are declared (in C and C++
  mode) changes which registers MW assigns them.
- **gcc 2.96:** whichever parameter is stored first gets `s0`; copy a parameter into the
  loop variable after an early `return`, not before; `for(;;)` with `break` and one
  return after the loop reproduces retail's block order.
- **mw38 inline helpers:** exposing a helper's locals in the caller and changing their
  declaration order can resolve register allocation without changing control flow.
  This finished `AnimCtl_UpdateTransitions` and `PlayerSlots_Get`.
- **mw50 indexed pointers:** integer byte-address addition can choose different
  temporary registers from pointer indexing. This finished both texture-cache
  update functions at `00382190` and `00382540`.
- **GCC register copies:** bind a local copy rather than the incoming parameter.
  Assigning it after the null test preserved the original branch register in
  `00311120`; assigning the shared second argument before the final call branch
  recovered both argument delay slots in `0027C410`.

- **gcc296:** a weak stub of the callee in the same file
  (`int __attribute__((weak, section(".dtors_drop"))) f(...) { return 0; }`) can change
  `bnel` and delay-slot choices. `int r = K; return r;` keeps `v0` live across
  branches. A struct copy produces `ldl`/`ldr`/`sdl`/`sdr`. A ternary produces `movz`.
  The callee's declared return type and pointer-vs-int fields change register
  allocation.
- **mw38:** declaration order sets which saved register a local gets, but not its
  stack slot. Reading a field through a cast inside a loop makes the compiler hoist and
  spill the pointer; declaring the field in the struct avoids it. Declaring callee
  parameters `int` rather than `long long` avoids sign extension. A `static inline`
  helper that returns `p + 1` stops store offsets being folded.
- **mw38 stack slots:** moving a local's declaration into a nested block `{ ... }`
  changes the order of spill slots when declaration order alone does not.
- **mw38 static initializers:** the store order in `__sinit_*` follows the member
  declaration order of the struct or class, not the order of the assignments.
- **mw38 switches:** sparse `case` labels are tested in reverse source order; reorder
  the cases to match the compare chain.
- **mw38 calls:** a call through a C function pointer goes through `v0`, while a C++
  virtual call goes through `t9`. Pick whichever matches the retail register.
- **Decompiler argument omissions:** check every call against the original argument
  setup, including unused receivers, fifth/sixth integer arguments and floating-point
  arguments. A lower difference score can hide an incomplete prototype.
- **mw38 loop guards:** after initializing an index to zero, `index < count` can
  retain a separate comparison that `count > 0` replaces with a direct branch.
  A pointer const-reference helper used only in the loop update can preserve the
  original count and data-pointer setup.
- **mw38 inlined wrappers:** a getter taking a global value as an argument can
  preserve an eager load; a queue wrapper with the iterator initialized after its
  entry fields can preserve stack-store order. Use the surrounding source semantics
  to choose the wrapper rather than adding instruction assembly.
- **mw38 dead aligned slot:** a `volatile int x[4];` local reproduces an aligned
  16-byte stack slot that is written but never read.
- **Return registers:** declaring a `void` callee as returning `int` can fix
  `v0`/`v1` choices in the caller.
- **gcc296:** wrapping one of two adjacent `memcpy`s in `do { } while (0)` keeps the
  compiler from merging or reordering them.
- **SCE assembler padding:** some SDK functions were built with the SCE assembler,
  which inserts `nop`s after `li.s`/`div.s` and in short loops. A small inline `asm`
  sequence reproduces it (comment why).
- **gp swaps and libgcc aliases:** a short asm barrier fixes a swapped `gp` load; a
  libgcc routine that the game re-exports can be expressed as an alias,
  `__asm__("__floatdisf = func_XXXXXXXX");`.
- **Permutation over declaration order:** for mw38 near misses that differ only in
  saved registers or slots, a small script that tries every order of the local
  declarations (and a few block nestings) finds the match quickly. Give each trial its
  own scratch directory; a shared directory corrupted scores in parallel runs.
- **mw pragmas:** `opt_rotateloops off` gives the "branch to the loop test" layout,
  `opt_unroll_loops off` stops fixed-count copy loops being unrolled, `peephole off`
  stops constant offsets being folded into loads/stores, `opt_propagation off` keeps
  separate copies of inlined-function arguments.
- **Unsolved pattern:** several large mw38 functions keep code from inlined helpers that
  the compiler would normally optimize away (dead `if (out)` branches, unfolded offsets,
  recomputed index arithmetic). No pragma combination reproduces it yet.
- **decomp-permuter** found several GCC matches in long runs (20 minutes or more). It
  can't parse the C++ drafts.
- **mw38 stack-slot order by inline depth:** locals of deeper inlines get later (lower)
  slots. Wrapping a helper in pass-through inlines moves its temporary down; declaring
  named struct locals in the outer function and passing them by reference moves them up.
- **Per-call-site helper copies:** when one inline helper is used at several sites and
  each site needs a different register or operand order, give each site its own copy.
- **Hidden return slots:** an inline returning a struct computes the return-slot address
  at the start of the inline; a hand-written copy (`{ V* pt = &tmp; *pt = *p; }`) fixes
  the order.
- **VU0 vector compare:** the original code tests VU0 flags with
  `vnop` ×4, `cfc2.ni f, vi17`, `bne k, f, done`, `ori r, zero, 1`. This sequence is the
  only accepted asm that contains a branch.

## Naming from the PC port research

The private PC port keeps research notes with a generated `ADDRESS_INDEX.md` of every EE
address it cites. Name syncs (2026-10-18/19: 731 function names, 104 data names) went like this:

1. Collect every cited address that is still `func_`/`D_`, read the note or port source comment,
   and name it only where the research states what it does (mark guesses `(inferred)` and leave
   them out). Follow the existing style (`Module_VerbNoun`, `g_` for globals, vtable names
   from the class). Prefix C library names (`Libc_Abort`, never `abort`).
2. Function names: append to `config/symbol_addrs.txt` (`Name = 0xADDR; // type:func`) and run
   `tools/apply_names.py`, then rebuild every C file and require the OK line.
3. Data names: append `Name = 0xADDR;`, rename the `D_XXXXXXXX` tokens in `src/` and `include/`
   yourself (token-exact; `apply_names.py` only renames functions), then the normal round
   (`data_gen.py release --all` ... `data_gen.py` ... `ninja`). The whole split is redone.
4. Commit names separately from matches.

## Source layout

`src/` follows the original project tree from the prototypes' debug information (paths relative
to the original project's code directory). `config/tu_ranges.txt` lists all 270 original files
with their retail address ranges (and the old library ranges that do not overlap them).

- **Part files.** Each original file `Dir/Stem.cc` is `src/Dir/Stem.c` if its code merged into
  one translation unit, else `Stem.c`, `Stem_2.c`, ... in address order. Asm units and units that
  could not be merged sit between part files. 173 files have no asm left in their range; 26 of
  those are one file, the rest split on declaration conflicts or data order (below).
- **New matches.** `tools/integrate_pending.py` puts a function inside an original file's range
  at `src/Dir/Stem/func_XXXXXXXX.c` (EE-GCC files still go to `src/lib/`). Outside those ranges:
  `src/main/[<tu>/]func_XXXXXXXX.c` as before.
- **Merging later.** After integrating, run `python tools/merge_units.py --all` (or name the
  modules, e.g. `SFOGame/Source/human`), then the full build. New units and neighbouring part
  files are merged when the byte check passes and the part files are renumbered; a lone unit is
  renamed to the next part-file name. `-v` prints why groups split. Most splits are conflicting
  declarations of one helper in different blocks (`cMessage_dtor`, container helpers) or C and
  C++ blocks declaring the same function: give the helper one prototype in a shared header and
  rerun. "data subsegments not adjacent" needs the retail data order and cannot be merged.
- **Not placed:** 982 units under `src/main/` (template/inline code at file boundaries that the
  prototypes attribute to headers only, code added after the prototypes, `src/main/sinit/`) and
  22 EE-GCC units inside game files' ranges (they stay in `src/lib/`).
- **Progress categories:** `main` plus `game`, `libs` and `sdk` (configure.py).

## Merging into translation units

Matched functions are first committed one per file, then merged per original source file
(above; docs/merge_units.md). Each merge is checked byte for byte over the whole unit's code and
data. `--unmerge` cannot split units whose blocks are themselves earlier merged units. Gotchas:
every merged block ends with an empty `static inline` function so the compiler emits each
function in the right C/C++ mode; MW 3.0.3 and 3.0b38 order locals differently; a shared helper
prototype that callers use inconsistently is declared K&R in a shared header (for example
`include/SFOLobby_helpers.h`).

## Known blocked work

- `func_004769A4` (gcc296) is instruction-identical, but its asm unit (0x476998) runs on
  into the data block at 0x476B00; it needs a split at 0x476ABC near the fragile
  `d_00476B00` data units.
- `Mem_Init` (0x36B630) references `D_01FF0000`, `D_0059A980`, `D_0059C980`, which have
  no symbol entries.
- Some functions reference `.lit4` float literals that the current linking cannot place.
- `0x286570` / `0x286590`: already integrated as cTurret_Stop / cTurret_NextFrame in tank_15.c (confirmed R163).
- Hand-written assembly functions stay as assembly.
- `0x2B69A0` (_sceMcFatInit) was resolved in R162 by reusing the existing root-directory
  literal with a fixed-size memcpy. No rodata split was needed; the held draft is historical.
- Do not retry the old 0x286570 packed-unit draft: both functions are already C-owned.
- **Dead `div` in DMA wait loops (`man.cc`):** cMan_ManDMA 0x385D40, cMan_SetGunOffsets
  0x38E100, BloodHitVert/BloodHitPart/BloodHit 0x38BA80/0x38BD30/0x38C050 and GunCalcBBox
  0x38D720 contain a busy-wait loop with a `div` whose result is unused. mw38 removes it in
  every legal form tried; it survives only if the value is carried across iterations
  (`a = a / a;`, but then `li 7` is hoisted) or at `optimization_level 0` (wrong frame).

## Readability

Fully matched modules were cleaned up module by module (names, shared struct headers
in `include/`, enums for magic numbers). [HEADERS.md](HEADERS.md) lists the headers.
Function names live in `config/symbol_addrs.txt`; add a name there and run
`tools/apply_names.py` so every caller is renamed. Many matched modules still use
`func_XXXXXXXX`, `D_XXXXXXXX` and raw offsets.

## Open decisions for the owner

- Whether to commit hand-written assembly functions as `.s` units.
- Whether to give data the same readability treatment as code.
