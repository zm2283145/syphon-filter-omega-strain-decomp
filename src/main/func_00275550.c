#include "types.h"

extern char D_004FFE60[];
extern char D_004FFEDC[];
extern char D_004FFF75[];

void func_00275550(void) {
    int a0, a1, a2, v1;
    int cond;

    a1 = 0;
    a0 = (int)D_004FFE60;
L00275560:;
    *(char*)((char*)a0 + 277) = 0;
    *(int*)((char*)a0 + 124) = 0;
    a1 = a1 + 8;
    *(char*)((char*)a0 + 613) = 0;
    v1 = a1 < 42;
    *(int*)((char*)a0 + 460) = 0;
    *(char*)((char*)a0 + 949) = 0;
    *(int*)((char*)a0 + 796) = 0;
    *(char*)((char*)a0 + 1285) = 0;
    *(int*)((char*)a0 + 1132) = 0;
    *(char*)((char*)a0 + 1621) = 0;
    *(int*)((char*)a0 + 1468) = 0;
    *(char*)((char*)a0 + 1957) = 0;
    *(int*)((char*)a0 + 1804) = 0;
    *(char*)((char*)a0 + 2293) = 0;
    *(int*)((char*)a0 + 2140) = 0;
    *(char*)((char*)a0 + 2629) = 0;
    *(int*)((char*)a0 + 2476) = 0;
    cond = v1 != 0;
    a0 = a0 + 2688;
    if (cond) goto L00275560;
    v1 = a1 << 3;
    a2 = v1 - a1;
    a0 = (int)D_004FFF75;
    a1 = a2 << 2;
    a1 = a1 - a2;
    v1 = (int)D_004FFEDC;
    a1 = a1 << 4;
    a0 = a0 + a1;
    v1 = v1 + a1;
    *(char*)(char*)a0 = 0;
    *(int*)(char*)v1 = 0;
    *(char*)((char*)a0 + 336) = 0;
    *(int*)((char*)v1 + 336) = 0;
    goto ret;
ret:;
}
