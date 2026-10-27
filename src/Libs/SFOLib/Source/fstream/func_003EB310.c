/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */

#include "types.h"
#include "fstream_types.h"

extern int std_list_deleter_voidPtr_insert(int** out, StdList* list, int** pos, int value);

/* list.push_back(value): insert before the sentinel. */
int std_list_cFSDataPtr_push_back(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return std_list_deleter_voidPtr_insert(&it.result, list, &it.pos, value);
}
