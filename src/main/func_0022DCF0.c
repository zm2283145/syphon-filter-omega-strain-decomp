/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F79A0[];
extern char D_004F79A8[];
extern char D_004F79B0[];
extern char D_004F79B8[];
extern char D_004F79C0[];
extern char D_004F79C8[];
extern char D_004F79D0[];
extern char D_004F79D8[];
extern char D_00555070[];
extern int func_0022DD20(void);
extern int func_0022DDA0(void);
extern int func_0022DE00(void);
extern int func_0022DE60(void);
extern int func_0022DED0(int, int);
extern int func_003C8C50(void);
extern int func_003CC820(int);
extern int func_003CC830(void);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_0022DCF0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F79D8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DD20(void) {
    return (int)D_004F79D0;
}

int func_0022DD30(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DD20();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_0022DD50(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

void func_0022DD70(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79C8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DDA0(void) {
    return (int)D_004F79C0;
}

int func_0022DDB0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DDA0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

void func_0022DDD0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79B8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DE00(void) {
    return (int)D_004F79B0;
}

int func_0022DE10(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DE00();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

void func_0022DE30(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79A8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DE60(void) {
    return (int)D_004F79A0;
}

int func_0022DE70(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DE60();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_0022DE90(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_003CC820(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = func_0022DED0(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
