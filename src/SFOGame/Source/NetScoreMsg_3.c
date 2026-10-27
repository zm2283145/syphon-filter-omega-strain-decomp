/*
 * SFOGame/Source/NetScoreMsg: 1 file, 00316600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316600 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x28); MP_I(b, 0xC) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK(cNetScoreMsg_Pack, 20, D_0052ACA8, PACK_BODY)
static inline void merge_flush_func_00316600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316600 */
