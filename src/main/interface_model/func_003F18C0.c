/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern OwnedVec* func_003F1940(OwnedVec* v);
extern int func_003F3370(RawVec* v, char* pos, int n, int value);
extern int func_003F3900(int a0, int a1);

/* Clears the three vector words. */
OwnedVec* func_003F18C0(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

/* push_back on a vector of 16-byte elements. */
int func_003F18E0(RawVec* v, int value) {
    return func_003F3370(v, v->data + (v->count << 4), 1, value);
}

int func_003F1900(int a0, int a1) {
    return func_003F3900(a0, a1);
}

OwnedVec* func_003F1910(OwnedVec* v) {
    func_003F1940(v);
    v->unk0C = 1;
    return v;
}
