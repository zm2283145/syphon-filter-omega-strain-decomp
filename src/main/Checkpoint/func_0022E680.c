#include "types.h"
#include "message_pack.h"
extern char* strncpy(char* d, const char* s, unsigned int n);

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(MP_P(e, 0x24), 0xC); strncpy(b + 0xC, MP_P(e, 0x28), 0x40);

DEFINE_MESSAGE_PACK(cAddCheckpointMsg_v02, 76, D_004F7948, PACK_BODY)
