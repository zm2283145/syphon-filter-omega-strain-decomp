#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3EB0;
extern void cNPC_ResumeAIMode(Npc3EB0* o);
void cNetNPC_ResumeAIMode(Npc3EB0* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeAIMode(o);
    cNetNPCMsgs_SendMessage(o->net, 2, 8, 0, 0, 0, 0);
}