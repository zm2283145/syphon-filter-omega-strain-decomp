/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00245EE0(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
