#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" void Message_GetScriptTypeKey();
extern "C" void cGeneratorDataMessage_dtor();
extern "C" void cGeneratorDataMessage_Pack();
extern void * const D_004DB5E0[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004DB5E0); p->a24 = s->a24; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(cGeneratorDataMessage_Clone, Msg_0021C830, 44, D_004A4C78, 253, CLONE_BODY)
void * const D_004DB5E0[8] = { (void*)0x0, (void*)0x0, (void*)cGeneratorDataMessage_dtor, (void*)cGeneratorDataMessage_Clone, (void*)cGeneratorDataMessage_Pack, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
