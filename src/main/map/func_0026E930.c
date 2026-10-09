/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(v, value) */
int func_0026E930(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

Rel* func_0026E950(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
