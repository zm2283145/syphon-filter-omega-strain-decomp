#include "types.h"

extern void IeElement_SetShown(int, int);

void HudTicker_SetShown(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 1288);
    cond = a0 == 0;
    if (cond) goto L003F9E50;
    IeElement_SetShown(a0, a1);
L003F9E50:;
    goto ret;
ret:;
}
