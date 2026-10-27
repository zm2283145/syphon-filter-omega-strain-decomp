/*
 * SFOGame/Source/hud_netlobby: 1 file, 0027B4A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027B4A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud_netlobby.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_netlobby_types.h"

extern ListPos* std_list_deleter_voidPtr_insert(ListPos* result, void* list, ListPos* pos, int value);

void std_list_GameInfoPtr_generic_iterator_opCast(int* dst, int* src) {
    *dst = *src;
}

/* push_back on a list whose sentinel node is at +4. */
ListPos* std_list_GameInfoPtr_push_back(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_0027B4A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027B4A0 */
