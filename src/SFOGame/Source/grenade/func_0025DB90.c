/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(int, int);
extern int std_vector_imp_cVector_reserve(int, int);

int PtrVec_Reserve_Thunk_25DB90(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* func_0025DBA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_cVector_reserve(int a0, int a1) {
    return std_vector_imp_cVector_reserve(a0, a1);
}
