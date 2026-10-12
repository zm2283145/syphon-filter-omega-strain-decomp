#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DE5F0[];

struct Msg_002104B0 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DE5F0; p->a24 = s->a24; p->a28 = s->a28;

extern "C" { char D_004B3580[] = "NetShatterMsg.hh"; }
DEFINE_MESSAGE_CLONE(func_003166B0, Msg_002104B0, 0x2C, D_004B3580, 0x15, CLONE_BODY)
