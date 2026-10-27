/*
 * SFOGame/Source/hud: 1 file, 00243430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00243430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern ListPos* std_list_deleter_voidPtr_insert(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
ListPos* std_list_tCalloutPtr_push_back(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00243430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00243430 */
