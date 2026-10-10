#include "types.h"

extern int func_003F05A0(int, int);

void func_003E7AD0(int a0) {
    int a1, v0;
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L003E7AF0;
    v0 = func_003F05A0(a0, a1);
L003E7AF0:;
    goto ret;
ret:;
}
