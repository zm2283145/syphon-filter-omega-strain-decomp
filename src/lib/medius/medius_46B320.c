/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497CF0[];

int MediusGetLastNetUpdateError(void) {
    int tmp0;

    tmp0 = *(int*)D_00497CF0;
    return tmp0;
}
