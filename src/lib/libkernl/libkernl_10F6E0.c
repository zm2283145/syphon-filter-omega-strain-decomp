/*
 * lib/libkernl: 2 files, 0010F6E0-0010F718
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010F6E0 */
extern int DisableDmac(int a);
extern int RemoveDmacHandler(int a, int b);
extern int D_004E2D54;
extern int D_004861A8;
int func_0010F6E0(void)
{
    int r;
    DisableDmac(5);
    r = RemoveDmacHandler(5, D_004E2D54);
    D_004861A8 = 0;
    return r;
}
/* merge_units: end func_0010F6E0 */

/* merge_units: begin func_0010F718 */
#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { char pad[0x14]; int a; int b; } State;
extern State D_004E2D58;

/* Replaces the (a, b) pair in a global state and returns the previous a. */
int func_0010F718(int a, int b)
{
    int old = D_004E2D58.a;
    D_004E2D58.a = a;
    D_004E2D58.b = b;
    return old;
}
/* merge_units: end func_0010F718 */
