/*
 * main/character: 2 files, 003E5FD0-003E6060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E5FD0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define Event_PackHeader func_003FF330
#define PACK_BODY(e, b) MP_F(b, 0xC) = MP_F(e, 0x30); MP_F(b, 0x10) = MP_F(e, 0x34); MP_F(b, 0x14) = MP_F(e, 0x38); MP_F(b, 0x18) = MP_F(e, 0x3C);
DEFINE_MESSAGE_PACK_NOTYPE(func_003E5FD0, 28, D_0055A1E8, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003E5FD0 */

/* merge_units: begin func_003E6060 */
#pragma push /* merge_units */
#undef PACK_BODY /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x30); MP_F(b, 0x14) = MP_F(e, 0x34); MP_U(b, 0x18) = MP_U(e, 0x38);
DEFINE_MESSAGE_PACK_NOTYPE(func_003E6060, 28, D_0055A200, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003E6060 */
