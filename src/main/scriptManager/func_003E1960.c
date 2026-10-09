/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern OwnedVec* func_003E19B0(OwnedVec* v);

/* Clears the three PtrVec words. */
OwnedVec* func_003E1960(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

OwnedVec* func_003E1980(OwnedVec* v) {
    func_003E19B0(v);
    v->unk0C = 1;
    return v;
}
