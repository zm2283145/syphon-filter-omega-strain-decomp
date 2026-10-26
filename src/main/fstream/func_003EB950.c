/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"

/* begin() iterator of a pointer vector. */
void std_list_cFSDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
