/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54D0[];
extern char D_004F55D8[];
extern char D_004F55E0[];
extern char D_004F5610[];
extern char D_004F5618[];
extern char D_004F5638[];
extern char D_004F5640[];
extern char D_004F5660[];
extern char D_004F5668[];
extern char D_00555070[];
extern int SoundAction_CtorVoice(int, int, int, int, int);
extern int func_00215530(int, int, int);
extern int func_002155F0(int, int, int);
extern int func_003C8C50(void);
extern int GObj_IdentityA(int);
extern void func_003D9440(int, int);
extern int ScriptFilter_Dispatch(int, int, int);
extern int Object_LookupById(int);

void func_00210AC0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F5668;
    tmp1 = *(int*)D_004F54D0;
    func_003D9440(tmp0, tmp1);
}

int func_00210AE0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5660;
    return tmp0;
}

int func_00210AF0(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int func_00210B10(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int PathedNotice_GetAction(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_00210B40(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F5640;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int PathedNotice_GetScriptType(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5638;
    return tmp0;
}

int func_00210B80(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00210BA0(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_00210BB0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F5618;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00210BE0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5610;
    return tmp0;
}

int func_00210BF0(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 44);
    a0 = (int)loc;
    *(int*)(char*)loc = v0;
    v0 = Object_LookupById(a0);
    a0 = v0;
    v0 = GObj_IdentityA(a0);
    goto ret;
ret:
    return v0;
}

int func_00210C20(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 48);
    a0 = (int)loc;
    *(int*)(char*)loc = v0;
    v0 = Object_LookupById(a0);
    a0 = v0;
    v0 = GObj_IdentityA(a0);
    goto ret;
ret:
    return v0;
}

int func_00210C50(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_00210C70(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_00210C80(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F55E0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00210CB0(void) {
    return (int)D_004F55D8;
}

int TriggerEvent_GetScriptType(void) {
    int tmp0;

    tmp0 = *(int*)D_004F55D8;
    return tmp0;
}

int func_00210CD0(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = func_00215530(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00210D00(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = func_002155F0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00210D30(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 736;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00210D70(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 1536;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00210DB0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 1136;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00210DF0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 336;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
