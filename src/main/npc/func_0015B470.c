#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004D9300[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004D9300; p->b24 = s->b24;

DEFINE_MESSAGE_CLONE(func_0015B470, Msg_0023FF50, 0x28, D_0049C050, 0xE, CLONE_BODY)
