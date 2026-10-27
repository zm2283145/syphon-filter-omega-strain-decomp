/*
 * Libs/SFOLib/Source/callback: 1 file, 003EA2B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EA2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "callback_types.h"

extern CbListPos* std_list_deleter_voidPtr_insert(CbListPos* result, void* list, CbListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4 (named std_list_cCBDataPtr_push_back in the symbol map). */
CbListPos* std_list_cCBDataPtr_push_back(void* list, int value) {
    CbListPos end;
    CbListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_003EA2B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA2B0 */
