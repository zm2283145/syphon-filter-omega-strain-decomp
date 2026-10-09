/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504040[];
extern char D_00504058[];
extern int ScalarCollection_Init(int);
extern int func_00241B70(int, int);
extern int func_003EEBE0(int, int, int);

int func_0027B900(int a0, int a1, int a2) {
    int tmp2;
    int tmp4;
    int tmp5;

    ScalarCollection_Init((a0 + 44));
    *(int*)((char*)a0 + 80) = 3658;
    tmp2 = func_00241B70(a2, a1);
    *(int*)((char*)a0) = tmp2;
    tmp4 = *(int*)(char*)a0;
    tmp5 = *(int*)(char*)tmp4;
    func_003EEBE0(tmp5, 0, 1);
    *(int*)((char*)a0 + 56) = 0;
    *(int*)((char*)a0 + 60) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0 + 28) = 0;
    *(int*)((char*)a0 + 32) = 0;
    *(int*)((char*)a0 + 20) = 0;
    *(int*)((char*)a0 + 40) = 0;
    *(char*)((char*)a0 + 84) = 0;
    *(char*)((char*)a0 + 85) = 0;
    *(char*)((char*)a0 + 86) = 0;
    *(char*)D_00504040 = 0;
    return a0;
}

int func_0027B9B0(void) {
    int tmp0;

    tmp0 = *(int*)D_00504058;
    return tmp0;
}
