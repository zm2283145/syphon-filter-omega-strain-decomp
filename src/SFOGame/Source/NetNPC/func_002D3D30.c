#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3D30;
extern void cNPC_AddAwarenessOfPlayers(Npc3D30* o);
void cNetNPC_AddAwarenessOfPlayers(Npc3D30* o)
{
    if (NpcAuth_IsLocal())
        cNPC_AddAwarenessOfPlayers(o);
    cNetNPCMsgs_SendMessage(o->net, 4, 8, 0, 0, 0, 0);
}