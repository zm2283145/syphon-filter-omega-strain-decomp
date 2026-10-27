/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern int cStateMachine_ChangeState(void* obj, int a1, int a2);

/* Three-word record, initialised to {0, -2, -1}. */
typedef struct NpcTriple {
    int unk0;
    int unk4;
    int unk8;
} NpcTriple;

NpcTriple* cTargetAwareness_ctor(NpcTriple* self) {
    self->unk4 = -2;
    self->unk0 = 0;
    self->unk8 = -1;
    return self;
}

Word* cObjectId_ctor_uint(Word* self, int value) {
    self->value = value;
    return self;
}

void* cPathTransfer_ctor(void* self) {
    return self;
}

void* cPathNavigatorTransfer_ctor(void* self) {
    return self;
}

void* cAiTargetTransfer_ctor(void* self) {
    return self;
}

NpcTriple* cAiTransfer_ctor(NpcTriple* self) {
    self->unk0 = 0;
    self->unk8 = 0;
    cStateMachine_ChangeState(self, 0, 0);
    return self;
}
