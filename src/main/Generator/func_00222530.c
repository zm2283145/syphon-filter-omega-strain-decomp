#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB660[];
extern "C" char D_004DB620[];

struct Msg_00222530 : ClonedMessageBase {
    int a24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24; p->vtable = D_004DB620;

extern "C" { char D_004A4C98[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cDespawnedNPCMsg_v01, Msg_00222530, 40, D_004A4C98, 207, CLONE_BODY)
