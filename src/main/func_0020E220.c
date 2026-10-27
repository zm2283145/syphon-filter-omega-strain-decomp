#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DADB0[];

struct Msg_0020E220 : ClonedMessageBase {
    char b24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DADB0; p->b24 = s->b24; p->a28 = s->a28;

extern "C" { char D_004A4068[] = "game_msg.hh"; }
DEFINE_MESSAGE_CLONE(cEndLevelMsg_Clone, Msg_0020E220, 44, D_004A4068, 81, CLONE_BODY)
