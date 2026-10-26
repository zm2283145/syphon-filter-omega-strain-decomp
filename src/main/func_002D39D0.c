#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0xE8]; int i11C; int i120; char pad3[0x19]; unsigned char b13D; } Npc39D0;
void cNetNPC_ResumeAIAiming(Npc39D0* o)
{
    if (NpcAuth_IsLocal()) {
        o->i120 = 0;
        o->b13D = 1;
        o->i11C = -1;
    }
    NetEvent_Send(o->net, 0xB, 8, 0, 0, 0, 0);
}