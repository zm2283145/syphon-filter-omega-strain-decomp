/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

/* Address of the second word of the vector's first element. */
int* func_00159560(PtrVec* v) {
    return v->data + 2;
}

int func_00159570(Word* self) {
    return self->value;
}

void func_00159580(Iter* out, PtrVec* v) {
    out->p = v->data;
}
