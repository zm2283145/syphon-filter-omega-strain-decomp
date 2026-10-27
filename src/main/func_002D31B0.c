#include "types.h"
#include "npc_auth.h"
typedef struct { unsigned char f0 : 1; unsigned char f1 : 1; unsigned char f2 : 1; } Bits31B0;
typedef struct { char pad[0x30]; void* net; char pad2[0x10D]; Bits31B0 bits; } Npc31B0;
void cNetNPC_DeactivateDead(Npc31B0* o, unsigned char v)
{
    if (NpcAuth_IsLocal())
        cNetNPCMsgs_SendMessage(o->net, 0x18, 4, v, 0, 0, 0);
    o->bits.f2 = v;
}