#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc32C0;
extern void cNPC_ResumeAILookAt(Npc32C0* o, int v);
void cNetNPC_ResumeAILookAt(Npc32C0* o, int v)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeAILookAt(o, v);
    cNetNPCMsgs_SendMessage(o->net, 0x11, 8, v, 0, 0, 0);
}