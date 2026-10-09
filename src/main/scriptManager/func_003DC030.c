/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

int* func_003DC030(PtrVec* v, int i) {
    return v->data + i;
}

/* push_back: inserts one value at the end. */
int func_003DC040(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

int* func_003DC060(PtrVec* v, int i) {
    return v->data + i;
}

int* func_003DC070(PtrVec* v, int i) {
    return v->data + i;
}
