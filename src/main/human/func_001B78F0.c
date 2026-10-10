#include "types.h"

int func_001B78F0(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001B7908;
    *(int*)(char*)a0 = v0;
    goto L001B7910;
L001B7908:;
    *(int*)(char*)a0 = 0;
L001B7910:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
