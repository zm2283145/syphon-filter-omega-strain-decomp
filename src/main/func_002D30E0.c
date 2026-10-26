#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2D30E0;
extern void cNPC_StopMovement(Npc2D30E0* o, int x, float v);
void cNetNPC_StopMovement(Npc2D30E0* o, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_StopMovement(o, x, v);
    NetEvent_Send(o->net, 0x15, 8, (int)v, x, 0, 0);
}
