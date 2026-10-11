#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DC2D0[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DC2D0; p->b24 = s->b24;

DEFINE_MESSAGE_CLONE(func_0023FF50, Msg_0023FF50, 40, D_004A71B8, 105, CLONE_BODY)
