#include "types.h"

extern char D_005721D8[];

int func_00169360(void) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)D_005721D8;
    cond = v0 == 0;
    if (cond) goto L00169380;
    v0 = 0 + 1;
    *(char*)(char*)D_005721D8 = 0;
    goto L00169388;
L00169380:;
    v0 = 0;
L00169388:;
    goto ret;
ret:
    return v0;
}
