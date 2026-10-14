# Linking data from C (data split)

Until this change only code came from C: a matched unit's object had to be
pure `.text`, every string literal, float table, switch jump table and
initialised global stayed in the assembly of the data segments (`data`,
`data_4AEFD0`, `data_4B33D0`, `data_4D8D10`: 339,552 bytes), decomp.dev showed
0 % data, and functions that need a literal or a jump table could not be
integrated. This note describes how a C unit links its own data.

## Retail layout

The original link placed the code first (0x00100000-0x00476B00) and the data
after it, with two code islands and the static initialisers in between. Within
the data, each object's data sections follow each other **in object order**,
whatever their kind: a function's string literals (Metrowerks `.data`) and its
jump table (`.rodata`) are interleaved exactly as the compiler emitted them
(for example 0x004BA340-0x004BA3B0: five strings of func_00346FB0, then its
jump table at 0x004BA380). Each section keeps its own alignment (Metrowerks:
size <= 4 -> 4, 5..15 -> 8, >= 16 -> 16; gaps are zero-filled).

What the compilers emit:

| Source construct | Metrowerks (mw38, mw, mw304, mw50) | EE-GCC 2.96 -G0 |
| --- | --- | --- |
| string literal | `.data`, one section per literal (`.rodata` with `#pragma readonly_strings on`) | `.rodata` |
| switch jump table | `.rodata`, `R_MIPS_32` words against the function | `.rodata` |
| `static const` table | `.rodata` | `.rodata` |
| initialised global / static | `.data`, one section per object | `.data` |
| float literal, `const float` scalar | `lui`/`ori`+`mtc1`, no data | `lui`/`ori`+`mtc1` |

EE-GCC 2.96 at its default -G8 puts float literals in `.lit4` (doubles in
`.lit8`) and loads them gp-relative (`lwc1 $f0, %gp_rel(D_xxx)($gp)`); see
"gp-relative literal pools" below.

The measured Metrowerks rules are in the d2 notes (`build/agents/d2/rules.md`
in the coordinator's checkout).

## Configuration: one data subsegment per unit

A unit's data block is a *dot subsegment* in `config/splat.yaml`, named like
the unit, at the retail address of the block:

```yaml
      - [0x2FE110, c, main/globalization/func_003FE110]
      ...
      - [0x3B33D0, data, data_4B33D0]
      - [0x3BE4B0, .rodata, main/globalization/func_003FE110]
      - [0x3BE4C8, data]
```

* The block holds all of the unit's data sections in object order. Its type is
  `.rodata` if the unit has any `.rodata` (jump tables, const tables), else
  `.data` (`.sdata` for gp-relative data only).
* Its size is the laid-out size of the block rounded up to 4 bytes. Trailing
  padding up to the next item stays in the asm data after it, which remains an
  ordinary (unnamed, so splat names it by its ROM offset) `data` subsegment.
* splat writes the retail bytes of the block into the unit's full
  disassembly `asm/<unit>.s` (the objdiff target) and, with
  `disassemble_all`, to `asm/data/<unit>.<type>.s`; neither is linked.

These lines are written by `tools/integrate_pending.py`, never by hand.

## Build (configure.py)

The link keeps one fast wildcard for the code and places everything after
the code by **section name**:

```
.main 0x100000 : AT(0) {
    *(.text* .data* .rodata* .sdata*)   /* code region, command-line (address) order */
    *(SORT_BY_NAME(.tail.*))            /* data region, sorted by address */
}
```

* The *tail* is everything from the first data subsegment on: the asm data
  pieces, the code islands and static initialisers among them, and the data
  blocks of C units. Each tail object's sections are renamed
  `.tail.<VRAM>` (8 hex digits, so name order is address order) by
  `tools/tail_obj.py`; sections with equal names keep their object order.
  The renamed sections do not match the code wildcard.
* A C unit with a data subsegment is compiled to `build/src/<unit>.raw.o`;
  `tools/data_obj.py RAW BASE LINK START [TEXT]` writes
  * `build/src/<unit>.link.o`: its data sections renamed `.tail.<START>` (and
    its `.text` renamed `.tail.<TEXT>` when the code itself is in the tail,
    as for the static initialisers);
  * `build/src/<unit>.o`, the objdiff base: `ld -r` merges all data sections,
    in object order, into one section named like the block type, laid out
    from `START % 16` so inner 16-byte alignments fall where they do in the
    retail block; the section is padded to 4 bytes (its last symbol grows
    over the padding, as splat's label does) and `sh_addr` is reset to 0.
  Both renaming tools rewrite their output only when it changes (`restat`),
  so a change that only affects an objdiff base does not relink.
* Labels inside a C data block that other code still uses (a string pooled in
  the unit's translation unit, say) are defined with
  `PROVIDE(D_xxxxxxxx = 0x...)` in the linker script, from splat's
  `asm/data/<unit>.<type>.s`.
* objdiff: splat's full disassembly of the unit (`asm/<unit>.s`,
  `make_full_disasm_for_code`) already contains the data subsegment after the
  code, so the unit's target object counts the data; the asm data units
  shrink by the same amount. The target is assembled with
  `tools/assemble.py --relative-jumptables`, which writes jump-table entries
  `.word .L003FE1C0` as `.word func_003FE110 + 0xb0` - the form the compiler
  emits - so objdiff sees equal bytes and relocations. EE-GCC instead
  relocates the entries against `.text` plus the offset in the unit, so
  `tools/data_obj.py` rewrites them in the base to the same form (without
  it every jump table of a function that does not start its unit fails).
* A unit whose compiler is not installed falls back to splat's assembly
  (code and data), renamed the same way, so the build still matches.

Uninitialised data (`.bss`, `.sbss`, common) cannot be placed yet:
`data_obj.py` stops with an error; such variables stay `extern`. The C++
exception index (`.exceptix`) is discarded as before.

A side effect: the old script had to match every object through one
wildcard and took minutes to link; the build above links in about 30 s here.
## How objdiff counts it

For each unit `objdiff-cli report` adds the size of each data section of the
target object to `total_data`, and the size of each section whose bytes and
relocations all match to `matched_data`. Asm data units have no base object,
so they only count toward the total. Before this change no C unit had data,
so matched data was 0 of 339,552 bytes.

## Checking a candidate

`tools/check_match.py` now places and compares the data of the file:

```
[mw38] func_003FE110: MATCH
[mw38] DATA .rodata 0x004BE4B0 size 0x18: MATCH
```

The %hi/%lo pairs that load the data give the retail address of the items
they reference; the block is laid out in object order with the sections' own
alignment (the block start is searched below the first referenced item when
that item is not the first section); bytes are compared with the retail data
and relocations inside the data (jump-table entries, pointers to functions or
other data) are resolved to retail addresses and compared. Other results:
`DIFF at <offsets>`, `not referenced from code (cannot be placed)`,
`inconsistent placement`, `the referenced items cannot be laid out in object
order at their retail addresses`, and a request to make `.bss` data extern.

## Integrating

`tools/integrate_pending.py REPO DONE_DIR` replaces the old external
integrator and `integrate_island.py`: it compiles each done file (CW38_DIR,
CW304_DIR, CW50_DIR as for check_match), requires the DATA result to be
MATCH, cuts the block out of the asm data segment that holds it and adds the
unit's `c` and dot subsegments. Functions in the static-initialiser island
(`sinit_*` asm segments) become `main/sinit/func_<ADDR>` units. A done file
for a function that is already a C unit replaces that unit's source when it
adds data (an `extern D_xxxxxxxx` turned back into the literal or table).

## gp-relative literal pools (.lit4/.lit8)

The retail linker merged the `.lit4`/`.lit8` sections of all EE-GCC -G8
objects into one deduplicated pool (around `0x004E1B8C`, inside the data-only
unit `data/d_004E1B00`); a value used by several functions is stored once, so
a unit's literals are neither contiguous nor its own and cannot be carved out
like `.rodata`. Instead the pool stays where it is and the C unit's loads are
pointed at it:

* gcc emits `R_MIPS_LITERAL` relocations against the `.lit4` section symbol
  (instruction immediate = offset - gp0, gp0 = 0x4000 in `.reginfo`).
* `tools/lit_pool.py` (run by `tools/compile_aligned.py --pool ROM GP VRAM`,
  which the `gcc` rule in `configure.py` passes for every EE-GCC unit) reads
  the retail instruction at each load (`gp + simm16` gives the pool address),
  requires the literal's bytes to equal the retail pool entry, rewrites the
  relocation to `R_MIPS_GPREL16` against the undefined global `D_<ADDR>`
  with a zero immediate, and the `.lit4`/`.lit8` sections are removed.
  Objects without literal sections are unchanged. A literal that differs from
  retail stops the build with an error.
* The object then has exactly the relocations of the splat asm
  (`%gp_rel(D_<ADDR>)`), so objdiff pairs the functions; the pool bytes keep
  counting toward the data-only unit.

`check_match.py` prints one `LIT` line per literal
(`[gcc296] LIT .lit4 0x004E1BD0: MATCH`) and `integrate_pending.py` requires
them all to match. gcc 2.96 rounds some long decimal float literals to the
wrong float (`0.015915492549538612f` gives `0x3C826134`, retail
`0x3C826135`); write a shorter spelling (`0.01591549255f`) or the hex value
when a LIT line shows a DIFF.

## Conventions for matching agents

* Write data the natural way: string literals, `switch`, `static const`
  tables, initialised statics. Done file names are unchanged
  (`<kind>_<ADDR>.c`).
* A file is done when every function line says MATCH and the DATA line (if
  any) says MATCH. `objdump -h` may now show `.data`/`.rodata`.
* One unit owns a data item: Metrowerks pools identical literals per
  translation unit, so a string used by several functions belongs to the
  first of them. Every other user, and any data that is not this function's
  own, is referenced as `extern char D_xxxxxxxx[];` (the label stays defined
  when its owner is linked from C) (only names that exist in
  `asm/data`; use `(D_label + n)` inside a label).
* The function's data must be one contiguous block in retail; items that are
  not referenced from its code (or not directly after the referenced ones)
  must stay extern.
* No uninitialised data definitions (`.bss`): use extern.
* Upgrading an already integrated function: put the new version in done\
  under the usual name; the integrator swaps the source if it brings data.