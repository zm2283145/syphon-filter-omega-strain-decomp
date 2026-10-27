/*
 * SFOGame/Source/hud: 2 files, 00242DD0-00242E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00242DD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetCalloutMsg_dtor, D_004DE0F0, cMessage_dtor)
static inline void merge_flush_func_00242DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242DD0 */

/* merge_units: begin func_00242E30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_tCalloutPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_00242E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00242E30 */
