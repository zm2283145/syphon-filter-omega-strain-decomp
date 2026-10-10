#include "types.h"

extern char D_0049D010[];
extern int func_001439B0(int, int);

int Script_cPlayer_ArmWeapon(int a0) {
    int loc[1];
    int a1, v0, v1;
    int cond;

    v0 = *(int*)((char*)a0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    a0 = *(int*)((char*)v0 + 48);
    cond = a0 == 0;
    a1 = *(int*)(char*)loc;
    if (cond) goto L00175CC0;
    v1 = *(int*)((char*)a0 + 76);
    v0 = *(int*)(char*)D_0049D010;
    cond = v1 != v0;
    if (cond) goto L00175CC0;
    a0 = *(int*)((char*)a0 + 13604);
    v0 = func_001439B0(a0, a1);
L00175CC0:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
