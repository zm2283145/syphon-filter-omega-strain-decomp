/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002071B0(int);
extern void func_00207200(void);

int func_002071C0(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = func_002071B0(a0);
    tmp2 = *(int*)(char*)tmp0;
    return ((unsigned int)(0) < (unsigned int)((tmp2 & 1)));
}

void func_002071F0(void) {
    func_00207200();
}
