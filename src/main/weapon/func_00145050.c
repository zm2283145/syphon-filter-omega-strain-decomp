/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA160[];
extern int func_001450B0(int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int Script_cOutOfAmmoMsg_Weapon(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_001450B0(a0);
    v0 = *(int*)((char*)v0 + 36);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void ScriptType_cOutOfAmmoMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004EA160;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
