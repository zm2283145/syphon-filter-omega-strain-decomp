/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

Word* std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(Word* self, int value) {
    self->value = value;
    return self;
}

Word* std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_cLookAtListItem_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_3(void* self) {
    return self;
}
