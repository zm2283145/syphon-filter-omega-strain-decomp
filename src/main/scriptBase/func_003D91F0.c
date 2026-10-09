/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);
extern OwnedVec* func_003D9240(OwnedVec* v);

/* push_back: inserts one value at the end. */
int func_003D91F0(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

OwnedVec* func_003D9210(OwnedVec* v) {
    func_003D9240(v);
    v->unk0C = 1;
    return v;
}
