/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFC10[];
extern int Vec4_Assign(int, int);
extern int func_003B2950(int, int, int, int, int);

int func_001F0540(int a0, int a1, int a2, int a3, int t0, float f12, float f13) {
    func_003B2950(a0, 1, a2, 0, t0);
    *(int*)((char*)a0) = (int)D_004DFC10;
    *(int*)((char*)a0 + 80) = a1;
    *(float*)((char*)a0 + 84) = f12;
    *(float*)((char*)a0 + 88) = f13;
    Vec4_Assign((a0 + 96), a3);
    return a0;
}
