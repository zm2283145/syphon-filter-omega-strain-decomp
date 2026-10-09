/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7668[];
extern char D_004F7670[];
extern char D_00555070[];
extern int func_002257A0(void);
extern int func_00225C40(int);
extern int ObjMan_SetDisplayLabel(int, int, int, int);
extern int ObjMan_DeleteAll(int);
extern int func_003CB1D0(void);
extern int GObj_IdentityB(int);
extern void func_003D9440(int, int);
extern int ScriptFilter_Dispatch(int, int, int);

void func_00225740(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F7670;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00225770(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* Objective_ResolveReceiver(void* self) {
    return self;
}

int func_002257A0(void) {
    return (int)D_004F7668;
}

int func_002257B0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_002257A0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int Objective_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int func_002257F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225C40(tmp0);
    ObjMan_DeleteAll(tmp1);
    return 0;
}

int ObjMan_ScriptSetDisplayLabelObj(int a0) {
    int loc[1];
    int a1, a2, a3, s0, s1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    s0 = a0;
    *(int*)(char*)loc = v0;
    s1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = s1;
    a2 = v0;
    a3 = 0;
    v0 = ObjMan_SetDisplayLabel(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int ObjMan_ScriptSetDisplayLabel(int a0) {
    int loc[1];
    int a1, a2, a3, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    a3 = 0;
    v0 = ObjMan_SetDisplayLabel(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
