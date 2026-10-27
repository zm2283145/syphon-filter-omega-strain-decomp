#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3BB0;
extern void cNPC_ActivateByRadiusOff(Npc3BB0* o);
void cNetNPC_ActivateByRadiusOff(Npc3BB0* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ActivateByRadiusOff(o);
    cNetNPCMsgs_SendMessage(o->net, 0x34, 8, 0, 0, 0, 0);
}