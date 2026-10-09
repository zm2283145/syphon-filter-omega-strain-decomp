/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void func_00158490(char* self, int value) {
    *(int*)(self + 0x1C) = value;
}

int func_001584A0(Word* self) {
    return self->value;
}
