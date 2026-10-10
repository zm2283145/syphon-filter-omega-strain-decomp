#include "types.h"

extern int func_002B6BB0(int, int, int);

void func_002B6D20(int a0, int a1, int a2) {
    int s0, v0, v1;
    int cond;

    s0 = a2;
    v0 = func_002B6BB0(a0, a1, a2);
    v1 = 0x7fff0000;
    a0 = 0x81010000;
    v1 = v1 | 0xffff;
    cond = v0 != v1;
    a0 = a0 | 0x9002;
    if (cond) goto L002B6D4C;
    *(int*)(char*)s0 = a0;
L002B6D4C:;
    goto ret;
ret:;
}
