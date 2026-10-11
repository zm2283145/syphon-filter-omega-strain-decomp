#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB8B0[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DB8B0;

DEFINE_MESSAGE_CLONE(cNotifyCheckpointMsg_v01, Msg_0022ED30, 36, D_004A67D8, 73, CLONE_BODY)
