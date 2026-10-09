/*
 * Matched functions (byte-identical with the retail executable).
 * Rel initializers and pointer vector push_back.
 */

#include "types.h"
#include "particle_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Zeroes the three words. */
Rel* func_00398410(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* push_back on a pointer vector. */
int func_00398430(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* Zeroes the three words. */
Rel* func_00398450(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
