#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b)

DEFINE_MESSAGE_PACK_PRE(func_00431900, 8, D_00582738, PACK_PRE, PACK_BODY)