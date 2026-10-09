/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055D4C8[];
extern char D_0055D4D0[];
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void ScriptType_cEnableMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_0055D4D0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int cEnableMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_0055D4C8;
    return tmp0;
}
