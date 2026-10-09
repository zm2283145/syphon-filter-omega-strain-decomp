/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00393C50(char* self) {
    return self + 4;
}

void func_00393C60(char* self, int value) {
    *(int*)(self + 0) = value;
}

Rel* func_00393C70(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
