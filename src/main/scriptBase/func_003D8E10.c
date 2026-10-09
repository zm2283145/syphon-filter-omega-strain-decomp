/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);
extern OwnedVec* func_003D8E60(OwnedVec* v);

/* push_back: inserts one value at the end. */
int func_003D8E10(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

OwnedVec* func_003D8E30(OwnedVec* v) {
    func_003D8E60(v);
    v->unk0C = 1;
    return v;
}
