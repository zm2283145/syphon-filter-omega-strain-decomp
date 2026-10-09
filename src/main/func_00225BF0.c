/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7578[];
extern char D_004F75E8[];
extern char D_004F75F0[];
extern char D_004FFB50[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int Service_Lookup(int, int);
extern int func_00225C20(int);
extern int func_00225C50(void);
extern int func_00225CD0(void);
extern int func_003CB1D0(void);
extern void func_003D9440(int, int);

void func_00225BF0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F75F0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00225C20(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_00225C40(void* self) {
    return self;
}

int func_00225C50(void) {
    return (int)D_004F75E8;
}

int func_00225C60(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00225C50();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_00225C80(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int func_00225CA0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00225CD0();
    tmp2 = func_00225C20(tmp0);
    return tmp2;
}

int func_00225CD0(void) {
    return Service_Lookup((int)D_004FFB50, (int)D_004F7578);
}
