/*
 * SFOGame/Source/NIEvent: 2 files, 0023A550-0023A560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023A550 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0023A550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A550 */

/* merge_units: begin func_0023A560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nievent_v10.h"

/* Event virtual 10: call slot 66 while inactive. */
DEFINE_NIEVENT_V10(cNIEventOBJ_NextFrame)
static inline void merge_flush_func_0023A560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A560 */
