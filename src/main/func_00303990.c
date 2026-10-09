/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets unk188 (at most 256); returns 2 on a bad argument. */
int func_00303990(RtObj188* obj, unsigned int value) {
    int inRange = value < 257;
    int result = 2;

    if (obj != 0 && inRange) {
        obj->unk188 = value;
        result = 0;
    }
    return result;
}
