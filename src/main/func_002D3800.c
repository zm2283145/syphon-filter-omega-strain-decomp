#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3800;
typedef struct { char pad[0xC]; int id; } Gobj3800;
extern void cNPC_MoveToGobj(Npc3800* o, Gobj3800* g);
int cNetNPC_MoveToGobj(Npc3800* o, Gobj3800* g)
{
    if (NpcAuth_IsLocal())
        cNPC_MoveToGobj(o, g);
    cNetNPCMsgs_SendMessage(o->net, 0x2C, 8, g->id, 0, 0, 0);
    return 1;
}