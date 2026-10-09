/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver list insertion (push_back on listA).
 */

#include "types.h"
#include "path_types.h"

extern int List_InsertBefore(PathListLink** out, PathList* list, PathListLink** pos, int* value);
extern int PathList_PushBack(PathList* list, int* value);

/* Appends value to listA; always returns 1. */
int func_00164120(PathReceiver* self, int value) {
    volatile int tmp = value; /* original stack temporary */
    PathList_PushBack(&self->listA, (int*)&tmp);
    return 1;
}

/* push_back: insert before the sentinel. */
int PathList_PushBack(PathList* list, int* value) {
    PathListLink* end = &list->head;
    PathListLink* result;
    return List_InsertBefore(&result, list, &end, value);
}
