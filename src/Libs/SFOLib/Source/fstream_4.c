/*
 * Libs/SFOLib/Source/fstream: 1 file, 003EB310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EB310 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003EB310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB310 */
