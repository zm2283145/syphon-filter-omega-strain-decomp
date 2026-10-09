/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_003AF130(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003AF150(int a0, int a1) {
    *(char*)((char*)a0) = *(unsigned char*)(char*)a1;
    *(char*)((char*)a0 + 1) = *(unsigned char*)((char*)a1 + 1);
    *(char*)((char*)a0 + 2) = *(unsigned char*)((char*)a1 + 2);
    return a0;
}
