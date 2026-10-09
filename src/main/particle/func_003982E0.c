/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector push_back helpers.
 */

#include "types.h"
#include "particle_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_003982E0(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* push_back on a pointer vector. */
int func_00398300(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
