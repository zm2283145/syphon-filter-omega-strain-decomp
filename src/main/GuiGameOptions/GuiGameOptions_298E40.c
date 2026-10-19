/*
 * main/GuiGameOptions: 2 files, 00298E40-00299180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00298E40 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004AA560[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_298E40, D_004AA560, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00298E40 */

/* merge_units: begin func_00299180 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_00299180)
#pragma pop /* merge_units */
/* merge_units: end func_00299180 */
