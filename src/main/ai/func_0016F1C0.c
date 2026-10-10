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
extern NetCtx* D_004FFC0C;
extern char D_004FF268[];
extern char D_004DCD30[];
extern char D_004DCD70[];
extern void Event_Construct(AIMsg* msg, void* name);
extern void Event_Send(AIMsg* msg, void* target, int flags);
extern void cMessage_dtor(AIMsg* msg, int flags);

/* cAI virtual slot 0x10: unless disabled, sends a kind-2 message carrying the network target to the owner. */
void cAI_v10(cAI* self)
{
    if (!self->disabled) {
        AIMsg msg;
        void* target = D_004FFC0C->target;
        unsigned char* kind;
        Event_Construct(&msg, D_004FF268);
        msg.target = target;
        kind = &msg.kind;
        *kind = 2;
        msg.vtable = D_004DCD30;
        msg.size = 0x40;
        *kind = 2;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = D_004DCD70;
        cMessage_dtor(&msg, 0);
    }
}
