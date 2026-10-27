/*
 * main/WaterFx: range (3 files, 002B4810-002B49A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "object_list_erase_range.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "object_list_erase_file.h"
#pragma pop

/* merge_units: begin func_002B4810 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSplash_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002B4810 */

/* merge_units: begin func_002B4860 */
#pragma push /* merge_units */
#pragma cplusplus on
#define D_0049AE80 D_004ABFD0
extern "C" {
char D_004ABFD0[] = "allocator.hh";
}

DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_tNode_erase_listdeleter_listdeleter)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B4860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B4860 */

/* merge_units: begin func_002B49A0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_OBJECT_LIST_ERASE_ONE_FILE(std_list_deleter_tNode_erase_listdeleter, D_004ABFD0)
#pragma pop /* merge_units */
/* merge_units: end func_002B49A0 */
