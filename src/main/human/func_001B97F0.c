#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DA8B0[];

struct Msg_0020FEC0 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DA8B0; p->b24 = s->b24;

extern "C" { char D_0049EDA8[] = "human.cc"; }
DEFINE_MESSAGE_CLONE(cEquipGogglesMsg_v01, Msg_0020FEC0, 0x28, D_0049EDA8, 0x2F89, CLONE_BODY)
