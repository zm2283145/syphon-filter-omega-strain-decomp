/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004EE5C8[];
extern int func_003C9E30(int, int);

int func_0016B4F0(int a0, int a1, int a2, float f12, float f13) {
    int tmp2;

    func_003C9E30(a0, (int)D_004EE5C8);
    *(int*)((char*)a0) = (int)D_004D92A0;
    *(char*)((char*)a0 + 36) = 0;
    *(char*)((char*)a0 + 37) = a2;
    *(float*)((char*)a0 + 40) = f12;
    *(float*)((char*)a0 + 44) = f13;
    *(int*)((char*)a0) = (int)D_004D92C0;
    tmp2 = *(int*)(char*)a1;
    *(int*)((char*)a0 + 48) = tmp2;
    return a0;
}
