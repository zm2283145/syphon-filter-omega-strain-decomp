/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_tree_pair_int_value_compare_node_alloc_void(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_3(void) {
}

void* std_tree_pair_int_value_compare_alloc_void(void* self) {
    return self;
}

Map* func_003FCC80(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

Map* std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_2(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
