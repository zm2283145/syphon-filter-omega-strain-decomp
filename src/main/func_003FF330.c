#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_U(b, 8) = MP_I(e, 0x24); MP_U(b, 9) = MP_U(e, 0x28);

DEFINE_MESSAGE_PACK_NOTYPE(func_003FF330, 12, D_0055D490, PACK_BODY)