/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* std_list_deleter_TaserPulse_generic_iterator_ctor(Word* self, int value) {
    self->value = value;
    return self;
}

void* std_list_deleter_TaserPulse_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(void* self) {
    return self;
}
