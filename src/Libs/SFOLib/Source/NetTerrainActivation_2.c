/*
 * Libs/SFOLib/Source/NetTerrainActivation: 1 file, 00431EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00431EA0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_H(b, 0x8) = MP_I(e, 0x24); MP_H(b, 0xA) = MP_U(e, 0x28); MP_I(e, 0x1C) = 0x40;
DEFINE_MESSAGE_PACK(cNetTerrainActivation_Pack, 12, D_00582758, PACK_BODY)
static inline void merge_flush_func_00431EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431EA0 */
