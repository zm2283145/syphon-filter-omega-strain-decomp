#include "types.h"

typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[0xF];
} E3AIMsgF0;
typedef struct { char pad[0x30]; void* owner; char pad2[0x29]; unsigned char disabled; } E3cAIF0;
extern char g_ScriptAIDeactivatedMsgKey[];
extern void cAIDeactivatedMsg_dtor();
extern void cAIDeactivatedMsg_v01();
extern void cAIDeactivatedMsg_v02();
extern void cAIDeactivatedMsg_v03();
void * const D_004DCD10[8] = { (void*)0x0, (void*)0x0, (void*)cAIDeactivatedMsg_dtor, (void*)cAIDeactivatedMsg_v01, (void*)cAIDeactivatedMsg_v02, (void*)cAIDeactivatedMsg_v03, (void*)0x0, (void*)0x0 };
extern void Event_Construct(E3AIMsgF0* msg, void* name);
extern void Event_Send(E3AIMsgF0* msg, void* target, int flags);
extern void cMessage_dtor(E3AIMsgF0* msg, int flags);

/* cAI virtual slot 0x11: unless disabled, sends the AI-deactivated message to the owner. */
void cAI_v11(E3cAIF0* self)
{
    if (!self->disabled) {
        E3AIMsgF0 msg;
        unsigned char* kind;
        Event_Construct(&msg, g_ScriptAIDeactivatedMsgKey);
        msg.vtable = ((char*)D_004DCD10);
        kind = &msg.kind;
        *kind = 2;
        *kind = 2;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = ((char*)D_004DCD10);
        cMessage_dtor(&msg, 0);
    }
}