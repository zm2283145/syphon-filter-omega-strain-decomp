#include "types.h"

void cNPC_SetWeaponPreference(int a0, int a1, int a2) {
    int v1;
    int cond;

    v1 = a2 & 255;
    cond = v1 != 0;
    if (cond) goto L0014B758;
    *(int*)((char*)a0 + 176) = a1;
    goto L0014B760;
L0014B758:;
    *(int*)((char*)a0 + 180) = a1;
L0014B760:;
    goto ret;
ret:;
}
