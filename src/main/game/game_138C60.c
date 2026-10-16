/*
 * main/game: 2 files, 00138C60-00138DA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00138C60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "object_list_erase_range.h"
extern "C" { char D_0049AE80[] = "allocator.hh"; }

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(ObjectList_EraseRange)
#pragma pop /* merge_units */
/* merge_units: end func_00138C60 */

/* merge_units: begin func_00138DA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_one.h"

/* Erase one node from a linked list. */
DEFINE_OBJECT_LIST_ERASE_ONE(List_Erase)
#pragma pop /* merge_units */
/* merge_units: end func_00138DA0 */
