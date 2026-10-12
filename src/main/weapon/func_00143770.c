#include "types.h"

extern int HeldItem_Release(int);

void WeaponInv_ReleaseHeldObject(int a0) {
    int v0;
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00143790;
    v0 = HeldItem_Release(a0);
L00143790:;
    goto ret;
ret:;
}
