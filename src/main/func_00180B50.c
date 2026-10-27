/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void cGOBJ_SetRotation(int);

void cGameCamera_SetRotation(int a0) {
    cGOBJ_SetRotation(a0);
}
