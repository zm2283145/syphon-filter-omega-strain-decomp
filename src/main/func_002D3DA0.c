#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0x178]; void* body; } Npc3DA0;
typedef struct { char pad[0xC]; int id; } Arg3DA0;
extern void NpcPerception_RemoveAwareness(void* body, Arg3DA0* a);
void cNetNPC_RemoveAwareness(Npc3DA0* o, Arg3DA0* a)
{
    if (NpcAuth_IsLocal())
        NpcPerception_RemoveAwareness(o->body, a);
    NetEvent_Send(o->net, 0x29, 8, a->id, 0, 0, 0);
}