/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float cNPC_v59(int a0, float f12) {
    float tmp0;

    tmp0 = *(float*)((char*)a0 + 120);
    *(float*)((char*)a0 + 120) = f12;
    return tmp0;
}
