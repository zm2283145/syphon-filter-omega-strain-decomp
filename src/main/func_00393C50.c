/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00393CC0(int);

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

int func_00393C90(int a0) {
    func_00393CC0(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
