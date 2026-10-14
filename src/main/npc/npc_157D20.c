/*
 * main/npc: range (2 files, 00157D20-00157D90)
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

/* merge_units: begin func_00157D20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(func_00157D20, D_004DB600, D_004DB660, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00157D20 */

/* merge_units: begin func_00157D90 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cGeneratorMessageBase_dtor, D_004DB660, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00157D90 */
