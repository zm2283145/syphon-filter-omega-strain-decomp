/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Reads unk004 into out; returns 5 on a null obj. */
int func_00310D00(RtObj210* obj, int* out) {
    int result = 5;

    if (obj != 0) {
        result = 0;
        *out = obj->unk004;
    }
    return result;
}

/* Reads unk210 into out; returns 5 on a null obj. */
int func_00310D20(RtObj210* obj, int* out) {
    int result = 5;

    if (obj != 0) {
        result = 0;
        *out = obj->unk210;
    }
    return result;
}
