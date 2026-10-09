/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00584240[];
extern char D_00584241[];
extern char D_005842C8[];
extern char D_005842CC[];
extern int func_002EBC48(int);

int func_00444020(int a0) {
    *(char*)D_005842C8 = a0;
    return func_002EBC48((int)D_005842CC);
}

void func_00444040(int a0) {
    *(char*)D_00584241 = a0;
}

void func_00444050(int a0) {
    *(char*)D_00584240 = a0;
}

int func_00444060(void) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)D_00584240;
    return tmp0;
}
