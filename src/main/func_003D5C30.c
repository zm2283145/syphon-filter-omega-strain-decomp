/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001004B0(int, int, int, int, int);
extern int func_003D5AA0(int, int);
extern int func_003D5CD0(int);

int func_003D5C30(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(short*)((char*)a0 + 12) = -1;
    return a0;
}

int func_003D5C50(int a0) {
    int v0, v1;

    *(int*)(char*)a0 = 0;
    v1 = 0x3f800000;
    *(int*)(char*)(a0 + 100) = 0;
    v0 = a0;
    *(int*)(char*)(a0 + 112) = 0;
    *(int*)(char*)(a0 + 116) = 0;
    *(int*)(char*)(a0 + 120) = 0;
    *(int*)(char*)(a0 + 124) = v1;
    goto ret;
ret:
    return v0;
}

int func_003D5C80(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    func_001004B0((a0 + 16), (int)func_003D5CD0, (int)func_003D5AA0, 48, 6);
    return a0;
}

int func_003D5CD0(int a0) {
    int v0, v1;

    *(char*)(char*)a0 = 0;
    v1 = 0x3f800000;
    *(int*)(char*)(a0 + 4) = 0;
    v0 = a0;
    *(int*)(char*)(a0 + 16) = 0;
    *(int*)(char*)(a0 + 20) = 0;
    *(int*)(char*)(a0 + 24) = 0;
    *(int*)(char*)(a0 + 28) = v1;
    *(int*)(char*)(a0 + 32) = 0;
    *(int*)(char*)(a0 + 36) = 0;
    *(int*)(char*)(a0 + 40) = 0;
    *(int*)(char*)(a0 + 44) = 0;
    goto ret;
ret:
    return v0;
}
