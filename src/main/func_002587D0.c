/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7EB8[];
extern char D_004F7EC0[];
extern int GObj_IdentityA(int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int Script_cCrateInteractMsg_Who(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 44);
    return GObj_IdentityA(tmp1);
}

int Script_cCrateInteractMsg_Taken(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 36);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_cCrateInteractMsg_Given(int a0) {
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

void ScriptType_cCrateInteractMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7EC0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int cCrateInteractMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7EB8;
    return tmp0;
}
