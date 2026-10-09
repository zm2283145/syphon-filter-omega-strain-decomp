/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Quad* func_001BEAA0(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

void func_001BEAD0(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 12) + (*(int*)((char*)a1 + 8) << 2));
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 8) = (*(int*)((char*)a0 + 4) + (*(int*)((char*)a1 + 8) << 2));
    *(int*)((char*)a0 + 12) = (*(int*)((char*)a0 + 4) + (*(int*)(char*)a1 << 2));
}
