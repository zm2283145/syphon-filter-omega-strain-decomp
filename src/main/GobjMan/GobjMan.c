/*
 * main/GobjMan: 3 files, 0040C080-0040C120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040C080 */
#pragma push /* merge_units */
#include "types.h"
#include "GobjMan_types.h"

extern GobjEntry* ObjRegistry_Find(GobjScope* scope, const GobjId* id);

/*
 * Returns the object registered under id if it is visible from scope (its
 * scope chain reaches scope), otherwise null.
 */
GobjEntry* IdMgr_IsOccupied(GobjScope* scope, const GobjId* id) {
    GobjScope* s;
    GobjEntry* obj;

    obj = ObjRegistry_Find(scope, id);
    if (obj != 0) {
        s = obj->scope;
        if (s != 0) {
loop:
            if (s == scope) {
                return obj;
            }
            s = s->parent;
            if (s == 0) {
                goto none;
            }
            goto loop;
        }
    }
none:
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C080 */

/* merge_units: begin func_0040C0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: iterator helpers for a scope's id vector (GobjScope.ids).
 */


/* Iterator inequality. */
int IdVecIter_Ne(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* end() iterator of the id vector. */
void IdVec_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C0E0 */

/* merge_units: begin func_0040C120 */
#pragma push /* merge_units */
#pragma bool off
extern int** IdVec_DataRef(PtrVec* v);
static inline int IdIter_Ne(int* a, int* b) { return (a == b) ^ 1; }
/* Finds the id word *id in the vector; stores its iterator (end() if absent). */
void IdVec_Find(int** out, PtrVec* v, int* id) {
    int* it = *IdVec_DataRef(v);
    int* end = *IdVec_DataRef(v) + v->count;
    while (IdIter_Ne(it, end)) {
        if (*it == *id) {
            *out = it;
            return;
        }
        it++;
    }
    *out = end;
}
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_0040C120 */