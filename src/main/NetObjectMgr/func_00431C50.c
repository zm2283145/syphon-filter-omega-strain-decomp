#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004E0F00[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004E0F00; p->a24 = s->a24; p->b28 = s->b28;

extern "C" { char D_004BFC50[] = "NetTerrainActivation.hh"; }
DEFINE_MESSAGE_CLONE(func_00431C50, Msg_0021C830, 0x2C, D_004BFC50, 0x17, CLONE_BODY)
