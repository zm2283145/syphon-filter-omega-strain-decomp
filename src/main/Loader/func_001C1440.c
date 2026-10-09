/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern int List_InsertBefore(int** out, StdList* list, int** pos, int value);

/* list.push_back(value): insert before the sentinel. */
int func_001C1440(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return List_InsertBefore(&it.result, list, &it.pos, value);
}
