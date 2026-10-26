#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x24); MP_S(b, 8) = MP_S(e, 0x28);

DEFINE_MESSAGE_PACK(cGeneratorDataMessage_Pack, 16, D_004F56D0, PACK_BODY)
