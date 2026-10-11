#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e)
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(func_00440160, 12, D_00583988, PACK_PRE, PACK_BODY)