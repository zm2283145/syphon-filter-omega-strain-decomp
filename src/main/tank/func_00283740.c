/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506278[];
extern char D_00506280[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void func_00283740(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_00506280;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00283770(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00283790(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_002837B0(void* self) {
    return self;
}

void* func_002837C0(void* self) {
    return self;
}

int func_002837D0(void) {
    return (int)D_00506278;
}

int func_002837E0(void) {
    return (int)D_00506278;
}

int func_002837F0(void) {
    int tmp0;

    tmp0 = *(int*)D_00506278;
    return tmp0;
}

int func_00283800(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
