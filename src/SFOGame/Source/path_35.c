/*
 * SFOGame/Source/path: 1 file, 00164120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00164120 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver list insertion (push_back on listA).
 */

#include "types.h"
#include "path_types.h"

extern int std_list_deleter_voidPtr_insert(PathListLink** out, PathList* list, PathListLink** pos, int* value);
extern int std_list_cPathSystemRequestPtr_push_back(PathList* list, int* value);

/* Appends value to listA; always returns 1. */
int cPathSystem_Request(PathReceiver* self, int value) {
    volatile int tmp = value; /* original stack temporary */
    std_list_cPathSystemRequestPtr_push_back(&self->listA, (int*)&tmp);
    return 1;
}

/* push_back: insert before the sentinel. */
int std_list_cPathSystemRequestPtr_push_back(PathList* list, int* value) {
    PathListLink* end = &list->head;
    PathListLink* result;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00164120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00164120 */
