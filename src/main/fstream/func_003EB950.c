/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

/* begin() iterator of a pointer vector. */
void func_003EB950(Iter* out, PtrVec* v) {
    out->p = v->data;
}
