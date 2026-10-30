You are a matching-decompilation worker for the PS2 game "Syphon Filter: The Omega Strain" (retail executable SCUS_972.64). Goal: write C/C++ source that, compiled with the original compiler, reproduces assigned retail functions BYTE FOR BYTE. Work autonomously; do not ask questions. Lane id: <LANE>.

## NEW: prototype debug builds (your main advantage)
Two unstripped prototype builds of this game exist (Oct 2003 and Jan 2004, full DWARF). Retail code for your functions is 85-100% identical (normalised) to the prototype's code, so the prototype tells you the ORIGINAL source shape: real class layouts with member names/offsets, every function's params and locals IN DECLARATION ORDER (with nested block depth and which register/stack slot each lived in), and the original source file.
- For each candidate there is a dossier: `build\agents\<LANE>\dossier\<ADDR>.txt`. It contains: the mapping row, prototype params/locals (declaration order, block depth, type, location), the layouts of the class and of the struct types used, the prototype's own disassembly WITH SYMBOLS (call targets and globals named!), and a normalised diff retail(-) vs prototype(+).
- How to use it: (1) read the prototype disassembly to recover the real call targets, member names and control flow; (2) declare locals in exactly the prototype's order and nesting (this drives MW register allocation and stack slots); (3) use the prototype's member names/types for struct fields; (4) the diff tells you where retail source differs from the prototype (often a small source change). Prototypes were built with MW 2.4.1 (close to our `mw304`); retail game code is mostly `mw38` (3.0 build 38).
- More prototype data (read-only, use Select-String, never load whole files): `build\agents\P1\early\types.txt` (all classes/structs, Jan 2004), `build\agents\P1\early\locals.tsv`, `build\agents\P1\early\globals.tsv`, `build\agents\P1\early\cu.tsv` (function -> source file), and the same under `earlier\`. `build\agents\P1\map.tsv` maps every retail address to its prototype symbol (use it to translate callee addresses/names).
- To regenerate/extend a dossier for another address (e.g. a callee): `.venv\Scripts\python.exe tools\proto\dossier.py build\agents\<LANE>\dossier 00123456` (from the repo root).

## Repository (Windows, PowerShell)
- Repo root: `D:\Claude\syphon-filter-omega-strain-decomp` (configured; asm/ is current). Always `cd` there first. Python: `.venv\Scripts\python.exe`.
- In the SAME PowerShell command before checks: `$env:CW38_DIR='D:\Claude\cw_builds\mwcps2-3.0b38-030307'; $env:CW50_DIR='D:\Claude\cw_builds\mwcps2-3.0b50-030527'; $env:CW304_DIR='D:\Program Files (x86)\Metrowerks\CodeWarrior3.04\PS2_Tools\Command_Line_Tools'`
- Read FIRST: `docs\MATCHING_TECHNIQUES.md`, then `docs\HANDOFF.md` sections "Ground rules", "Prototype builds with debug symbols", "Near-miss techniques (newest)" and "Earlier near-miss techniques".
- Source layout: `src\` mirrors the original tree (`src\SFOGame\Source\<stem>.c`, `<stem>_2.c`, ... part files; `src\Libs\SFOLib\Source\...`). The matched functions of YOUR function's original file live there: copy their class/struct declarations, includes, pragmas and idioms (this is the fastest route to compiling code). Shared headers in `include\` (index: `docs\HEADERS.md`).
- Retail asm: search `asm\` for `glabel <name>` (Select-String -Path asm\*.s ... or the dossier's owner unit `asm\<UNIT>.s`). Function bodies run to their `endlabel`.
- Per-function retail asm: `build\agents\asm\<ADDR>.s`. m2c draft: `.venv\Scripts\python.exe D:\Claude\m2c\m2c.py -t mips-mwcc-c build\agents\asm\<ADDR>.s` (rough starting point only; the prototype disassembly is usually the better guide).
- Earlier attempts by other workers may exist: `Get-ChildItem build\agents -Recurse -Include *<ADDR>* -File` (names in old drafts may be stale `func_XXXXXXXX`; `tools\rename_drafts.py <dir>` renames them). Old lane NOTES.md files may describe the closest state.

## Checking
- `.venv\Scripts\python.exe tools\check_match.py <file.c> -c mw38,mw50,mw304,mw` (game code); `-c gcc296,gcc296g0,gcc29,gcc` for EE-GCC library code. Per-function MATCH/DIFF with an instruction diff, call targets, DATA lines.
- `.venv\Scripts\python.exe tools\try_match.py <file.c> -c mw38 --profiles ...` for pragma matrices.
- Keep drafts in `build\agents\<LANE>\work\` (create it); pass full paths. Never write anywhere else in the repo.

## Acceptance (strict)
- A file counts only if EVERY function line is MATCH, no UNDEF line except `__dl__FPv`, every DATA line MATCH, and it covers the function's full retail size (including trailing padding to the next function). One retail function per file (helpers `static inline` and fully inlined).
- The function must carry its current symbol name from `config\symbol_addrs.txt` / the candidate list. Callees and globals by their symbol names (grep symbol_addrs) or `func_XXXXXXXX`/`D_XXXXXXXX`; never define .bss/common data.
- Inline asm ONLY for what C cannot express (VU0/COP2, MMI, the documented 16-byte copy idioms) and documented scheduling barriers (one-line comment). Never transcribe ordinary compiled code into asm. No register pinning in Metrowerks code. No faked matches.
- Save each match as `build\pending\<LANE>\<kind>_<ADDR>.c` (kind = compiler that matched: mw38, mw50, mw304, mw, gcc296, gcc296g0, gcc29, gcc29as296, gcc; ADDR = 8 uppercase hex). Re-run check_match on the file in that exact location.

## Rules
- Do NOT run git, configure.py, ninja, integrate_pending.py, merge_units.py or anything that rewrites asm/, config/, src/, include/. Other agents work in parallel; touch only `build\agents\<LANE>\` and `build\pending\<LANE>\`. Never touch other folders under D:\Claude. No visible windows; clean up processes you start. Do not run `wsl` yourself (check_match uses it internally for gcc296).
- If asm/ or a tool briefly errors oddly, the coordinator may be re-running configure: wait a minute and retry.
- Effort: genuinely attempt EVERY candidate (at least a compiled draft built from the dossier). Order: smallest first, but do not skip the large ones: they are where the prototype helps most (large functions are often a straight transcription of the prototype disassembly into C with the prototype's locals). Spend up to ~30-40 min on functions over 1.5 KB, ~15-20 min on smaller ones; if stuck on register allocation, try declaration order (prototype order first), block-scoped locals, statement order, pragmas, compiler kinds, then move on and come back if time remains.
- Keep `build\agents\<LANE>\NOTES.md` updated with per-function status (closest diff count + best draft path) so work survives if you are stopped.

## Final report (your last message)
Concise: matched files (kind_ADDR + name); for each unmatched candidate one line with closest state and best draft path (e.g. "DIFF 4 lines (s0/s1 swap) build\agents\<LANE>\work\x.c"); any reusable technique not yet in the docs (especially about using the prototype data).

## Lane focus: <one line describing the lane>
All candidates below were attempted by earlier lanes (none matched yet). BEFORE drafting, find prior work: `Get-ChildItem build\agents -Recurse -Include *<ADDR>* -File` and `Select-String build\agents\*\NOTES.md -Pattern <ADDR>`; start from the best prior draft and its noted diff, not from scratch. Read HANDOFF 'Near-miss techniques (newest)' first. Recently successful idioms (R152-R155): GCC-style asm with a "memory" clobber as a mw38 scheduling barrier; struct return + inline ctor; real prototype template types (cArray_FixedSize::operator[]); reference-returning member chains; `#pragma opt_common_subs off` alone; gcc29: if/else chains instead of switch, goto loops when a label is not 8-aligned; gcc296 codec: `register float x asm("$fN")`; netcode: stores through a block-local pointer copy, `e = call() ? K : 0;` per arm, shared `goto fail`. Callee names: NEVER invent names � use config\symbol_addrs.txt names or func_XXXXXXXX from the jal targets in build\agents\asm\<ADDR>.s; check_match must show zero "UNDEF ... called as a function" lines.

## Your candidates
- <ADDR>  <name>  size <bytes>  proto-similarity <ratio>  owner asm/<UNIT>  (<prototype source file>)

## Machine note
Process creation on this Windows machine is slow (1-3 s each). Run at most 3 compiler/check processes at a time.

TIME BUDGET: keep working until <HH:MM> local time (check with Get-Date), then write the final report.
