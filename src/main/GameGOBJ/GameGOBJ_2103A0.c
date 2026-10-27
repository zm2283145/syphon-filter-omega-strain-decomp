#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DAE70[];

struct Msg_002103A0 : ClonedMessageBase {
    int a24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DAE70; p->a24 = s->a24;

extern "C" { char D_004A41B8[] = "player_msg.hh"; }
DEFINE_MESSAGE_CLONE(cMaxActiveNpcCountMsg_Clone, Msg_002103A0, 40, D_004A41B8, 59, CLONE_BODY)
