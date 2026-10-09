/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE700[];
extern char D_004EE738[];
extern char D_004EE740[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_003CC830(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);

int func_0016FDF0(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp8;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004EE740;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = *(int*)D_004EE740;
    tmp7 = *(int*)D_004EE700;
    tmp8 = func_003D9400(tmp6, tmp7);
    return tmp8;
}

void* func_0016FE30(void* self) {
    return self;
}

int func_0016FE40(void) {
    return (int)D_004EE738;
}

int func_0016FE50(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE738;
    return tmp0;
}

int func_0016FE60(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
