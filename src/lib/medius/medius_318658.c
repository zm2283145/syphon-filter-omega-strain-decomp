/*
 * lib/medius: 2 files, 00318658-003186E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00318658 */
typedef struct {
    char f00[0x10];
    char f10[0x10];
    int f20;
    int f24;
    int f28;
    int f2C;
} S_00318658;
extern S_00318658* (*D_004E1D34)(int n, int size);
extern void* (*D_004E1D3C)(void* d, int c, int n);
int func_00318658(S_00318658** pp)
{
    S_00318658* s;
    *pp = s = D_004E1D34(1, 0x30);
    if (!s) return 1;
    s->f2C = 0;
    s->f20 = 0;
    s->f24 = 0;
    s->f28 = 0;
    D_004E1D3C(s->f00, 0, 0x10);
    D_004E1D3C(s->f10, 0, 0x10);
    return 0;
}
/* merge_units: end func_00318658 */

/* merge_units: begin func_003186E0 */
#include "types.h"
#include "hook_free_ptr.h"

/* compiler: ee-gcc 2.96 -O2 */
/* Free a pointer through the hook and clear it. */
DEFINE_HOOK_FREE_PTR_RET0(func_003186E0)
/* merge_units: end func_003186E0 */
