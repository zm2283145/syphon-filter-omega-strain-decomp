/*
 * Libs/SFOLib/Source/interface_gobj: 1 file, 003E9540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin callback_3E9540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

unsigned int D_00493980[2] = { 0x3F800000, 0x0 };

void cMAP_GOBJ_SetScale(float value) {
    (*(float*)D_00493980) = value;
}
static inline void merge_flush_callback_3E9540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end callback_3E9540 */
