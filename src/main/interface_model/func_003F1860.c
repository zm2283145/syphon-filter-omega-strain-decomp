/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern OwnedVec* func_003F18C0(OwnedVec* v);
extern int func_003F24A0(RawVec* v, char* pos, int n, int value);
extern int func_003F29B0(int a0, int a1);

/* push_back on a vector of 8-byte elements. */
int func_003F1860(RawVec* v, int value) {
    return func_003F24A0(v, v->data + (v->count << 3), 1, value);
}

int func_003F1880(int a0, int a1) {
    return func_003F29B0(a0, a1);
}

OwnedVec* func_003F1890(OwnedVec* v) {
    func_003F18C0(v);
    v->unk0C = 1;
    return v;
}
