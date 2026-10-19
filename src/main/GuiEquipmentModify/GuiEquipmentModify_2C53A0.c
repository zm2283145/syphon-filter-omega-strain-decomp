/*
 * main/GuiEquipmentModify: 2 files, 002C53A0-002C5460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C53A0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
extern int Loc_FindKeyThunk(void* key);
#define PACK_BODY(e, b) MP_U(b, 0x8) = MP_U(e, 0x24); MP_I(b, 0x10) = MP_I(e, 0x28); MP_F(b, 0x14) = MP_F(e, 0x2C); MP_F(b, 0x18) = MP_F(e, 0x30); MP_I(b, 0x1C) = MP_I(e, 0x44); MP_U(b, 0x9) = MP_U(e, 0x48); MP_U(b, 0xA) = MP_U(e, 0x49); MP_I(b, 0xC) = Loc_FindKeyThunk((char*)(e) + 0x34);
DEFINE_MESSAGE_PACK(cNetCalloutMsg_Serialize, 0x20, D_0051EE40, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_002C53A0 */

/* merge_units: begin func_002C5460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetCopyMsg_dtor, D_004DE110, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002C5460 */
