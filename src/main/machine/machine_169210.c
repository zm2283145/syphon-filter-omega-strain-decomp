/*
 * main/machine: range (3 files, 00169210-001692D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#include "short_string_data.h"

/* merge_units: begin func_00169210 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cStartLevelMsg_dtor, D_004DADD0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00169210 */

/* merge_units: begin func_00169270 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00169270, D_004D97F0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00169270 */

/* merge_units: begin func_001692D0 */
#pragma push /* merge_units */
/* String character data. */
DEFINE_SHORT_STRING_DATA(String_CStr)
#pragma pop /* merge_units */
/* merge_units: end func_001692D0 */
