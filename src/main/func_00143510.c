/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern int func_00147840(int, int);

int Inventory_GetEquipMode(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = 0 + 6;
    a1 = *(unsigned char*)(char*)(a0 + 132);
    cond = a1 == v1;
    v0 = 0;
    if (cond) goto L00143548;
    v0 = a1 << 4;
    v0 = a0 + v0;
    a0 = *(int*)(char*)D_004FFD30;
    a1 = *(int*)(char*)(v0 + 8);
    v0 = func_00147840(a0, a1);
    v0 = *(signed char*)(char*)(v0 + 72);
L00143548:;
    goto ret;
ret:
    return v0;
}
