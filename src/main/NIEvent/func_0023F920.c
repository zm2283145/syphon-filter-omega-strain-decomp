#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(func_0023F920, 12, D_004F7C48, PACK_PRE, PACK_BODY)
