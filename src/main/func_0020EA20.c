#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x30); *(__int128*)(b + 0x10) = *(__int128*)((char*)e + 0x40); MP_I(b, 0x20) = MP_I(e, 0x1B0); MP_U(b, 0x24) = MP_U(e, 0x1C0);

DEFINE_MESSAGE_PACK(cStopSoundMsg_Pack, 48, D_004F53E0, PACK_BODY)
