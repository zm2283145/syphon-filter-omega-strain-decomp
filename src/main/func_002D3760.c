#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3760;
typedef struct { char pad[0x78]; int netId; } Gobj3760;
extern void cNPC_v35(Npc3760* o, unsigned char a, Gobj3760* g);
void func_002D3760(Npc3760* o, unsigned char a, Gobj3760* g)
{
    if (NpcAuth_IsLocal())
        cNPC_v35(o, a, g);
    NetEvent_Send(o->net, 1, 8, a, g ? g->netId : -1, 0, 0);
}