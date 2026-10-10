#include "types.h"

extern char D_00554F28[];

int func_003D7590(int a0) {
    int v0, v1;
    int cond;

    v0 = a0 < 5100;
    cond = v0 != 0;
    if (cond) goto L003D75A0;
    a0 = a0 + -5000;
L003D75A0:;
    v0 = a0 + -100;
    v1 = v0 << 2;
    v0 = *(int*)(char*)D_00554F28;
    v0 = *(int*)((char*)v0 + 8);
    v0 = v0 + v1;
    v0 = *(int*)(char*)v0;
    goto ret;
ret:
    return v0;
}
