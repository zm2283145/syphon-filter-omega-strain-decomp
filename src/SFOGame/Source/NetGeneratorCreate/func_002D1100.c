#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x50); MP_I(b, 0xC) = MP_I(e, 0x54); MP_I(b, 0x10) = MP_I(e, 0x58); MP_F(b, 0x14) = MP_F(e, 0x40); MP_F(b, 0x18) = MP_F(e, 0x44); MP_F(b, 0x1C) = MP_F(e, 0x48); MP_F(b, 0x20) = MP_F(e, 0x30); MP_F(b, 0x24) = MP_F(e, 0x34); MP_F(b, 0x28) = MP_F(e, 0x38); MP_I(b, 0x2C) = MP_I(e, 0x5C); MP_I(b, 0x30) = MP_I(e, 0x60);
DEFINE_MESSAGE_PACK(cNetGeneratorCreateMsg_Pack, 0x34, D_0051F060, PACK_BODY)
