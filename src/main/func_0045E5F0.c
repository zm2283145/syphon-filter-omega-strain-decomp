/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC820(int);
extern int func_0045E730(int);
extern int func_0045E930(int, int, int);
extern void func_0045EC60(void);
extern void func_0045ED00(int, int);

int func_0045E5F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003CC820(tmp0);
    func_0045E730(tmp1);
    return 0;
}

int func_0045E620(void) {
    func_0045EC60();
    return 0;
}

int func_0045E640(int a0) {
    int loc[1];
    int a1, a2, s0, v0;

    s0 = *(unsigned char*)(char*)(a0 + 8);
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_003CC820(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = s0;
    v0 = func_0045E930(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0045E690(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_003CC820(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0 + 1;
    v0 = func_0045E930(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0045E6D0(int a0) {
    int loc[1];
    int a1, v0;

    a1 = *(unsigned char*)(char*)(a0 + 4);
    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    func_0045ED00(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0045E700(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    a1 = 0 + 1;
    func_0045ED00(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
