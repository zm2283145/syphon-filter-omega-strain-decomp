#include "types.h"

extern int cSKM_GOBJ_Render(int);

void cHuman_Render(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 13236);
    cond = v1 != 0;
    if (cond) goto L001B1700;
    v0 = cSKM_GOBJ_Render(a0);
L001B1700:;
    goto ret;
ret:;
}
