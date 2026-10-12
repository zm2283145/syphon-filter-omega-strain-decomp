#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004D90E0[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004D90E0;

extern "C" { char D_0049AEB0[] = "player_msg.hh"; }
DEFINE_MESSAGE_CLONE(func_001383E0, Msg_0022ED30, 0x24, D_0049AEB0, 0x23, CLONE_BODY)
