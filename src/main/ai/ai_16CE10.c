/*
 * main/ai: range (2 files, 0016CE10-0016CE80)
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

/* merge_units: begin func_0016CE10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIPickupableAwarenessMsg_dtor, D_004DCBD0, D_004DCD70, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0016CE10 */

/* merge_units: begin func_0016CE80 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIGOBJMsg_dtor, D_004DCD70, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0016CE80 */
