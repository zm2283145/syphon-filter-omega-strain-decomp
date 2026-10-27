/*
 * Matched functions (byte-identical with the retail executable).
 * List append: inserts value before the list end.
 */

#include "types.h"

extern int std_list_deleter_voidPtr_insert(Iter*, List*, Iter*, int);

int std_list_cTargetAwarenessPtr_push_front(List* list, int value) {
    Iter pos;
    Iter result;

    pos.p = list->last;
    return std_list_deleter_voidPtr_insert(&result, list, &pos, value);
}
