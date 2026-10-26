/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cInterfaceElementPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
