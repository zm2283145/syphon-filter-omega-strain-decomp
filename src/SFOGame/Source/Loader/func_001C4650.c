/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* Construct an empty map with comparator byte *cmp. */
Map* std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
