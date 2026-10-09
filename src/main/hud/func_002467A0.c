/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7D40[];
extern void func_002467C0(int);

int func_002467A0(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    func_002467C0(tmp0);
    return 0;
}

void func_002467C0(int a0) {
    *(char*)D_004F7D40 = a0;
}
