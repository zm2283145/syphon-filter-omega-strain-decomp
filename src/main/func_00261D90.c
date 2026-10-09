/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F8310[];
extern char D_004F8318[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void ScriptType_cFireObj_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F8318;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int cFireObj_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004F8310;
    return tmp0;
}

int cFireObj_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
