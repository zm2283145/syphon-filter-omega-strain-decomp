/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC820(int);
extern int func_0045E730(int);
extern void func_0045EC60(void);

int func_0045E5F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003CC820(tmp0);
    func_0045E730(tmp1);
    return 0;
}

int func_0045E620(void) {
    func_0045EC60();
    return 0;
}
