#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2DE0;
typedef struct { char pad[0x78]; int netId; } Node2DE0;
extern void cNPC_RemoveGroupFromPathRegion(Npc2DE0* o, Node2DE0* n);
void cNetNPC_RemoveGroupFromPathRegion(Npc2DE0* o, Node2DE0* n)
{
    if (NpcAuth_IsLocal())
        cNPC_RemoveGroupFromPathRegion(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x31, 8, *(volatile int*)&n->netId, 0, 0, 0);
}