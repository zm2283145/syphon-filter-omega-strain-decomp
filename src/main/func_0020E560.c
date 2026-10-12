#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DADD0[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DADD0;

extern "C" { char D_004A4078[] = "game_msg.hh"; }
DEFINE_MESSAGE_CLONE(cStartLevelMsg_v01, Msg_0020E560, 36, D_004A4078, 59, CLONE_BODY)
