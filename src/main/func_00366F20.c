/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int AnimChannelBase_CopyCtor(int, int);
extern char D_004DA840[];

int func_00366F20(int a0, int a1) {
    unsigned char tmp2;

    AnimChannelBase_CopyCtor(a0, a1);
    *(int*)((char*)a0) = (int)D_004DA840;
    tmp2 = *(unsigned char*)((char*)a1 + 56);
    *(char*)((char*)a0 + 56) = tmp2;
    return a0;
}
