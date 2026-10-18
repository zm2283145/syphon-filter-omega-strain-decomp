/*
 * main/interface_element: range (2 files, 003E7EE0-003E8040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E7EE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1A]; unsigned char r, g, b, a; } O_E7EE0;
void IeElement_SetColour(O_E7EE0* o, float* c)
{
    unsigned char g = (unsigned int)(255.0f * c[1]);
    unsigned char b = (unsigned int)(255.0f * c[2]);
    unsigned char a = (unsigned int)(255.0f * c[3]);
    o->r = (unsigned int)(255.0f * c[0]);
    o->g = g;
    o->b = b;
    o->a = a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E7EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E7EE0 */

/* merge_units: begin func_003E8040 */
#pragma push /* merge_units */
typedef struct { __int128 a, b, c, d; } M_8040;
typedef struct { char pad[0x30]; M_8040 m; } S_8040;
#pragma peephole off
void IeElement_SetMatrix(S_8040* s, M_8040* m)
{
    M_8040* d = &s->m;
    __int128 t0, t1;
    t0 = m->a; t1 = m->b;
    d->a = t0; t0 = m->c;
    d->b = t1; t1 = m->d;
    d->c = t0;
    d->d = t1;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E8040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E8040 */
