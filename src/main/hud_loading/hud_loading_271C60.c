#include "types.h"

extern void IeElement_SetShown(int, int);

void LoadingScreen_DrawPressX(int a0) {
    int a1, s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 40);
    cond = a0 == 0;
    if (cond) goto L00271C88;
    IeElement_SetShown(a0, a1);
L00271C88:;
    a0 = *(int*)((char*)s0 + 36);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CA0;
    IeElement_SetShown(a0, a1);
L00271CA0:;
    a0 = *(int*)((char*)s0 + 56);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L00271CB8;
    IeElement_SetShown(a0, a1);
L00271CB8:;
    goto ret;
ret:;
}
