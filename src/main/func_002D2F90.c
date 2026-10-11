#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2F90;
extern void cNPC_v73(Npc2F90* o, unsigned char v, int send);
void func_002D2F90(Npc2F90* o, unsigned char v, int send)
{
    if (send)
        NetEvent_Send(o->net, 0x21, 4, v, 0, 0, 0);
    cNPC_v73(o, v, 0);
}