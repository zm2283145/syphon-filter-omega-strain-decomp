/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00198D00(int, int);
extern int func_00198E90(int);
extern int func_00198F70(int);

void* func_00198F20(void* self) {
    return self;
}

int func_00198F30(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_00198F70(a0);
    tmp2 = func_00198D00(tmp0, a1);
    return ((unsigned int)(0) < (unsigned int)(tmp2));
}

int func_00198F70(int a0) {
    int tmp0;

    tmp0 = func_00198E90((a0 + 60));
    return (tmp0 + 232);
}
