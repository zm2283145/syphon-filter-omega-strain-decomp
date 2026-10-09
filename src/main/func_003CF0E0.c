/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFF50[];
extern int func_003CB090(int, int);

int func_003CF0E0(int a0, int a1, int a2, int a3) {
    int tmp2;
    int tmp3;

    func_003CB090(a0, a1);
    *(int*)((char*)a0) = (int)D_004DFF50;
    *(char*)((char*)a0 + 44) = 1;
    *(char*)((char*)a0 + 45) = 0;
    *(char*)((char*)a0 + 46) = 0;
    *(char*)((char*)a0 + 47) = 0;
    *(int*)((char*)a0 + 48) = -1;
    *(int*)((char*)a0 + 56) = 128;
    *(int*)((char*)a0 + 60) = 0;
    *(int*)((char*)a0 + 64) = 0;
    *(int*)((char*)a0 + 68) = 0;
    *(char*)((char*)a0 + 72) = 0;
    *(char*)((char*)a0 + 73) = a2;
    tmp2 = *(int*)(char*)a3;
    *(int*)((char*)a0 + 76) = tmp2;
    *(int*)((char*)a0 + 80) = 0;
    *(int*)((char*)a0 + 84) = 0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 92) = 0;
    tmp3 = *(int*)(char*)a1;
    *(int*)((char*)a0 + 16) = tmp3;
    return a0;
}
