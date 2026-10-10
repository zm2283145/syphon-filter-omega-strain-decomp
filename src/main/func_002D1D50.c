#include "types.h"

extern char D_005723C8[];

void func_002D1D50(void) {
    int v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L002D1D68;
    *(char*)(char*)D_005723C8 = v1;
L002D1D68:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
