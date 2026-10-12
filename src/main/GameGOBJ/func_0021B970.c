#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DAED0[];

struct Msg_0021B970 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAED0; p->a24 = s->a24; p->a28 = s->a28;

extern "C" { char D_004A4A58[] = "gamegobj.hh"; }
DEFINE_MESSAGE_CLONE(cElevatorNotice_v01, Msg_0021B970, 44, D_004A4A58, 49, CLONE_BODY)
