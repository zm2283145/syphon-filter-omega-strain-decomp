#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc35A0;
void cNetNPC_SetTravelSpeed(Npc35A0* o, float v)
{
    cNetNPCMsgs_SendMessage(o->net, 0x12, 8, *(volatile int*)&v, 0, 0, 0);
}