#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2D3B10;
extern void cNPC_SetAggressiveness(Npc2D3B10* o, float v);
void cNetNPC_SetAggressiveness(Npc2D3B10* o, float v)
{
    if (NpcAuth_IsLocal()) cNPC_SetAggressiveness(o, v);
    NetEvent_Send(o->net, 8, 8, *(int*)&v, 0, 0, 0);
}
