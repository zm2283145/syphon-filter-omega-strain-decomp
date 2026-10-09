/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005721C8[];

unsigned char func_001B8740(unsigned char* self) {
    return self[13220];
}

void func_001B8750(int a0, int a1) {
    int v1;
    int cond;

    *(char*)(char*)(a0 + 13220) = a1;
    v1 = *(unsigned char*)(char*)D_005721C8;
    cond = v1 == 0;
    if (cond) goto L001B8780;
    v1 = *(unsigned char*)(char*)(a0 + 20);
    cond = v1 == 0;
    if (cond) goto L001B8780;
    v1 = *(int*)(char*)(a0 + 13700);
    cond = v1 == 0;
    if (cond) goto L001B8780;
    *(char*)(char*)(v1 + 52) = a1;
L001B8780:;
    goto ret;
ret:;
}
