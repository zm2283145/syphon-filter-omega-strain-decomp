#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3070;
extern void cNPC_v54(Npc3070* o);
void func_002D3070(Npc3070* o)
{
    if (NpcAuth_IsLocal())
        cNPC_v54(o);
    NetEvent_Send(o->net, 0x16, 8, 0, 0, 0, 0);
}