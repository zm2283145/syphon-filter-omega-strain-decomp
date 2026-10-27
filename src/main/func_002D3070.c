#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3070;
extern void cNPC_ResumeMovement(Npc3070* o);
void cNetNPC_ResumeMovement(Npc3070* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeMovement(o);
    cNetNPCMsgs_SendMessage(o->net, 0x16, 8, 0, 0, 0, 0);
}