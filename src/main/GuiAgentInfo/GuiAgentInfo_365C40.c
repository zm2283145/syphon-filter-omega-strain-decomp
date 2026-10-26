/*
 * main/GuiAgentInfo: 7 files, 00365C40-00366640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00365C40 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_365C40)
#pragma pop /* merge_units */
/* merge_units: end func_00365C40 */

/* merge_units: begin func_00365D30 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004BBAA0[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_365D30, 0x1800000, 0xC00000, D_004BBAA0, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00365D30 */

/* merge_units: begin func_00366200 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_004BBAC0[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(Vector_Reserve_366200, 0x1800000, D_004BBAC0, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00366200 */

/* merge_units: begin func_00366450 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(ChannelVector_Resize_366450, Elem60, AnimChannelVec_Grow, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00366450 */

/* merge_units: begin func_003664E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_003664E0, Elem8, Vector_Insert_1BF5A0, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_003664E0 */

/* merge_units: begin func_00366550 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00366550, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_00366550 */

/* merge_units: begin func_00366640 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_00366640)
#pragma pop /* merge_units */
/* merge_units: end func_00366640 */
