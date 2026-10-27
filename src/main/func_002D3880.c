#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3880;
typedef struct { char pad[0x78]; int netId; } Node3880;
extern void cNPC_MoveToNode(Npc3880* o, Node3880* n);
int cNetNPC_MoveToNode(Npc3880* o, Node3880* n)
{
    if (NpcAuth_IsLocal())
        cNPC_MoveToNode(o, n);
    cNetNPCMsgs_SendMessage(o->net, 6, 8, *(volatile int*)&n->netId, 0, 0, 0);
    return 1;
}