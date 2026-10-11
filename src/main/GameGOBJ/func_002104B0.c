#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DAE90[];

struct Msg_002104B0 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAE90; p->a24 = s->a24; p->a28 = s->a28;

DEFINE_MESSAGE_CLONE(cPathedNotice_v01, Msg_002104B0, 44, D_004A4A48, 75, CLONE_BODY)
