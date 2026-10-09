/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA158[];
extern int func_001450C0(void);

void* func_001450B0(void* self) {
    return self;
}

int func_001450C0(void) {
    return (int)D_004EA158;
}

int cOutOfAmmoMsg_v03(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_001450C0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}
