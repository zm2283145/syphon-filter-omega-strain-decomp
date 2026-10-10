#include "types.h"

extern char D_0048BE60[];

int func_002BB300(int a0, int a1) {
    int a2, v0, v1;
    int cond;

    v0 = a0 << 1;
    a2 = 0;
    v0 = v0 + a0;
    v0 = v0 << 5;
    v0 = v0 + a0;
    v0 = v0 << 2;
    a0 = (int)D_0048BE60;
    a0 = a0 + v0;
    v1 = *(int*)(char*)a0;
L002BB328:;
    a0 = a0 + 4;
    cond = v1 == a1;
    v0 = 0 + 1;
    if (cond) goto L002BB350;
    a2 = a2 + 1;
    v0 = a2 < 32;
    if (v0 != 0) {
    v1 = *(int*)(char*)a0;
    goto L002BB328;
    }
    v0 = 0;
L002BB350:;
    goto ret;
ret:
    return v0;
}
