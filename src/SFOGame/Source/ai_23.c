/*
 * SFOGame/Source/ai: 2 files, 0016DAB0-0016DB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016DAB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAINewAwarenessMsg_dtor, D_004DCC90, D_004DCD70, cMessage_dtor)
static inline void merge_flush_func_0016DAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DAB0 */

/* merge_units: begin func_0016DB20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copies.
 */


Word* std_list_cTargetAwarenessPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cTargetAwarenessPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}
static inline void merge_flush_func_0016DB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016DB20 */
