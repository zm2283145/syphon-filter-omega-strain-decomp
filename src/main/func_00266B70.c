/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(char* self) {
    return self + 4;
}

List* std_list_deleter_TaserPulse_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
