/*
 * SFOGame/Source/humanCollision: 2 files, 001EEDC0-001EEEC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EEDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DAD40[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cFoundLedgeMsg_Clone(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)cMemMan_Allocate(0, 0x28, "foundLedgeMsg.hh", 0x21);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004DAD40;
        p->w24 = self->w24;
    }
    return p;
}
static inline void merge_flush_func_001EEDC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EEDC0 */

/* merge_units: begin func_001EEEC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E1EEEC0 { int w[4]; };
struct V1EEEC0 { int capacity; int count; E1EEEC0* data; };
extern "C" void cEdgeGroup_dtor(E1EEEC0* e, int flags);
extern "C" void std_vector_deleter_cEdgeGroup_clear(V1EEEC0* v)
{
    E1EEEC0* first = v->data;
    E1EEEC0* last = first + v->count;
    while (first < last) {
        --last;
        cEdgeGroup_dtor(last, -1);
    }
    v->count = 0;
}
static inline void merge_flush_func_001EEEC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EEEC0 */
