/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int std_list_deleter_voidPtr_insert(int* result, List* list, void** pos, int value);

/* Append value at the end of the list (insert before the sentinel at +4). */
int std_list_cSkaPlaybackGroupPtr_push_back(List* list, int value) {
    struct {
        void* pos;
        int result;
    } loc;

    loc.pos = &list->first;
    return std_list_deleter_voidPtr_insert(&loc.result, list, &loc.pos, value);
}
