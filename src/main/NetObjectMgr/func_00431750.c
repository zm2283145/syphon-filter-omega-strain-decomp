#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004E0EC0[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004E0EC0;

extern "C" { char D_004BFBE0[] = "NetPlayGameMsg.hh"; }
DEFINE_MESSAGE_CLONE(func_00431750, Msg_0020E560, 0x24, D_004BFBE0, 0x10, CLONE_BODY)
