/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001BE960(int, int, int);

void* func_00198BC0(char* self) {
    return self + 232;
}

int func_00198BD0(char* self) {
    return *(int*)(self + 16);
}

void func_00198BE0(int a0, int a1) {
    int loc[8];
    int a2, s0, v0, v1;

    a2 = *(int*)(char*)(a1 + 20);
    s0 = a0;
    a0 = (int)loc;
    v0 = func_001BE960(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    v1 = *(int*)((char*)loc + 4);
    *(int*)(char*)(s0 + 4) = v1;
    v1 = *(int*)((char*)loc + 8);
    *(int*)(char*)(s0 + 8) = v1;
    v1 = *(int*)((char*)loc + 12);
    *(int*)(char*)(s0 + 12) = v1;
    v1 = *(int*)((char*)loc + 16);
    *(int*)(char*)(s0 + 16) = v1;
    v1 = *(int*)((char*)loc + 20);
    *(int*)(char*)(s0 + 20) = v1;
    goto ret;
ret:;
}

void func_00198C40(int a0) {
    int loc[8];
    int a1, a2, s0, v0, v1;

    a2 = 0;
    s0 = a0;
    a0 = (int)loc;
    v0 = func_001BE960(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    v1 = *(int*)((char*)loc + 4);
    *(int*)(char*)(s0 + 4) = v1;
    v1 = *(int*)((char*)loc + 8);
    *(int*)(char*)(s0 + 8) = v1;
    v1 = *(int*)((char*)loc + 12);
    *(int*)(char*)(s0 + 12) = v1;
    v1 = *(int*)((char*)loc + 16);
    *(int*)(char*)(s0 + 16) = v1;
    v1 = *(int*)((char*)loc + 20);
    *(int*)(char*)(s0 + 20) = v1;
    goto ret;
ret:;
}
