/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceCdLayerSearchFile(int, int, int);

int sceCdSearchFile_2(int a0, int a1) {
    int tmp0;

    tmp0 = sceCdLayerSearchFile(a0, a1, 0);
    return tmp0;
}
