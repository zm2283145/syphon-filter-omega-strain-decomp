#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DAEF0[];

struct Msg_0021BA80 : ClonedMessageBase {
    int a24;
    unsigned char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAEF0; p->a24 = s->a24; p->b28 = s->b28;

extern "C" { char D_004A4A28[] = "gamegobj.hh"; }
DEFINE_MESSAGE_CLONE(func_0021BA80, Msg_0021BA80, 44, D_004A4A28, 163, CLONE_BODY)
