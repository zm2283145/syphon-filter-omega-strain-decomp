#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3170;
float cNetNPC_SetFiringThreshold(Npc3170* o, float v)
{
    NetEvent_Send(o->net, 0x1A, 8, *(volatile int*)&v, 0, 0, 0);
    return v;
}