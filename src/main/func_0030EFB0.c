/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets unk5C; returns 2 on a null argument. */
int func_0030EFB0(RtObj5C* obj, int value) {
    int result = 2;

    if (obj != 0 && value != 0) {
        obj->unk5C = value;
        result = 0;
    }
    return result;
}
