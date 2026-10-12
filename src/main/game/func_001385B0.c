#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004D9160[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004D9160;

extern "C" { char D_0049AEC0[] = "lib_msg.hh"; }
DEFINE_MESSAGE_CLONE(func_001385B0, Msg_0020E560, 0x24, D_0049AEC0, 0x26, CLONE_BODY)
