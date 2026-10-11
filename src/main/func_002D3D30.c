#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3D30;
extern void cNPC_v39(Npc3D30* o);
void func_002D3D30(Npc3D30* o)
{
    if (NpcAuth_IsLocal())
        cNPC_v39(o);
    NetEvent_Send(o->net, 4, 8, 0, 0, 0, 0);
}