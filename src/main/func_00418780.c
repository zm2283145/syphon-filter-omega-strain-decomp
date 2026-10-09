/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0013BCB0(L4WordVec*, int);

int func_00418780(L4WordVec* v, int a1, int value) {
    int ret = func_0013BCB0(v, a1);

    v->unk0C = value;
    return ret;
}
