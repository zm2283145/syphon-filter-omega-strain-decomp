/*
 * Matched functions (byte-identical with the retail executable).
 * List helpers.
 */

#include "types.h"
#include "WaterFx_types.h"

/* Address of the list sentinel (end()). */
WaterListLink* func_002B4CE0(WaterList* list) {
    return &list->head;
}

/* Initializes an empty list. */
WaterList* List_Init(WaterList* list) {
    list->count = 0;
    list->head.prev = &list->head;
    list->head.next = &list->head;
    return list;
}
