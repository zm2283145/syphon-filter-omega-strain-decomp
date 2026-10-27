/*
 * Libs/SFOLib/Source/skeleton: 1 file, 003AA130
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AA130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "skeleton_types.h"

extern SkelListPos* std_list_deleter_voidPtr_insert(SkelListPos* result, void* list, SkelListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
SkelListPos* std_list_cSkeletonDataBankEntryPtr_push_back(void* list, int value) {
    SkelListPos end;
    SkelListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_003AA130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA130 */
