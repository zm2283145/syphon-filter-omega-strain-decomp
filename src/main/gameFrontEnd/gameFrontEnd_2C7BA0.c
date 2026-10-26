#include "types.h"

extern char D_0051EE88[];
extern char D_005723C8[];
extern int NetGetObject(int, int);

int tNetGenerator_NetGeneratorCreationCallback(void) {
    int loc[2];
    int a0, a1, v0, v1;
    int cond;

    v0 = *(unsigned char*)(char*)D_005723C8;
    cond = v0 != 0;
    v0 = 0 + 1;
    if (cond) goto L002C7BC0;
    *(char*)(char*)D_005723C8 = v0;
L002C7BC0:;
    a0 = (int)loc;
    v0 = NetGetObject(a0, a1);
    cond = v0 != 0;
    if (cond) goto L002C7BE0;
    v1 = *(int*)(char*)loc;
    v1 = *(int*)((char*)v1 + 28);
    *(int*)(char*)D_0051EE88 = v1;
L002C7BE0:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:
    return v0;
}
