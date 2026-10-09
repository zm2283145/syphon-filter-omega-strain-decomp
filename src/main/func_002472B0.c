/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7E50[];
extern char D_004F7E58[];
extern int func_002472F0(void);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void func_002472B0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7E58;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

void* func_002472E0(void* self) {
    return self;
}

int func_002472F0(void) {
    return (int)D_004F7E50;
}

int func_00247300(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_002472F0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}
