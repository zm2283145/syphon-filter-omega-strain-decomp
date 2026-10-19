/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Vector_Reserve_139920(int, int);

int Vector_Reserve_139920_Thunk(int a0, int a1) {
    return Vector_Reserve_139920(a0, a1);
}

int func_001361D0(char* self) {
    return *(int*)(self + 0);
}

Rel* func_001361E0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
