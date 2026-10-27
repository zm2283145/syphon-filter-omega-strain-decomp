/*
 * Libs/SFOLib/Source/texman: 1 file, 00380170
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00380170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "texman_types.h"

extern TexListIter* std_list_deleter_int_insert(TexListIter* result, void* list, TexListIter* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
TexListIter* cLList_int_PushBackActual(void* list, int* value) {
    TexListIter end;
    TexListIter result;

    end.node = (TexListNode*)((char*)list + 4);
    return std_list_deleter_int_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00380170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00380170 */
