#include "types.h"

int cNIEventOBJ_v47(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 96);
    v0 = 0 + 1;
    cond = v1 == v0;
    v0 = 0 + 3;
    if (cond) goto L0023C1A8;
    cond = v1 == v0;
    if (cond) goto L0023C1A8;
    v0 = 0 + 6;
    cond = v1 != v0;
    if (cond) goto L0023C1B0;
L0023C1A8:;
    v0 = *(int*)((char*)a0 + 320);
    goto L0023C1B8;
L0023C1B0:;
    v0 = 0;
L0023C1B8:;
    goto ret;
ret:
    return v0;
}
