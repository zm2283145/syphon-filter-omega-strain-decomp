#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB660[];
extern "C" char D_004DB600[];

struct Msg_00222410 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB600; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(func_00222410, Msg_00222410, 44, D_004A4C88, 227, CLONE_BODY)
