/*
 * main/game: 2 files, 00139200-001396D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139200 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_0049AB70[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(PtrVec_Insert, 0x1800000, 0xC00000, D_0049AB70, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00139200 */

/* merge_units: begin func_001396D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_0049AB90[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(PtrVec_Reserve, 0x1800000, D_0049AB90, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_001396D0 */
