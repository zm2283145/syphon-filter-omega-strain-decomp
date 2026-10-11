#include "types.h"
typedef struct { char pad[0x2C]; unsigned char x2C; unsigned char x2D; unsigned char x2E; char pad2[0x3469 - 0x2F]; unsigned char disguise; } Ctl_AC90;
typedef struct { char pad[0x30]; Ctl_AC90* ctl; } NPC_AC90;
extern unsigned char D_005721C8;
extern void NetEvent_Send(Ctl_AC90* c, int id, int kind, int v, int a, int b, int d);
void cNPC_SetHasDisguise(NPC_AC90* self, unsigned char v, int send)
{
    Ctl_AC90* c = self->ctl;
    unsigned char cur = c->x2D && c->x2C && !c->x2E && c->disguise;
    if (v != cur) {
        c->disguise = v;
        if (D_005721C8 && send)
            NetEvent_Send(self->ctl, 0x39, 4, v, 0, 0, 0);
    }
}