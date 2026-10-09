/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int value);
extern int PtrVector_Resize(PtrVec* v, int a1, int a2);
extern int func_001396D0(int, int);

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
    return func_001396D0(a0, a1);
}

Rel* func_0040BCA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
