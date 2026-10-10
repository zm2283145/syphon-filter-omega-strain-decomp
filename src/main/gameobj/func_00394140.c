#include "types.h"

extern int func_003A2650(int, int);

int func_00394140(int a0) {
    int a1, v0;
    int cond;

    a0 = *(int*)((char*)a0 + 100);
    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L00394160;
    v0 = func_003A2650(a0, a1);
L00394160:;
    goto ret;
ret:
    return v0;
}
