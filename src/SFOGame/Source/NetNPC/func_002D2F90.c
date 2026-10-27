#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2F90;
extern void cNPC_SetPickupable(Npc2F90* o, unsigned char v, int send);
void cNetNPC_SetPickupable(Npc2F90* o, unsigned char v, int send)
{
    if (send)
        cNetNPCMsgs_SendMessage(o->net, 0x21, 4, v, 0, 0, 0);
    cNPC_SetPickupable(o, v, 0);
}