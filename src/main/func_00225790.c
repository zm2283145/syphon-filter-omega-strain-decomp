/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7668[];
extern char D_00555070[];
extern int func_002257A0(void);
extern int func_00225C40(int);
extern int func_00227C60(int);
extern int func_003E1AA0(int, int, int);

void* func_00225790(void* self) {
    return self;
}

int func_002257A0(void) {
    return (int)D_004F7668;
}

int func_002257B0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_002257A0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_002257D0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

int func_002257F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225C40(tmp0);
    func_00227C60(tmp1);
    return 0;
}
