/*
 * Matched functions (byte-identical with the retail executable).
 * List helpers.
 */

#include "types.h"
#include "WaterFx_types.h"

/* Address of the list sentinel (end()). */
WaterListLink* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(WaterList* list) {
    return &list->head;
}

/* Initializes an empty list. */
WaterList* List_Init(WaterList* list) {
    list->count = 0;
    list->head.prev = &list->head;
    list->head.next = &list->head;
    return list;
}
