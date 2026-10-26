/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

/* Address of the second word of the vector's first element. */
int* List_Front(PtrVec* v) {
    return v->data + 2;
}

int func_00159570(Word* self) {
    return self->value;
}

void std_list_cNPCPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
