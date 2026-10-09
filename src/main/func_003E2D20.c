/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004938D0;
extern char D_00559F18;
extern int func_001396D0(int, int);

int func_003E2D20(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_003E2D30(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003E2D50(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_003E2D60(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Byte flag setters. */
void func_003E2D80(int value) {
    D_00559F18 = value;
}

void func_003E2D90(int value) {
    D_004938D0 = value;
}
