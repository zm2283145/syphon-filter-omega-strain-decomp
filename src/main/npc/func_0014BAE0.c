#include "types.h"
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
extern int func_001B16C0(Ctl_NPCW* c);
extern int Random_Next(void);
extern int func_001438E0(void* inv, int slot);
static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (func_001B16C0(c)) {
        void* inv = c->inv;
        self->burst = (self->ctl->seed & 7) + 3;
        if (Random_Next() & 1)
            self->burst++;
        if (self->burst > func_001438E0(inv, 6)) {
            int h = func_001438E0(inv, 6) / 2;
            if (h <= 0)
                h = 1;
            self->burst = h;
        }
    } else {
        self->burst = 0;
    }
    self->burstCount = 0;
}extern void func_001439B0(void* inv, int w);
extern void func_00143C50(void* inv);
void cNPC_v69(NPC_W* self, int w)
{
    Ctl_NPCW* c = self->ctl;
    if (w >= 0)
        func_001439B0(c->inv, w);
    else
        func_00143C50(c->inv);
    ResetBurst(self);
}