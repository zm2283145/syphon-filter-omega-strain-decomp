#include "types.h"

extern int func_0045CE10(int, int, int, int);

void func_00245E00(int a0) {
    int a1, a2, a3, v0;
    int cond;

    a0 = *(int*)((char*)a0 + 1700);
    cond = a0 == 0;
    if (cond) goto L00245E20;
    v0 = func_0045CE10(a0, a1, a2, a3);
L00245E20:;
    goto ret;
ret:;
}
