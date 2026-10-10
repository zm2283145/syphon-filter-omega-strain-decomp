#include "types.h"
typedef struct { char pad0[0x30]; int netId; char pad1[0x64]; int timer; char pad2[0xA5]; unsigned char rest : 7; unsigned char active : 1; } NpcB;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void NetEvent_Send(int id, int ev, int a, int b, int c, int d, int e);
static inline int NpcIsHost(void) { return D_005721C8 ? D_005721C0 : 1; }
void cNPC_v72(NpcB* self)
{
    if (D_005721C8 && NpcIsHost()) {
        NetEvent_Send(self->netId, 0x34, 4, 0, 0, 0, 0);
    }
    self->timer = 0;
    self->active = 0;
}