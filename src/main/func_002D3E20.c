#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0x178]; void* body; } Npc3E20;
typedef struct { char pad[0xC]; int id; } Arg3E20;
extern void NpcPerception_AddAwareness(void* body, Arg3E20* a, int f, float t);
void cNetNPC_AddAwareness(Npc3E20* o, Arg3E20* a)
{
    if (NpcAuth_IsLocal())
        NpcPerception_AddAwareness(o->body, a, 1, 0.0f);
    NetEvent_Send(o->net, 3, 8, a->id, 0, 0, 0);
}