#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DAE50[];

struct Msg_0020FEC0 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DAE50; p->b24 = s->b24;

extern "C" { char D_004A41A8[] = "player_msg.hh"; }
DEFINE_MESSAGE_CLONE(cAtmosphericEffectMsg_v01, Msg_0020FEC0, 40, D_004A41A8, 86, CLONE_BODY)
