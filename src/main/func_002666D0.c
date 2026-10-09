/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int PtrVec_Insert(PtrVec*, int*, int, int*);

/* push_back */
int func_002666D0(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

Rel* func_002666F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void func_00266710(PtrVec* v) {
    v->count = 0;
}
