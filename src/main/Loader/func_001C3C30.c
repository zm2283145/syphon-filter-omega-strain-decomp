/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* v.back(): address of the last element. */
int* PtrVec_Back_1C3C30(PtrVec* v) {
    return v->data + v->count - 1;
}
