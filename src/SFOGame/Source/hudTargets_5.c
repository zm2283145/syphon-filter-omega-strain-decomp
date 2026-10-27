/*
 * SFOGame/Source/hudTargets: 1 file, 00273540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00273540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern ListPos* std_list_deleter_voidPtr_insert(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a marker list whose sentinel node is at +4. */
ListPos* std_list_cHudTargetInfoPtr_push_back(MarkerList* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (ListNode*)&list->unk04;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00273540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273540 */
