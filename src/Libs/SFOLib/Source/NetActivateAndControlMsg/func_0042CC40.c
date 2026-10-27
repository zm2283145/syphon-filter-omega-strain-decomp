#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e)
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK_PRE(cNetActivateAndControlMsg_Pack, 12, D_00582688, PACK_PRE, PACK_BODY)