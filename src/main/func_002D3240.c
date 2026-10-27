#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3240;
extern void cNPC_LookAround(Npc3240* o, int v);
void cNetNPC_LookAround(Npc3240* o, int v)
{
    if (NpcAuth_IsLocal())
        cNPC_LookAround(o, v);
    cNetNPCMsgs_SendMessage(o->net, 0x10, 8, v, 0, 0, 0);
}