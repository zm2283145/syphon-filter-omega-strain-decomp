/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00269090(int);
extern int func_002690C0(int);

void func_00269070(void) {
}

int func_00269080(int a0) {
    return func_00269090(a0);
}

int func_00269090(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int func_002690B0(int a0) {
    return func_002690C0(a0);
}
