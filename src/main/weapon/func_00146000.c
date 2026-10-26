/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);

/* push_back on a pointer vector. */
int std_vector_charPtr_push_back_charPR(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

Rel* std_vector_charPtr_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
