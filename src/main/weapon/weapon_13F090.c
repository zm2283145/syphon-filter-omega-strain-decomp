/*
 * main/weapon: 3 files, 0013F090-0013F1A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013F090 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int m0; void* m4; } TB5C0;
extern void std_tree_pair_float_value_compare_destroy(TB5C0* t, void* n);
extern void operator_delete(void* p);
TB5C0* cAssocMultiArray_float_cGOBJPtr_dtor(TB5C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_float_value_compare_destroy(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F090 */

/* merge_units: begin func_0013F100 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern void Tree_Successor(Iter* it);

int cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocMultiArray_float_cGOBJPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* ++it on a tree iterator. */
Iter* TreeIter_Increment(Iter* it) {
    Tree_Successor(it);
    return it;
}

/* Value part of the current tree node (+0x10). */
char* cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(Iter16* it) {
    return it->p + 16;
}

void cAssocMultiArray_float_cGOBJPtr_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* Build a (float, int) pair from pointers. */
FloatIntPair* std_pair_float_cGOBJPtr_ctor(FloatIntPair* p, float* f, int* i) {
    p->f = *f;
    p->i = *i;
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F100 */

/* merge_units: begin func_0013F1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "vslot_pad.h"
class R_F1A0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ren_F1A0 { unsigned int f0; char pad4[0x20]; unsigned int f24; };
struct Obj_F1A0 { char pad[0x49]; unsigned char kind; char pad4a[0xE]; R_F1A0* recv; char pad5c[0xC]; Ren_F1A0* ren; };
struct List_F1A0 { int n; Obj_F1A0* items[1]; };
extern "C" {
extern char D_00543790[];
extern unsigned char g_IsMultiplayer;
void Shadow_AddReceiver(void* mgr, Obj_F1A0* o, int flag);
void Shadow_AddCaster(void* mgr, Obj_F1A0* o, int mode);
}
extern "C" void Shadow_RegisterReceiver(List_F1A0* list)
{
    Obj_F1A0** p;
    for (p = list->items; p != list->items + list->n; p++) {
        Obj_F1A0* o = *p;
        if (o->kind == 1) {
            Ren_F1A0* r = o->ren;
            if (r->f24 & 0x60) { unsigned char v = r->f0 != 0; if (v)
                Shadow_AddReceiver(D_00543790, o, 0); }
        } else if (o->kind == 2) {
            Obj_F1A0* c = o;
            unsigned char local = 0;
            R_F1A0* rc = c->recv;
            if (rc && rc->IsLocal())
                local = 1;
            if (g_IsMultiplayer) {
                if (local)
                    Shadow_AddCaster(D_00543790, c, 2);
            } else if (local) {
                Shadow_AddCaster(D_00543790, c, 2);
            } else {
                Shadow_AddCaster(D_00543790, c, 1);
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F1A0 */
