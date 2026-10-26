#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0xC]; int id; } Tgt002D33E0;
typedef struct { char pad[0x30]; void* net; } Npc002D33E0;
extern void cNPC_v48(Npc002D33E0* o, Tgt002D33E0* t, int x, float v);
void cNetNPC_RequestLookAt_cGOBJP_float_int(Npc002D33E0* o, Tgt002D33E0* t, int x, float v)
{
    if (NpcAuth_IsLocal()) cNPC_v48(o, t, x, v);
    NetEvent_Send(o->net, 0xE, 8, t->id, *(int*)&v, x, 0);
}
