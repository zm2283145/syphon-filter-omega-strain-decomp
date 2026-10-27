/*
 * Libs/SFOLib/Source/GenInfoObject: 1 file, 00439C40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00439C40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GenInfoObject_types.h"

extern GioListPos* std_list_deleter_voidPtr_insert(GioListPos* result, void* list, GioListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
GioListPos* std_list_tGenInfoPtr_push_back(void* list, int value) {
    GioListPos end;
    GioListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00439C40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00439C40 */
