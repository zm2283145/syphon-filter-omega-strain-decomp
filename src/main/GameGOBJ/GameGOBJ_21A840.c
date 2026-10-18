/*
 * main/GameGOBJ: range (2 files, 0021A840-0021A8C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "linked_target_refresh.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_flag_slot16.h"
#pragma pop

/* merge_units: begin func_0021A840 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Push the value to the linked target and refresh it. */
DEFINE_LINKED_TARGET_REFRESH(cGameGOBJ_Draw)
#pragma pop /* merge_units */
/* merge_units: end func_0021A840 */

/* merge_units: begin func_0021A8C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Call slot 16 unless the object is active. */
DEFINE_GOBJ_FLAG_SLOT16(GObj_Tick)
#pragma pop /* merge_units */
/* merge_units: end func_0021A8C0 */
