# Matching decomp — progress log

## Decisions needed (owner)

1. **Exact compiler build.** The game code is Metrowerks CodeWarrior PS2.
   The three decomp.me archive builds that run without a FLEXlm license file
   (`mwcps2-3.0-011126`, `3.0.1-020123`, `3.0.3-020716`) reproduce most tested
   functions, but not all (see "Compiler evidence"). The 2003 builds
   (`3.0b38`…`3.0.1b87`) refuse to start without `license.dat`. Testing them
   needs a CodeWarrior PS2 license you are entitled to (or however decomp.me
   is permitted to run them). No license workaround was attempted.
2. **decomp.dev listing.** This public repository was split out of the
   private port project for decomp.dev; see [DECOMP_DEV.md](DECOMP_DEV.md).
3. **CI access to the executable** (self-hosted runner or encrypted secret).
   Also covered in DECOMP_DEV.md.

## Current status (2026-10-09)

| Item | State |
| --- | --- |
| Round-trip build (all asm) | **Byte-identical**, SHA-256 `9924da91…31dc6` (Windows, native tools) |
| Build with C | **Byte-identical** with 3,018 functions compiled from C |
| Functions (objdiff) | 3,018 / 14,327 matched (21.1 %) |
| Code bytes (objdiff) | 66,000 / ~3.66 MB (1.80 %); mostly small accessors, container helpers and straight-line call wrappers |
| Data | not tracked yet (one data file from 0x00476B00) |

"Matched" means the whole executable still builds with the SHA-256 of the
retail file and objdiff reports the function as identical. Function totals
are splat/spimdisasm's function detection over 0x00100000–0x00476B00 and will
shift slightly as boundaries are refined.

## Toolchain identification — evidence

* **ELF container**: 5 `PT_LOAD` entries (0x00100000 empty, 0x00100000 image
  filesz 0x3E1D80 / memsz 0x498980, 0x00598980 empty, 0x01E68000 memsz
  0x180000, 0x70000000 scratchpad), unnamed section headers, empty
  `.symtab`/`.strtab`, `.reginfo` with gp = 0x004E9B70. This layout is
  characteristic of the Metrowerks linker `mwldps2`.
* **`.comment`** = `"MW MIPS C Compiler (2.4.1.01)\0PlayStation2\0"`. Every
  archived `mwldps2.exe` (2.3.3 through 3.0.1b87) embeds exactly this string,
  so it identifies the Metrowerks linker but not the compiler build. The
  2001–2002 compilers (3.0, 3.0.1, 3.0.3) also call themselves 2.4.1.01; the
  2003 builds say 3.0.0.
* **Startup**: `_start` at 0x00100008 clears all GPRs with `padduw`, zeroes
  BSS (0x004E1D80–0x00598980), sets gp and calls `SetupThread` — Metrowerks
  `__start`.
* **Code idioms**: 9,652 stack-frame prologues; game functions save `ra` with
  `sd` and callee-saved registers with `sq`; moves are `daddu rd, rs, $zero`;
  functions are 16-byte aligned (12,596 at 0 mod 16; 1,520 at 8 mod 16, mostly
  GCC-built libraries). Almost no `$gp`-relative access in game code (316
  uses, nearly all in libraries) → compile with `-sdatathreshold 0`.
* **Test compiles** (`mwccps2 -O4,p`): byte-identical results for e.g.
  copy-assignments (0x00130AE0), a float setter (0x00132000), a tail call with
  computed arguments (0x00130F20), a 3x3 matrix builder taking a stack float
  argument (0x00140E20) and 897 small accessors. `,p` is required: it emits
  the `nop` after `jal` in loops seen in the retail code.
* **Compiler evidence for a later build**: 0x001423E0 (loop over six 16-byte
  slots calling 0x00142450) compiles to the right instructions with all
  license-free builds, but the retail code places the post-`jal` `nop`
  inside the conditional block (the `beq` skips it) whereas 3.0/3.0.1/3.0.3
  branch to it. Source variants did not change this; it most likely needs one
  of the 2003 builds. Kept as asm.
* **Libraries**: `PsIIlibgraph2800`, `PsIIlibpad2 2800` (Sony SDK 2.8.0),
  libdbc, usbkb, libnetb 1.10, Medius client 1.50.0014 / game comm 1.50.0000,
  rt_* SCE-RT libs, DME 1.32, lgaud 1.09 (Sep 2003), 989snd, nellymoser.
  These are prebuilt EE-GCC archives linked between game objects (not in one
  contiguous block). Game sources are C++ (`.cc` names such as `Objective.cc`,
  `hog.cc`, `GuiLobbyScreen.cc`).

## Setup (done)

* `configure.py` + ninja; splat 0.50.0 / spimdisasm 1.42.4; binutils
  mips-ps2-decompals v0.10; objdiff-cli v3.8.2. See README.md.
* `tools/extract_rom.py` takes the program image from the user's ELF,
  `tools/elf_rebuild.py` rebuilds the retail container (headers from
  `config/elf_layout.json`), `tools/check_sha256.py` verifies it.
* Each matched C unit gets an objdiff target assembled from splat's full
  disassembly of the same range (`make_full_disasm_for_code`).
* Linking uses splat's script with `SUBALIGN(16)`, so a C unit must start and
  end on 16-byte function boundaries.

## Matched so far

* 863 two-instruction functions found by pattern (empty bodies, `return this`,
  `return K`, field getters/setters by offset, float getters/setters, byte
  stores…), generated from templates and verified byte-identical.
* 38 hand-written functions, many described in the companion port project's research notes: vector/iterator
  helpers (begin/end/increment of the count+data arrays at
  0x00133960/0x00133990, 0x001E8F80, 0x00224A80/90, 0x0040F520/30 …), texture
  header offsets (0x003809B0 palette, 0x003809C0 pixels), script wrappers
  (`SetSpeed` 0x00211190), list/stack helpers (0x00139070, 0x003B1770,
  0x003ADF60), predicates (0x00190910, 0x001909A0, 0x001E9070, 0x001821A0).
* 688 further functions are byte-for-byte duplicates of matched leaf functions (C++ template instances: container swap, iterator begin/end/compare, copy constructors) and reuse the same source.
* Files live in `src/main/` named after their first function until real
  translation units are identified; shared provisional types in
  `include/types.h`.

### Attempted, not matched yet (kept as asm)

0x001423E0 (see above), 0x00131E70 / 0x0013AAC0 / 0x0017CD90 / 0x00133300
(128-bit copies whose address arithmetic suggests inlined C++ member
functions), 0x001839F0 (byte mask), 0x0019D7B0 (operand order of `addu`),
0x002111C0 (`movz` select), 0x00211310 (4-byte value returned through the
stack, probably a C++ by-value class).

## Next steps

1. Compile as C++ (`-lang c++`) for class-shaped code: by-value iterator
   and script-value classes, inline members, constructors/destructors
   (e.g. the vtable-setting destructor pattern at 0x00140D40).
2. Find translation-unit boundaries (`.cc` strings, function order, vtable
   and string-pool layout) and move matched functions into real files.
3. Separate game code from SDK/middleware ranges and add objdiff progress
   categories (game vs. libraries); libraries need EE-GCC (decomp.me has
   ee-gcc 2.9x builds).
4. Split `.data`/`.rodata` further (rodata likely starts near 0x00497F70,
   strings and VU microcode around 0x00476B00…0x004C0000) so data can be
   tracked and referenced symbolically.
5. Import names from the port project's research notes into `config/symbol_addrs.txt`.
6. Resolve the compiler build question (decision 1) and retry the
   near-misses above.
