/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int List_InsertBefore(int* result, List* list, void** pos, int value);

/* Append value at the end of the list (insert before the sentinel at +4). */
int func_003B0020(List* list, int value) {
    struct {
        void* pos;
        int result;
    } loc;

    loc.pos = &list->first;
    return List_InsertBefore(&loc.result, list, &loc.pos, value);
}
