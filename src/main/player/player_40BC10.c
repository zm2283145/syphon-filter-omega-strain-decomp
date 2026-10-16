/*
 * main/player: 2 files, 0040BC10-0040BC50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040BC10 */
#pragma push /* merge_units */
#include "types.h"
static inline Iter Iter_Make(int* p) { Iter it; it.p = p; return it; }
/* Stores an iterator to the end of the vector into out. */
void func_0040BC10(Iter* out, PtrVec* v) { Iter it = Iter_Make(v->data + v->count); out->p = it.p; }
#pragma pop /* merge_units */
/* merge_units: end func_0040BC10 */

/* merge_units: begin func_0040BC50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int value);
extern int PtrVector_Resize(PtrVec* v, int a1, int a2);
extern int PtrVec_Reserve(int, int);

int func_0040BC50(PtrVec* v, int a1, int a2) {
    return PtrVector_Resize(v, a1, a2);
}

int func_0040BC60(PtrVec* v) {
    return v->count;
}

/* push_back: inserts one value at end(). */
int PtrVec_PushBack_40BC70(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

int func_0040BC90(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_0040BCA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040BC50 */
