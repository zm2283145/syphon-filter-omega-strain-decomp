#include "types.h"

extern int func_002D8A98(int);

void func_002F5098(int a0) {
    int v0;
    int cond;

    cond = a0 == 0;
    if (cond) goto L002F50B0;
    v0 = func_002D8A98(a0);
    goto ret;
L002F50B0:;
    goto ret;
ret:;
}
