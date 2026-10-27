#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2EE0;
typedef struct { char pad[0x78]; int netId; } Node2EE0;
extern void cNPC_RestrictMovementToNodeGroup(Npc2EE0* o, Node2EE0* n);
void cNetNPC_RestrictMovementToNodeGroup(Npc2EE0* o, Node2EE0* n)
{
    if (NpcAuth_IsLocal())
        cNPC_RestrictMovementToNodeGroup(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x2F, 8, *(volatile int*)&n->netId, 0, 0, 0);
}