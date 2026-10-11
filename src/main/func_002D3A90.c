#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3A90;
extern void cNPC_v43(Npc3A90* o, unsigned char v);
void func_002D3A90(Npc3A90* o, unsigned char v)
{
    if (NpcAuth_IsLocal())
        cNPC_v43(o, v);
    NetEvent_Send(o->net, 9, 8, v, 0, 0, 0);
}