#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3A90;
extern void cNPC_SetAimMode_eAimMode(Npc3A90* o, unsigned char v);
void cNetNPC_SetAimMode(Npc3A90* o, unsigned char v)
{
    if (NpcAuth_IsLocal())
        cNPC_SetAimMode_eAimMode(o, v);
    cNetNPCMsgs_SendMessage(o->net, 9, 8, v, 0, 0, 0);
}