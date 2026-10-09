/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA778[];
extern char D_004EA780[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void func_0015C080(void) {
}

int func_0015C090(void) {
    return 1;
}

int func_0015C0A0(void) {
    return 0;
}

int Script_cNode_IsType(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(unsigned short*)((char*)a0 + 4) & *(int*)((char*)*(int*)(char*)a0 + 100))));
}

void ScriptType_cNode_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004EA780;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0015C100(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_0015C120(void* self) {
    return self;
}

int func_0015C130(void) {
    return (int)D_004EA778;
}

int cNode_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004EA778;
    return tmp0;
}

int cNode_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
