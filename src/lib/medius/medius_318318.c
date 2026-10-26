/*
 * lib/medius: 2 files, 00318318-00318348
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00318318 */
#include "types.h"
typedef struct { char pad0[0x20]; short x; short y; char pad24[4]; short dirty; } S318318B;
typedef struct { char pad0[0x48]; S318318B* b; } S318318A;
void NellySetSpectralFactorSase3200(S318318A* a, float v)
{
    S318318B* b = a->b;
    b->dirty = 1;
    b->x = v / 15.625f;
}
/* merge_units: end func_00318318 */

/* merge_units: begin func_00318348 */
typedef struct { char pad0[0x20]; short x; short y; char pad24[4]; short dirty; } S318348B;
typedef struct { char pad0[0x48]; S318348B* b; } S318348A;
void NellySetSpectralLedgeSase3200(S318348A* a, float v)
{
    S318348B* b = a->b;
    b->dirty = 1;
    b->y = v / 15.625f;
}
/* merge_units: end func_00318348 */
