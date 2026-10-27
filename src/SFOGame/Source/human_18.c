/*
 * main/human: range (2 files, 00188070-001880E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_00188070 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIUnconsciousMsg_dtor, D_004DCC30, D_004DCD70, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00188070 */

/* merge_units: begin func_001880E0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cDamageMsg_dtor, D_004E08A0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001880E0 */
