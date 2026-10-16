/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Reserve(void*, int);

int func_001AFCF0(void* self, int arg) {
    return PtrVec_Reserve(self, arg);
}

Rel* func_001AFD00(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_001AFD20(void* self, int arg) {
    return PtrVec_Reserve(self, arg);
}

Rel* func_001AFD30(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
