#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" void Event_PackHeader();
extern "C" void PathedNotice_GetScriptType();
extern "C" void cPathedNotice_dtor();
extern void * const D_004DAE90[];

struct Msg_002104B0 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004DAE90); p->a24 = s->a24; p->a28 = s->a28;

DEFINE_MESSAGE_CLONE(cPathedNotice_v01, Msg_002104B0, 44, D_004A4A48, 75, CLONE_BODY)
void * const D_004DAE90[8] = { (void*)0x0, (void*)0x0, (void*)cPathedNotice_dtor, (void*)cPathedNotice_v01, (void*)Event_PackHeader, (void*)PathedNotice_GetScriptType, (void*)0x0, (void*)0x0 };
