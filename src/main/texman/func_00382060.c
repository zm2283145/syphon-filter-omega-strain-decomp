#include "types.h"

extern char D_00539328[];
extern char D_00539330[];

void func_00382060(int a0) {
    int a1, v1;
    int cond;

    a1 = *(int*)((char*)a0 + 1156);
    cond = a1 == 0;
    if (cond) goto L003820A0;
    v1 = *(unsigned char*)((char*)a0 + 1161);
    cond = v1 != 0;
    if (cond) goto L00382088;
    a0 = *(int*)((char*)a0 + 1152);
    v1 = 0 + 1;
    cond = a0 != v1;
    if (cond) goto L00382098;
L00382088:;
    v1 = 0x13000000;
    *(int*)((char*)a1 + 8) = v1;
    goto L003820A0;
L00382098:;
    v1 = 0x13000000;
    *(int*)(char*)a1 = v1;
L003820A0:;
    *(int*)(char*)D_00539328 = 0;
    v1 = *(int*)(char*)D_00539330;
    v1 = v1 ^ 1;
    *(int*)(char*)D_00539330 = v1;
    goto ret;
ret:;
}
