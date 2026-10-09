/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7578[];
extern char D_004F75E8[];
extern char D_004FFB50[];
extern char D_00555070[];
extern int func_00225C20(int);
extern int func_00225C50(void);
extern int func_00225CD0(void);
extern int func_003CAA50(int, int);
extern int func_003E1AA0(int, int, int);

void* func_00225C40(void* self) {
    return self;
}

int func_00225C50(void) {
    return (int)D_004F75E8;
}

int func_00225C60(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00225C50();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_00225C80(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

int func_00225CA0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00225CD0();
    tmp2 = func_00225C20(tmp0);
    return tmp2;
}

int func_00225CD0(void) {
    return func_003CAA50((int)D_004FFB50, (int)D_004F7578);
}
