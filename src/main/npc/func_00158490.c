/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void func_00158490(char* self, int value) {
    *(int*)(self + 0x1C) = value;
}

int cObjectId_GetEncodedValue(Word* self) {
    return self->value;
}
