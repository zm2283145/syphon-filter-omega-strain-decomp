/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F83F8[];
extern char D_00555070[];
extern int func_00269830(void);
extern int func_003E1AA0(int, int, int);

void* func_00269810(void* self) {
    return self;
}

int func_00269820(void) {
    return func_00269830();
}

int func_00269830(void) {
    return (int)D_004F83F8;
}

int func_00269840(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00269830();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int func_00269860(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
