/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7960[];
extern void func_0022ED20(int);

int func_0022ED00(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    func_0022ED20(tmp0);
    return 0;
}

void func_0022ED20(int a0) {
    *(char*)D_004F7960 = a0;
}
