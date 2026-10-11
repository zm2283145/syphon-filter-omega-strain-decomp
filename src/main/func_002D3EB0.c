#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3EB0;
extern void cNPC_v36(Npc3EB0* o);
void func_002D3EB0(Npc3EB0* o)
{
    if (NpcAuth_IsLocal())
        cNPC_v36(o);
    NetEvent_Send(o->net, 2, 8, 0, 0, 0, 0);
}