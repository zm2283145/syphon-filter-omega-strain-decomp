/*
 * Matched functions (byte-identical with the retail executable).
 * mem.cc
 */

#include "types.h"
#include "mem_types.h"

/* Setter for unk08. */
void func_0036C030(MemObj* self, int value) {
    self->unk08 = value;
}

/* Setter for unk04. */
void func_0036C040(MemObj* self, int value) {
    self->unk04 = value;
}

/* Getter for unk04. */
int func_0036C050(MemObj* self) {
    return self->unk04;
}
