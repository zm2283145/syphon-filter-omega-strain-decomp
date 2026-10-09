/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE898[];
extern char D_004EE8D8[];
extern char D_004EE8E0[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern void func_003D9440(int, int);

void func_00179000(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004EE8E0;
    tmp1 = *(int*)D_004EE898;
    func_003D9440(tmp0, tmp1);
}

int func_00179020(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE8D8;
    return tmp0;
}

int func_00179030(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
