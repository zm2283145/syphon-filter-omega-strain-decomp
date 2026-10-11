#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004D92E0[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004D92E0; p->b24 = s->b24;

DEFINE_MESSAGE_CLONE(cAIModeChangeMsg_v01, Msg_0023FF50, 0x28, D_0049C070, 0x2D5, CLONE_BODY)
