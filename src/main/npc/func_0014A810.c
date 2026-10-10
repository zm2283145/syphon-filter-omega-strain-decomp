#include "types.h"
typedef struct { char pad[0x30]; void* actor; } cNPC;
extern unsigned char D_005721C8;
extern void func_001B8750(void* actor, int on);
extern void NetEvent_Send(void* actor, int id, int size, unsigned char value, int a, int b, int c);
/* Sets invulnerability and replicates it when networked and not silent. */
void cNPC_SetInvulnerable(cNPC* npc, int on, int silent)
{
    func_001B8750(npc->actor, on);
    if (D_005721C8 && !silent)
        NetEvent_Send(npc->actor, 0x2E, 4, on, 0, 0, 0);
}
