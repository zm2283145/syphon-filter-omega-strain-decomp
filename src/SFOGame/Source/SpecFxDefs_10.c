/*
 * SFOGame/Source/SpecFxDefs: 1 file, 002320F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002320F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern SpecListPos* std_list_deleter_voidPtr_insert(SpecListPos* result, void* list, SpecListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
SpecListPos* std_list_tItemPtr_push_back(void* list, int* value) {
    SpecListPos end;
    SpecListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_002320F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002320F0 */
