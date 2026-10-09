/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern int func_0016E170(void* obj, int a1, int a2);

/* Three-word record, initialised to {0, -2, -1}. */
typedef struct NpcTriple {
    int unk0;
    int unk4;
    int unk8;
} NpcTriple;

NpcTriple* func_0015AC70(NpcTriple* self) {
    self->unk4 = -2;
    self->unk0 = 0;
    self->unk8 = -1;
    return self;
}

Word* func_0015AC90(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_0015ACA0(void* self) {
    return self;
}

void* func_0015ACB0(void* self) {
    return self;
}

void* func_0015ACC0(void* self) {
    return self;
}

NpcTriple* func_0015ACD0(NpcTriple* self) {
    self->unk0 = 0;
    self->unk8 = 0;
    func_0016E170(self, 0, 0);
    return self;
}
