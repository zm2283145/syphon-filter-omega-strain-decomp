#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
extern int Loc_FindKeyThunk(void* key);
#define PACK_BODY(e, b) MP_U(b, 0x8) = MP_U(e, 0x24); MP_I(b, 0x10) = MP_I(e, 0x28); MP_F(b, 0x14) = MP_F(e, 0x2C); MP_F(b, 0x18) = MP_F(e, 0x30); MP_I(b, 0x1C) = MP_I(e, 0x44); MP_U(b, 0x9) = MP_U(e, 0x48); MP_U(b, 0xA) = MP_U(e, 0x49); MP_I(b, 0xC) = Loc_FindKeyThunk((char*)(e) + 0x34);
DEFINE_MESSAGE_PACK(func_002C53A0, 0x20, D_0051EE40, PACK_BODY)
