/*
 * main/GuiNetMessages: 5 files, 00345110-00345930
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00345110 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004BA0E0[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_345110, 0x1800000, 0xC00000, D_004BA0E0, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00345110 */

/* merge_units: begin func_003455E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_004BA100[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(Vector_Reserve_3455E0, 0x1800000, D_004BA100, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_003455E0 */

/* merge_units: begin func_00345830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(ChannelVector_Resize_345830, Elem60, AnimChannelVec_Grow, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00345830 */

/* merge_units: begin func_003458C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_003458C0, Elem8, Vector_Insert_1BF5A0, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_003458C0 */

/* merge_units: begin func_00345930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00345930, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_00345930 */
