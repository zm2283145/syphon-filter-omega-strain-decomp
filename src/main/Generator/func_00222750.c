#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DB660[];

struct Msg_00222750 : ClonedMessageBase {
    int a24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DB660; p->a24 = s->a24;

extern "C" { char D_004A4CB8[] = "generator.hh"; }
DEFINE_MESSAGE_CLONE(cGeneratorMessageBase_v01, Msg_00222750, 40, D_004A4CB8, 163, CLONE_BODY)
