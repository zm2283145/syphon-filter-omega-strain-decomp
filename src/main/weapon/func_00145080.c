/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA158[];
extern char D_004EA160[];
extern int func_001450C0(void);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void func_00145080(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004EA160;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

void* func_001450B0(void* self) {
    return self;
}

int func_001450C0(void) {
    return (int)D_004EA158;
}

int func_001450D0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_001450C0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}
