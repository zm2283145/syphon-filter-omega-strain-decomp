#include "types.h"

int func_00373BE0(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 16);
    cond = v1 == 0;
    v0 = 0;
    if (cond) goto L00373BF0;
    v0 = *(int*)(char*)a0;
L00373BF0:;
    goto ret;
ret:
    return v0;
}
