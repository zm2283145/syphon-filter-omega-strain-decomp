/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int func_001E12E0(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

Rel* func_001E1300(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_001E1320(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* func_001E1340(Iter16* it) {
    it->p += 16;
    return it;
}

/* push_back(value). */
int func_001E1360(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

/* clear(): count = 0. */
void func_001E1380(PtrVec* v) {
    v->count = 0;
}
