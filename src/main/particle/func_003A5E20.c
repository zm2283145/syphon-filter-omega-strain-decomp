/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003A5E30(int, int, float, float, float);

void func_003A5E20(int a0, int a1, int a2) {
    float tmp0;
    float tmp1;
    float tmp2;

    tmp0 = *(float*)((char*)a2 + 4);
    tmp1 = *(float*)((char*)a2 + 8);
    tmp2 = *(float*)(char*)a2;
    func_003A5E30(a0, a1, tmp2, tmp0, tmp1);
}
