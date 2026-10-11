#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad34[4]; float skill; } Npc0022F2D0;
void cNPC_SetSkill(Npc0022F2D0* self, float skill)
{
    self->skill = skill;
    if (D_005721C8 && NpcAuth_IsLocal())
        NetEvent_Send(self->net, 0x37, 4, *(volatile int*)&skill, 0, 0, 0);
}