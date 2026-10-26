/*
 * Matched functions (byte-identical with the retail executable).
 * mem.cc
 */

#include "types.h"
#include "mem_types.h"

/* Setter for unk08. */
void cMemChunk_SetPrev(MemObj* self, int value) {
    self->unk08 = value;
}

/* Setter for unk04. */
void cMemChunk_SetNext(MemObj* self, int value) {
    self->unk04 = value;
}

/* Getter for unk04. */
int cMemChunk_GetNext(MemObj* self) {
    return self->unk04;
}
