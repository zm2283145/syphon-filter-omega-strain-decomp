/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

/* Clears the three PtrVec words. */
OwnedVec* func_003DF3D0(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int* func_003DF3F0(PtrVec* v, int i) {
    return v->data + i;
}
