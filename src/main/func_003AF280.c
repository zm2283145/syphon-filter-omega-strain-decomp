/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003B8230(int, int);

Word* func_003AF280(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void* func_003AF290(char* self) {
    return self + 8;
}

int func_003AF2A0(int a0, int a1) {
    return func_003B8230(a0, a1);
}

Rel* func_003AF2B0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
