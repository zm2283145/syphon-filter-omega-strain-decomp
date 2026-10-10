#include "types.h"

extern char D_00487848[];

int func_00117558(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = (int)D_00487848;
    v0 = *(int*)((char*)v1 + 8);
    cond = v0 >= 0;
    if (cond) goto L00117578;
    v0 = 0x80000000;
    v0 = v0 | 0x8001;
    goto ret;
L00117578:;
    cond = a0 == 0;
    if (cond) goto L00117588;
    v0 = *(int*)((char*)v1 + 16);
    *(int*)(char*)a0 = v0;
L00117588:;
    cond = a1 == 0;
    if (cond) goto L001175A0;
    v1 = *(int*)((char*)v1 + 16);
    v0 = 0 + 128;
    v0 = v0 - v1;
    *(int*)(char*)a1 = v0;
L001175A0:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
