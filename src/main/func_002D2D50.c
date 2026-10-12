#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0xC]; int id; } Tgt2D2D50;
typedef struct { char pad[0x30]; void* net; } Npc2D2D50;
extern void cNPC_v3D(Npc2D2D50* o, Tgt2D2D50* t, float a, float b);
void func_002D2D50(Npc2D2D50* o, Tgt2D2D50* t, float a, float b)
{
    if (NpcAuth_IsLocal()) cNPC_v3D(o, t, a, b);
    NetEvent_Send(o->net, 0x32, 8, t->id, *(int*)&a, *(int*)&b, 0);
}
