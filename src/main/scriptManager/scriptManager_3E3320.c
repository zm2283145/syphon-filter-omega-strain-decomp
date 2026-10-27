/*
 * main/scriptManager: 2 files, 003E3320-003E3460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E3320 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#define D_0049AE80 D_004BDBE8
#include "object_list_erase_range.h"
extern "C" { char D_004BDBE8[] = "allocator.hh"; }

DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_PopVar_erase)
#pragma pop /* merge_units */
/* merge_units: end func_003E3320 */

/* merge_units: begin func_003E3460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


List* std_list_deleter_PopVar_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3460 */
