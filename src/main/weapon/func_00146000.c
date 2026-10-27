/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);

/* push_back on a pointer vector. */
int std_vector_charPtr_push_back_charPR(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

Rel* std_vector_charPtr_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
