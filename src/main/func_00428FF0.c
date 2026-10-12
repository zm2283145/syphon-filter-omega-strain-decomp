#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004E0E80[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004E0E80;

extern "C" { char D_004BF970[] = "DeactivateMsg.hh"; }
DEFINE_MESSAGE_CLONE(func_00428FF0, Msg_0022ED30, 0x24, D_004BF970, 0x13, CLONE_BODY)
