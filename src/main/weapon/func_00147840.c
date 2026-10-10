#include "types.h"

int WeaponDb_Get(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a1 < 0;
    if (cond) goto L00147860;
    v0 = *(int*)((char*)a0 + 4);
    v0 = *(int*)((char*)v0 + 4);
    v0 = a1 < v0;
    cond = v0 != 0;
    if (cond) goto L00147868;
L00147860:;
    a1 = 0;
L00147868:;
    v0 = *(int*)((char*)a0 + 20);
    v1 = a1 << 2;
    v1 = v1 + a1;
    v1 = v1 << 6;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
