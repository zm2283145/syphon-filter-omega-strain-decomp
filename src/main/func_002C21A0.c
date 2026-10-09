/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern char D_0051EE10[];
extern int WeaponDb_Get(int, int);
extern int func_002BF4B0(int, int, int);

Rel* func_002C21A0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_002C21C0(void) {
    int a0, a1, a2, at, s0, v0, v1;
    int cond;

    a1 = *(int*)(char*)D_0051EE10;
    v1 = *(int*)(char*)(a1 + 132);
    cond = v1 == 0;
    if (cond) goto L002C2278;
    v1 = *(int*)(char*)(a1 + 140);
    cond = v1 == 0;
    if (cond) goto L002C2278;
    a0 = *(int*)(char*)(a1 + 264);
    v1 = *(int*)(char*)(a1 + 260);
    at = a0 < v1;
    cond = at == 0;
    s0 = 0;
    if (cond) goto L002C2220;
    v0 = a0 << 1;
    v0 = v0 + a1;
    a1 = *(short*)(char*)(v0 + 268);
    a0 = *(int*)(char*)D_004FFD30;
    v0 = WeaponDb_Get(a0, a1);
    s0 = *(int*)(char*)(v0 + 316);
L002C2220:;
    cond = s0 == 0;
    if (cond) goto L002C2278;
    v1 = *(int*)(char*)D_0051EE10;
    v1 = *(int*)(char*)(v1 + 212);
    cond = v1 == 0;
    if (cond) goto L002C2278;
    a0 = *(int*)(char*)D_004FFD30;
    a1 = *(short*)(char*)(s0 + 1034);
    v0 = WeaponDb_Get(a0, a1);
    a0 = *(unsigned char*)(char*)(v0 + 240);
    v1 = 0 + 7;
    cond = a0 != v1;
    if (cond) goto L002C2260;
    s0 = *(int*)(char*)(v0 + 284);
L002C2260:;
    cond = s0 == 0;
    if (cond) goto L002C2278;
    a0 = *(int*)(char*)D_0051EE10;
    a2 = *(int*)(char*)(a0 + 212);
    a1 = s0;
    v0 = func_002BF4B0(a0, a1, a2);
L002C2278:;
    goto ret;
ret:
    return v0;
}
