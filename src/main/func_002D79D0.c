#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_U(b, 0x10) = MP_U(e, 0x34); MP_F(b, 0x14) = MP_F(e, 0x38); MP_F(b, 0x18) = MP_F(e, 0x3C); MP_F(b, 0x1C) = MP_F(e, 0x40); MP_I(e, 0x1C) = 0x40;
DEFINE_MESSAGE_PACK(func_002D79D0, 0x20, D_0051F0C8, PACK_BODY)
