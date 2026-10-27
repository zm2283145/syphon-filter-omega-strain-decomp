#include "types.h"

int func_001EC310(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001EC328;
    *(int*)(char*)a0 = v0;
    goto L001EC330;
L001EC328:;
    *(int*)(char*)a0 = 0;
L001EC330:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
