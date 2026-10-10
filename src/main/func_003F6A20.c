#include "types.h"

extern int func_003F6180(int, int);
extern int func_003F6480(int);

void func_003F6A20(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = *(int*)(char*)a0;
    cond = v1 == 0;
    if (cond) goto L003F6A78;
    a1 = *(unsigned char*)((char*)a0 + 4);
    v1 = 0 + 4;
    cond = a1 == v1;
    v1 = 0 + 2;
    if (cond) goto L003F6A78;
    cond = a1 != v1;
    if (cond) goto L003F6A60;
    v0 = func_003F6480(a0);
    goto L003F6A78;
L003F6A60:;
    v1 = 0 + 3;
    cond = a1 != v1;
    if (cond) goto L003F6A78;
    v0 = func_003F6180(a0, a1);
L003F6A78:;
    goto ret;
ret:;
}
