#include "types.h"

extern int func_00392990(int);

void func_001B16E0(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 13236);
    cond = v1 != 0;
    if (cond) goto L001B1700;
    v0 = func_00392990(a0);
L001B1700:;
    goto ret;
ret:;
}
