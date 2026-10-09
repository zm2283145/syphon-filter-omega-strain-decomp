/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7E58[];
extern int func_002472E0(int);
extern int func_003C8C50(void);
extern int func_003CB1A0(int);
extern void func_003D9440(int, int);

int Script_cMenuChoiceMsg_Who(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_002472E0(tmp0);
    tmp3 = *(int*)((char*)tmp1 + 36);
    tmp4 = func_003CB1A0(tmp3);
    return tmp4;
}

int Script_cMenuChoiceMsg_Choice(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_002472E0(a0);
    v0 = *(int*)((char*)v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void ScriptType_cMenuChoiceMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7E58;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
