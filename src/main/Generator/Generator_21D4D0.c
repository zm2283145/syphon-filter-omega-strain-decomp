/*
 * main/Generator: range (2 files, 0021D4D0-0021D580)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "message_pack.h"

/* merge_units: begin func_0021D4D0 */
#pragma push /* merge_units */
#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_S(b, 8) = 1;
DEFINE_MESSAGE_PACK_DERIVED(cSpawnedNPCMsg_v02, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
#pragma pop /* merge_units */
/* merge_units: end func_0021D4D0 */

/* merge_units: begin func_0021D580 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;

DEFINE_MESSAGE_PACK(cGeneratorMessageBase_v02, 20, D_004F56C8, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0021D580 */
