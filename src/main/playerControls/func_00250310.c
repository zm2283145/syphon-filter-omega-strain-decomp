#include "types.h"

extern char D_004F7E10[];
extern char D_004F7E20[];
extern char D_004F7E24[];
extern char D_004F7E28[];

int func_00250310(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004F7E10;
    cond = v0 != 0;
    if (cond) goto L00250340;
    v0 = 0 + 1;
    *(int*)(char*)D_004F7E20 = 0;
    *(char*)(char*)D_004F7E10 = v0;
    *(int*)(char*)D_004F7E24 = 0;
    *(int*)(char*)D_004F7E28 = 0;
L00250340:;
    v0 = (int)D_004F7E20;
    goto ret;
ret:
    return v0;
}
