#include "types.h"

int func_0023C140(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 96);
    v0 = 0 + 2;
    cond = v1 != v0;
    if (cond) goto L0023C168;
    v0 = *(unsigned char*)((char*)a0 + 220);
    cond = v0 == 0;
    if (cond) goto L0023C168;
    v0 = *(int*)((char*)a0 + 320);
    goto L0023C170;
L0023C168:;
    v0 = 0;
L0023C170:;
    goto ret;
ret:
    return v0;
}
