#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" void Event_PackHeader();
extern "C" void cAIModeChangeMsg_dtor();
extern "C" void cAIModeChangeMsg_getSOBJClassId();
extern void * const D_004D92E0[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004D92E0); p->b24 = s->b24;

DEFINE_MESSAGE_CLONE(cAIModeChangeMsg_Clone, Msg_0023FF50, 0x28, D_0049C070, 0x2D5, CLONE_BODY)
void * const D_004D92E0[8] = { (void*)0x0, (void*)0x0, (void*)cAIModeChangeMsg_dtor, (void*)cAIModeChangeMsg_Clone, (void*)Event_PackHeader, (void*)cAIModeChangeMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
