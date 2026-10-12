#include "types.h"

extern int WeaponInv_Holster(int, int);
extern int WeaponInv_CanChangeMode(int);

void WeaponInv_HolsterCurrent(int a0) {
    int a1, s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = WeaponInv_CanChangeMode(a0);
    cond = v0 == 0;
    if (cond) goto L00143BA8;
    a0 = *(unsigned char*)((char*)s0 + 132);
    v1 = 0 + 6;
    cond = a0 == v1;
    if (cond) goto L00143BA0;
    a1 = *(signed char*)((char*)s0 + 132);
    a0 = s0;
    v0 = WeaponInv_Holster(a0, a1);
    goto L00143BA8;
L00143BA0:;
    *(char*)((char*)s0 + 133) = v1;
L00143BA8:;
    goto ret;
ret:;
}
