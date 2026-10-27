/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_opAssign(int, int);

int std_vector_imp_cCollisionEdgePtr_1_opAssign(int a0, int a1) {
    std_vector_pod_int_opAssign(a0, a1);
    return a0;
}
