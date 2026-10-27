/*
 * SFOGame/Source/BeamMsg: 1 file, 00282980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00282980 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int D_00506268;

/* Message type id for cNetUpdateTankMsg. */
int cNetUpdateTankMsg_GetMsgId(void) {
    return D_00506268;
}
static inline void merge_flush_func_00282980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282980 */
