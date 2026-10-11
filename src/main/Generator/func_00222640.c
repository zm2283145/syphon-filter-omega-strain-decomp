#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB660[];
extern "C" char D_004DB640[];

struct Msg_00222640 : ClonedMessageBase {
    int a24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB640;

DEFINE_MESSAGE_CLONE(cSpawnedNPCMsg_v01, Msg_00222640, 40, D_004A4CA8, 191, CLONE_BODY)
