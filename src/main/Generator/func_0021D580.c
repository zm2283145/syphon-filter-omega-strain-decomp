#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;

DEFINE_MESSAGE_PACK(cGeneratorMessageBase_v02, 20, D_004F56C8, PACK_BODY)
