#include "types.h"

void func_00100D20(int a0) {
    int a1, v0, v1;
    int cond;

    a1 = *(int*)(char*)a0;
    cond = a1 == 0;
    if (cond) goto L00100D50;
    v1 = *(int*)((char*)a0 + 8);
    cond = v1 == 0;
    if (cond) goto L00100D50;
    a0 = a1;
    a1 = 0 + -1;
    v0 = ((int (*)(int, int))v1)(a0, a1);
L00100D50:;
    goto ret;
ret:;
}
