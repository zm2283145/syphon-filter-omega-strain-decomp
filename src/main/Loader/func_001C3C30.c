/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* v.back(): address of the last element. */
int* std_vector_charPtr_back(PtrVec* v) {
    return v->data + v->count - 1;
}
