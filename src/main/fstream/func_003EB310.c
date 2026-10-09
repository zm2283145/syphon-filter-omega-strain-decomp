/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"
#include "fstream_types.h"

extern int List_InsertBefore(int** out, StdList* list, int** pos, int value);

/* list.push_back(value): insert before the sentinel. */
int List_PushBack_3EB310(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return List_InsertBefore(&it.result, list, &it.pos, value);
}
