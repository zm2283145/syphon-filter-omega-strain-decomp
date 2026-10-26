#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3D00;
typedef struct { char pad[0xC]; int id; } Arg3D00;
void cNetNPC_ResendNewAwarenessMessage(Npc3D00* o, Arg3D00* a)
{
    int id = -1;
    void* n;
    if (!a) { n = o->net; } else { id = a->id; n = o->net; }
    NetEvent_Send(n, 0x35, 8, id, 0, 0, 0);
}