#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB5E0[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB5E0; p->a24 = s->a24; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(func_0021C830, Msg_0021C830, 44, D_004A4C78, 253, CLONE_BODY)
