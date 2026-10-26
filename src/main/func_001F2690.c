/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(void*);

int std_list_deleter_voidPtr_tail(char* self) {
    return details_compressed_pair_imp_cAllocator_node_node_base_1_second_void(self + 4);
}

Word* std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(Word* self, int value) {
    self->value = value;
    return self;
}
