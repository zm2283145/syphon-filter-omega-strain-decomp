#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc36C0;
typedef struct { char pad[0xC]; int id; } Arg36C0;
typedef struct { char pad[0x78]; int netId; } Gobj36C0;
extern void cNPC_v40(Npc36C0* o, Arg36C0* a, Gobj36C0* g);
int cNetNPC_CarryBodyToNode(Npc36C0* o, Arg36C0* a, Gobj36C0* g)
{
    int id;
    if (NpcAuth_IsLocal())
        cNPC_v40(o, a, g);
    if (g)
        id = g->netId;
    else
        id = -1;
    NetEvent_Send(o->net, 0x25, 8, a->id, id, 0, 0);
    return 1;
}