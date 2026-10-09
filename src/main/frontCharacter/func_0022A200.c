/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "frontCharacter_types.h"

extern int func_0022A360(FcVec* v, int* pos, int n, int value);  /* vector insert */

/* push_back(v, value) */
int func_0022A200(FcVec* v, int value) {
    return func_0022A360(v, v->data + v->count, 1, value);
}
