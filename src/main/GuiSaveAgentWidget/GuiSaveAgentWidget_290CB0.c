/*
 * main/GuiSaveAgentWidget: 4 files, 00290CB0-00291460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00290CB0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004A9B20[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_290CB0, 0x1800000, 0xC00000, D_004A9B20, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00290CB0 */

/* merge_units: begin func_00291180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_004A9B40[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(Vector_Reserve_291180, 0x1800000, D_004A9B40, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00291180 */

/* merge_units: begin func_002913D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002913D0, Elem60, AnimChannelVec_Grow, func_001BEB20)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002913D0 */

/* merge_units: begin func_00291460 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_00291460, Elem8, Vector_Insert_1BF5A0, func_001BF440)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00291460 */
