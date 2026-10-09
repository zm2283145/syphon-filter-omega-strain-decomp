/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Clears the three vector words. */
OwnedVec* func_003F1940(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* push_back: inserts one value at the end. */
int func_003F1960(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
