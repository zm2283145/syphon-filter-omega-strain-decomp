/*
 * Matched functions (byte-identical with the retail executable).
 * List append: inserts value before the list end.
 */

#include "types.h"

extern int List_InsertBefore(Iter*, List*, Iter*, int);

int List_PushBack_16CEE0(List* list, int value) {
    Iter pos;
    Iter result;

    pos.p = list->last;
    return List_InsertBefore(&result, list, &pos, value);
}
