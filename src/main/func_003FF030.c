#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004E0840[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004E0840; p->a24 = s->a24; p->b28 = s->b28;

extern "C" { char D_004BE550[] = "charActionMsg.hh"; }
DEFINE_MESSAGE_CLONE(func_003FF030, Msg_0021C830, 0x2C, D_004BE550, 0x98, CLONE_BODY)
