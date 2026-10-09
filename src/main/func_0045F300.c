/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_004147A0(void);
extern void func_00414AC0(int, int, int);
extern int func_0041EFA0(int);
extern int func_00441A10(int);

void func_0045F300(int a0) {
    int tmp0;

    tmp0 = func_004147A0();
    func_00414AC0(tmp0, a0, 0);
}

int func_0045F340(int a0) {
    int tmp2;

    func_0041EFA0(a0);
    *(char*)((char*)a0 + 76) = 2;
    tmp2 = func_00441A10(a0);
    return tmp2;
}
