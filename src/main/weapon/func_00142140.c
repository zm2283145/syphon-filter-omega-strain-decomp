#include "types.h"

extern void HeldItem_Reset(int);

void func_00142140(int a0) {
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00142160;
    HeldItem_Reset(a0);
L00142160:;
    goto ret;
ret:;
}
