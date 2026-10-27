#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2E60;
typedef struct { char pad[0x78]; int netId; } Node2E60;
extern void cNPC_AddGroupToPathRegion(Npc2E60* o, Node2E60* n);
void cNetNPC_AddGroupToPathRegion(Npc2E60* o, Node2E60* n)
{
    if (NpcAuth_IsLocal())
        cNPC_AddGroupToPathRegion(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x30, 8, *(volatile int*)&n->netId, 0, 0, 0);
}