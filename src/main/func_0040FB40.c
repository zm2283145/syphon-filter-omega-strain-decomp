/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0040F710(int, int);

void* func_0040FB40(char* self) {
    return self + 4;
}

void* func_0040FB50(void* self) {
    return self;
}

void func_0040FB60(int a0) {
    int a1, s0, v0, v1;
    int cond;

    a1 = *(int*)(char*)(a0 + 4);
    cond = a1 == 0;
    s0 = a0;
    if (cond) goto L0040FB90;
    v0 = func_0040F710(a0, a1);
    *(int*)(char*)s0 = 0;
    v1 = s0 + 4;
    *(int*)(char*)(s0 + 4) = 0;
    *(int*)(char*)(s0 + 12) = v1;
L0040FB90:;
    goto ret;
ret:;
}

Map* func_0040FBA0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
