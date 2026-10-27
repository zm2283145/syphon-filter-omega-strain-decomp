#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3690;
typedef struct { char pad[0x78]; int netId; } Gobj3690;
void cNetNPC_Teleport(Npc3690* o, Gobj3690* g)
{
    int id;
    if (g)
        id = g->netId;
    else
        id = -1;
    cNetNPCMsgs_SendMessage(o->net, 7, 8, id, 0, 0, 0);
}