/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int nciDecodeNeedsInputSase3200(int a0, int a1) {
    int tmp0;
    unsigned char tmp1;

    tmp0 = *(int*)((char*)a0 + 28);
    tmp1 = *(unsigned char*)((char*)tmp0 + 68);
    *(char*)((char*)a1) = tmp1;
    return 0;
}
