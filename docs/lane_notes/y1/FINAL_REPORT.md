# Lane Y1 final report (2026-11-02)

## Staged
| function | addr | size | file |
|---|---|---|---|
| func_003FD740 (UTF-8 -> local charset) | 0x3FD740 | 768 B | build/pending/y1/mw38_003FD740.c (check_match MATCH, no UNDEF, no data) |

## Not matched
| function | best | draft |
|---|---|---|
| cGameSound_PlaySound 0x1C8770 | 7 lab lines / 6 words, exact size (was 12 lines, 16 B short) | build/agents/Y1/ps_best7.c |
PlaySound remaining: priority-loop a1/a2 swap only (retail SR pointer a2 / fx a1). See NOTES.md for everything tried.

## New techniques
- **Implicit struct copy + later field uses:** an implicit copy reads source fields as `*(&src + off)`; a plain `obj.field`
  never CSEs with it. Read the field through a free inline taking `const T&` (`GH(vagFile)` returning `f.mHogFile`) and
  MW shares the copy's field address register with the later uses (PlaySound: 12 -> 7, exact size, alignment nops back).
  A member accessor or pointer local does not work.
- **Partial CSE via a named local:** when retail recomputes an address (`p + pos`) for a loop's strength-reduced pointer
  but shares it for the earlier uses, put the earlier uses on a named local (`q = base + at`) and keep the loop on the
  raw expression. `#pragma opt_common_subs off` is a quick probe: if it fixes exactly that window, the named local is the cure.
- **Retail `andi 0xff` after an lbu:** `int b = p[i] & 0xFF;` keeps it; `if (!p[i])` vs `== 0` changes colouring.
- **Two-statement accumulate** `v <<= 6; v += x;` gives the in-place `sll a3,a3,6; addu a3,a3,v1`.
- **Colouring:** a named iteration pointer gets coloured after a named derived pointer (r1.c), while a compiler SR temp is
  coloured before any named or inline local.
