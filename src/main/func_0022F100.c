/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7A20[];
extern char D_004F7A28[];
extern char D_004F7A38[];
extern char D_004F7A40[];
extern char D_00555070[];
extern int GObj_IdentityA(int);
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_003C8C50(void);
extern int func_003CB1D0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_0043FB90(void);

int Script_cGameGobjController_Gobj(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return GObj_IdentityA(tmp1);
}

int ScriptType_cGameGobjController_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp12;
    int tmp13;
    int tmp14;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F7A40;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_0043FB90();
    tmp8 = *(int*)D_004F7A40;
    tmp9 = *(int*)(char*)tmp6;
    func_003D9400(tmp8, tmp9);
    tmp12 = *(int*)D_004F7A40;
    tmp13 = *(int*)D_004F7A20;
    tmp14 = func_003D9400(tmp12, tmp13);
    return tmp14;
}

int func_0022F170(void) {
    return (int)D_004F7A38;
}

int func_0022F180(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7A38;
    return tmp0;
}

int func_0022F190(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Script_cTimerExpiredMsg_IsPersonal(int a0) {
    return ((unsigned int)(0) < (unsigned int)(*(int*)((char*)*(int*)(char*)a0 + 36)));
}

void ScriptType_cTimerExpiredMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7A28;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022F1F0(void) {
    return (int)D_004F7A20;
}

int cTimerExpiredMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7A20;
    return tmp0;
}
