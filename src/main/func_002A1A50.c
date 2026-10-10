#include "types.h"

int func_002A1A50(int a0, int a1, int a2, int a3) {
    int at, v0;
    int cond;

    cond = a3 == 0;
    if (cond) goto L002A1A60;
    a0 = a0 + 1;
    goto L002A1A68;
L002A1A60:;
    a0 = a0 + -1;
L002A1A68:;
    at = a0 < a1;
    cond = at == 0;
    if (cond) goto L002A1A78;
    a0 = a2;
L002A1A78:;
    at = a2 < a0;
    cond = at == 0;
    if (cond) goto L002A1A88;
    a0 = a1;
L002A1A88:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
