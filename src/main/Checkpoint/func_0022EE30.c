#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB8D0[];

struct Msg_0022EE30 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB8D0; p->a24 = s->a24; p->a28 = s->a28;

extern "C" { char D_004A67E8[] = "Checkpoint.hh"; }
DEFINE_MESSAGE_CLONE(cAddCheckpointMsg_v01, Msg_0022EE30, 44, D_004A67E8, 35, CLONE_BODY)
