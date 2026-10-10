#include "types.h"

extern int func_00263080(int);

void func_00143770(int a0) {
    int v0;
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00143790;
    v0 = func_00263080(a0);
L00143790:;
    goto ret;
ret:;
}
