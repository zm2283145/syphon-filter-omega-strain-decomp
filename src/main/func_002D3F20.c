#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3F20;
extern void func_0016F490(Npc3F20* o, int v);
void func_002D3F20(Npc3F20* o, int v)
{
    NetEvent_Send(o->net, 0x24, 8, v, 0, 0, 0);
    if (NpcAuth_IsLocal())
        func_0016F490(o, v);
}