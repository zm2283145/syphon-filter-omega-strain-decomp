/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void cScriptInterpreter_ExecuteInitCode(int);
extern int func_003E1520(int);

int Script_cScriptInterp_ExecuteInitCode(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003E1520(tmp0);
    cScriptInterpreter_ExecuteInitCode(tmp1);
    return 0;
}

void func_003E1510(void) {
}
