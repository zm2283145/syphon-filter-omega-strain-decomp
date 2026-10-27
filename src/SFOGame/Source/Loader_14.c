/*
 * SFOGame/Source/Loader: 1 file, 001C1440
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C1440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern int std_list_deleter_voidPtr_insert(int** out, StdList* list, int** pos, int value);

/* list.push_back(value): insert before the sentinel. */
int cLList_cEnvSettingsPtr_PushBackActual(StdList* list, int value) {
    ListInsertArgs it;

    it.pos = &list->header;
    return std_list_deleter_voidPtr_insert(&it.result, list, &it.pos, value);
}
static inline void merge_flush_func_001C1440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C1440 */
