/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Reserve(int, int);
extern int Vector_Reserve_25DBD0(int, int);

int PtrVec_Reserve_Thunk_25DB90(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_0025DBA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int Vector_Reserve_25DBD0_Thunk(int a0, int a1) {
    return Vector_Reserve_25DBD0(a0, a1);
}
