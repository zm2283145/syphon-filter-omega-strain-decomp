# P1: mapping retail functions to the prototype builds

The scripts are committed; their outputs are private. Put the two prototype ELFs (`SCUS_972.64_earlier_proto.elf`, `SCUS_973.97_early_proto.elf`, never committed) in `orig/prototypes/` or point `SFOS_PROTO_DIR` at them. Outputs go to `build/agents/P1/` (gitignored; override with `SFOS_P1_DIR`).
Never commit anything from the output folders (`early/`, `earlier/`, `cache/`) or the prototype binaries.

## Rerun

```sh
# from the repository root
python3 -I tools/proto/extract_proto.py            # both protos -> early/, earlier/, cache/<proto>.pkl   (~10 s)
python3 -I tools/proto/extract_retail.py [--refresh]  # retail fingerprints -> cache/retail.pkl          (~5 s)
python3 -I tools/proto/match.py                    # cache/match_{early,earlier}.pkl                       (~30 s)
python3 -I tools/proto/combine.py                  # map.tsv, names_*.txt, renames.tsv, layout*.txt, vtables.tsv, coverage.txt
python3 -I tools/proto/spotcheck.py 0x0015D170     # side-by-side disassembly diff of one mapping
python3 -I tools/proto/spotcheck.py --sample 20 --method order-gap --seed 3 [--quiet] [--conf medium]
```
Dependencies: Python 3 and pyelftools (`pip install --break-system-packages pyelftools`), plus the repo's
`.tools/binutils` objdump (used only by spotcheck).
`extract_retail.py` reads function names and sizes from a snapshot of `build/SCUS_972.64.elf`
(`retail_built.elf`; pass `--refresh` to re-copy it after symbol renames). It reads code bytes from
`orig/SCUS_972.64` and splat units from `build/SCUS_972.64.map`.

## Tools
| file | purpose |
|---|---|
| `dwarf1.py` | Hand-written DWARF v1 (.debug) parser for Metrowerks output: DIE tree via AT_sibling, type rendering (fund/mod/user types, arrays), location expressions (MW op 0x80 = FPU register). |
| `demangle.py` | Demangler for the Metrowerks/cfront mangling (`Load__6cHumanFPv`, `Q2` qualifiers, `T`/`N` repeats, templates, function templates with `_ret`). It also builds `Class_Method` identifiers. Modern binutils c++filt cannot read this mangling. |
| `common.py` | ELF loading and R5900 instruction normalisation: h0 = exact except jal targets and %hi/%lo/gp immediates; h1 = opcode + registers; h2 = opcode only. Also collects the jal call list, the lui/lo data references and the strings they point to. |
| `extract_proto.py` | Per proto it writes `cu.tsv` (object .cc, source CU, address, size, mangled, demangled), `types.txt` (structs/classes/unions with member offsets/types/sizes, bases, enums, typedefs), `locals.tsv` (params/locals/statics in declaration order, with lexical-block depth, type and location) and `globals.tsv` (global variable addresses and types). |
| `extract_retail.py` | Retail function list and fingerprints. |
| `match.py` | The matcher (see Method). It runs separately against each proto. |
| `combine.py` | Merges both proto runs, assigns confidence, builds the names, renames and layout. |
| `spotcheck.py` | Disassembly diff for manual verification. |

## Method (match.py)
1. **Anchors**: a retail function and a proto function become an anchor when their h0, h1 or h2 hash is unique on both sides (the function must be at least 3 instructions).
2. **Link-order gaps**: matched pairs that are consecutive in retail order and increasing in proto order bound a gap. The gap is aligned by DP over a cheap opcode-histogram similarity, and each accepted pair is re-scored with difflib on the opcode sequence. Runs are also extended outward from every match while similarity is at least 0.6.
3. **Call graph**: the jal lists of matched pairs are aligned with difflib. Equal-length unmatched stretches pair up position by position when similarity is at least 0.6.
4. **Vtables**: each proto `__vt__X` is located in retail by votes from already-mapped slots. The remaining slots then map one to one.
5. **Strings**: rare string references (used by at most 2 functions on each side) vote for a pair.
6. **Ambiguous hashes**: when an h1 hash has several candidates, the one at the position predicted by the neighbouring matches wins.
7. **Data references**: a retail-to-proto data-address map is learned from exact pairs. Matches whose data or call evidence contradicts them are pruned, and new matches are proposed from shared mapped data refs.
8. **Fuzzy global**: leftovers of at least 16 instructions are compared against the unmatched proto functions.

Stages 2 to 7 iterate until nothing changes.

Confidence (combine.py):
- **high**: unique exact hash, or link-order/call-graph/vtable/data match with high similarity, with no xref conflict. Two medium matches also become high when both protos independently give the same identifier and similarity is at least 0.7 (note `2-proto-agree-promoted`).
- **medium**: lower similarity, or the two protos disagree (`protos-disagree`).

## Outputs
- `map.tsv`: every retail function with confidence, proposed name, both proto matches (address, symbol, method, similarity), xref agree/disagree counts, original object and notes.
- `names_proposed.txt`: high-confidence names for functions currently named `func_XXXXXXXX`, in symbol_addrs.txt format. These can be applied.
- `names_proposed_renames.txt` and `renames.tsv`: high-confidence names for functions that already have a non-func_ name. These are for owner review only. The `kind` column is one of `vslot->name`, `same-prefix`, `different`.
- `names_review.txt`: medium-confidence mappings with evidence, plus unstable proto names (`nScriptNNNN::func` script thunks, whose numbers change between builds).
- `layout.txt`: splat unit to original source file (relative to `C:\SFO\Code`). `layout_objects.txt` merges contiguous units into per-object address runs.
- `vtables.tsv`: retail vtable address to proto `__vt__` symbol and class.
- `early/`, `earlier/`: the DWARF dumps (cu.tsv, types.txt, locals.tsv, globals.tsv).

Naming conventions: `Class_Method`, `Class_ctor`, `Class_dtor` and `Class_opAssign` (other operators follow the same op* pattern). Namespaces (`nMSGGAME::`, `@unnamed@...`, `Metrowerks::`) are dropped for class members and kept for free functions. Template classes get a short form of their arguments (`cArray_cHumanPtr_Begin`). C library functions become `Libc_Xxx`, newlib internals in 0x121B00-0x12ECD0 become `Newlib_Xxx`, and `__sinit_<file>` becomes `StaticInit_<file>`. When an identifier repeats, a parameter-type suffix is added, then `_2`, `_3`, and so on. No proposed name clashes with any name that stays in symbol_addrs.txt.
