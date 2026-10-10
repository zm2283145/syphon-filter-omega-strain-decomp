#include "types.h"

void func_00185940(int a0, int a1) {
    int v1;
    int cond;

    v1 = 0 + -1;
    cond = a1 != v1;
    if (cond) goto L00185958;
    v1 = *(int*)((char*)a0 + 12);
    *(int*)((char*)a0 + 16) = v1;
    goto L00185960;
L00185958:;
    *(int*)((char*)a0 + 16) = a1;
L00185960:;
    goto ret;
ret:;
}
