/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_4(char* self) {
    return self + 4;
}

/* Empty circular list: header node points to itself. */
List* std_list_deleter_cSafePtr_cGOBJ_ctor(List* l) {
    l->count = 0;
    l->last = &l->first;
    l->first = &l->first;
    return l;
}
