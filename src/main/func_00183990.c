/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_00139920(int, int);
extern int func_00183B70(int, int, int);

/* Last element of an array of 0x70-byte records. */
Elem70* func_00183990(Vec70Array* v) {
    return (v->data + v->count) + -1;
}

int func_001839B0(int a0, int a1, int a2) {
    return func_00183B70(a0, a1, a2);
}

int func_001839C0(int a0, int a1) {
    return func_00139920(a0, a1);
}

int func_001839D0(IntPair* p) {
    return p->a;
}

int func_001839E0(IntPair* p) {
    return p->b;
}
