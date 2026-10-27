/*
 * SFOGame/Source/GuiSubTitleDisplay: 2 files, 00459320-00459380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00459320 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_TextAtom_dtor, std_list_imp_TextAtom_dtor)
static inline void merge_flush_func_00459320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459320 */

/* merge_units: begin func_00459380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int std_vector_cLList_TextAtomPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00459380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459380 */
