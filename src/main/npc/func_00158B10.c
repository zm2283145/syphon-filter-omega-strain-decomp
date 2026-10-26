/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern void std_list_deleter_cLookAtListItem_ctor(void* self);

void* cNPC_cActiveSlot_ctor(void* self) {
    std_list_deleter_cLookAtListItem_ctor(self);
    return self;
}
