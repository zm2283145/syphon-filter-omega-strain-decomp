#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DAF10[];

struct Msg_0021BB90 : ClonedMessageBase {
    int a24;
    int a28;
    int a2C;
    int a30;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAF10; p->a24 = s->a24; p->a28 = s->a28; p->a2C = s->a2C; p->a30 = s->a30;

extern "C" { char D_004A4A38[] = "gamegobj.hh"; }
DEFINE_MESSAGE_CLONE(cGOBJTriggerEventMsg_v01, Msg_0021BB90, 52, D_004A4A38, 112, CLONE_BODY)
