#include "types.h"

extern char D_005723C8[];

void func_0016A550(void) {
    int v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L0016A568;
    *(char*)(char*)D_005723C8 = v1;
L0016A568:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
