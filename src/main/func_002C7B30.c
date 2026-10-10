#include "types.h"

extern char D_0051EE88[];
extern char D_005723C8[];
extern int func_002EB650(int, int);

void func_002C7B30(void) {
    int loc[2];
    int a0, a1, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L002C7B50;
    *(char*)(char*)D_005723C8 = v1;
L002C7B50:;
    v1 = *(int*)(char*)D_0051EE88;
    cond = v1 != 0;
    a0 = (int)loc;
    if (cond) goto L002C7B80;
    v0 = func_002EB650(a0, a1);
    cond = v0 != 0;
    if (cond) goto L002C7B80;
    v1 = *(int*)(char*)loc;
    v1 = *(int*)((char*)v1 + 28);
    *(int*)(char*)D_0051EE88 = v1;
L002C7B80:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
