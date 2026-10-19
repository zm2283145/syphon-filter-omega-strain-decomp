#include "types.h"

typedef struct {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    void* target;
    char pad2[8];
} AIMsg;
typedef struct { char pad[0x30]; void* target; } NetCtx;
typedef struct { char pad[0x30]; void* owner; char pad2[0x28]; unsigned char disabled; } cAI;
extern NetCtx* g_LocalPlayer;
extern char g_ScriptAIActivatedMsgKey[];
extern void cAIActivatedMsg_dtor();
extern void cAIActivatedMsg_v01();
extern void cAIActivatedMsg_v02();
extern void cAIActivatedMsg_v03();
void * const D_004DCD30[8] = { (void*)0x0, (void*)0x0, (void*)cAIActivatedMsg_dtor, (void*)cAIActivatedMsg_v01, (void*)cAIActivatedMsg_v02, (void*)cAIActivatedMsg_v03, (void*)0x0, (void*)0x0 };
extern char D_004DCD70[];
extern void Event_Construct(AIMsg* msg, void* name);
extern void Event_Send(AIMsg* msg, void* target, int flags);
extern void cMessage_dtor(AIMsg* msg, int flags);

/* cAI virtual slot 0x10: unless disabled, sends a kind-2 message carrying the network target to the owner. */
void cAI_v10(cAI* self)
{
    if (!self->disabled) {
        AIMsg msg;
        void* target = g_LocalPlayer->target;
        unsigned char* kind;
        Event_Construct(&msg, g_ScriptAIActivatedMsgKey);
        msg.target = target;
        kind = &msg.kind;
        *kind = 2;
        msg.vtable = ((char*)D_004DCD30);
        msg.size = 0x40;
        *kind = 2;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = D_004DCD70;
        cMessage_dtor(&msg, 0);
    }
}
