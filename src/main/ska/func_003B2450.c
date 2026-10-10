#include "types.h"

int func_003B2450(int a0) {
    int v0, v1;
    float f0, f1;
    int cond, fcc;

    f1 = *(float*)((char*)a0 + 12);
    v1 = 0x3f800000;
    f0 = 1.0f;
    fcc = f0 == f1;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003B2470;
    v0 = 0;
L003B2470:;
    goto ret;
ret:
    return v0;
}
