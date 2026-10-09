/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Model_GetChannelData(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (((a1 << 4) - a1) << 2));
}
