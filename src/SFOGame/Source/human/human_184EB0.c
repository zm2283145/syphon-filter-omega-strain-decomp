/*
 * main/human: range (2 files, 00184EB0-00184F20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_00184EB0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(func_00184EB0, D_004E01E0, D_004E0840, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00184EB0 */

/* merge_units: begin func_00184F20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetShockMsg_dtor, D_004DA9F0, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00184F20 */
