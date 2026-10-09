/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE700[];
extern char D_004EE708[];
extern int GObj_IdentityA(int);
extern int GObj_IdentityB(int);
extern int Global_MakeGOBJInteractable(int);
extern int Global_MakeNPCInteractable(int);
extern int func_0014A690(int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int Script_cHotboxMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return GObj_IdentityA(tmp1);
}

int Script_cHotboxMsg_Action(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void ScriptType_cHotboxMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004EE708;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int cHotboxMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE700;
    return tmp0;
}

int Script_MakeNPCInteractable(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_0014A690(a0);
    a0 = v0;
    v0 = Global_MakeNPCInteractable(a0);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_MakeGOBJInteractable(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a0 = v0;
    v0 = Global_MakeGOBJInteractable(a0);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
