#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DA890[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DA890;

DEFINE_MESSAGE_CLONE(func_001B96B0, Msg_0020E560, 0x24, D_0049D8D0, 0xEF, CLONE_BODY)
