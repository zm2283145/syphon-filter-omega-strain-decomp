/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC800(int);

int Script_GetGOBJ_AI(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return func_003CC800(tmp1);
}

int func_0016AB90(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)((char*)*(int*)((char*)*(int*)(char*)a0 + 48) + 56) ^ 128)));
}
