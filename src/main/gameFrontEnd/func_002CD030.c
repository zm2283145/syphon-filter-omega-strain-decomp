#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DE220[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DE220;

DEFINE_MESSAGE_CLONE(func_002CD030, Msg_0020E560, 0x24, D_004AD1D8, 0x1C, CLONE_BODY)
