#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0xC]; int id; } Tgt002D3340;
typedef struct { char pad[0x30]; void* net; } Npc002D3340;
extern void cNPC_v49(Npc002D3340* o, Tgt002D3340* t, int x, float v);
void func_002D3340(Npc002D3340* o, Tgt002D3340* t, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_v49(o, t, x, v);
    NetEvent_Send(o->net, 0xF, 8, t->id, *(int*)&v, x, 0);
}
