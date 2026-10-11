#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define Event_PackHeader func_003FF330
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x30); MP_F(b, 0x14) = MP_F(e, 0x34); MP_U(b, 0x18) = MP_U(e, 0x38);
DEFINE_MESSAGE_PACK_NOTYPE(func_003E6060, 28, D_0055A200, PACK_BODY)
