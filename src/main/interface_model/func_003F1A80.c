/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001396D0(int, int);
extern int func_003F1BF0(int);

Rel* func_003F1A80(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003F1AA0(int a0, int a1) {
    return func_001396D0(a0, a1);
}

int func_003F1AB0(int a0, int a1) {
    *(int*)((char*)a1) = *(int*)(char*)*(int*)(char*)a0;
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 4);
    return a0;
}

int func_003F1AD0(int a0) {
    func_003F1BF0(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
