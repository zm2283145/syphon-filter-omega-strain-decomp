/*
 * SFOGame/Source/Generator: 1 file, 0021D420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D420 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_S(b, 8) = 2;
DEFINE_MESSAGE_PACK_DERIVED(cDespawnedNPCMsg_Pack, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
static inline void merge_flush_func_0021D420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D420 */
