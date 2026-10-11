#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DBB40[];

struct Msg_00237260 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DBB40; p->a24 = s->a24; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(cNetSpawnParticleMsg_v01, Msg_00237260, 44, D_004A6E38, 1716, CLONE_BODY)
