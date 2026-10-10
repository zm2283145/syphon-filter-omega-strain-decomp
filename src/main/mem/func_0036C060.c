#include "types.h"

int func_0036C060(int a0, int a1) {
    int at, v0;
    int cond;

    v0 = (unsigned int)a1 < (unsigned int)40;
    cond = v0 != 0;
    if (cond) goto L0036C090;
L0036C070:;
    a1 = (unsigned int)a1 >> 1;
    at = (unsigned int)a1 < (unsigned int)40;
    a0 = a0 + 64;
    cond = at == 0;
    if (cond) goto L0036C070;
L0036C090:;
    v0 = a1 + -20;
    v0 = (unsigned int)v0 >> 2;
    v0 = v0 << 4;
    a0 = a0 + v0;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
