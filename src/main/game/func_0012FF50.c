#include "types.h"

void func_0012FF50(int a0) {
    int v1;
    int cond;

    a0 = *(int*)((char*)a0 + 176);
    cond = a0 == 0;
    if (cond) goto L0012FF70;
    v1 = *(unsigned char*)((char*)a0 + 561);
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L0012FF70;
    *(char*)((char*)a0 + 565) = v1;
L0012FF70:;
    goto ret;
ret:;
}
