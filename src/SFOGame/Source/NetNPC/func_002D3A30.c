#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0xE8]; int i11C; } Npc3A30;
void cNetNPC_SetAimSubtarget(Npc3A30* o, signed char v)
{
    if (NpcAuth_IsLocal())
        o->i11C = v;
    cNetNPCMsgs_SendMessage(o->net, 0xA, 8, v, 0, 0, 0);
}