#include "types.h"
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
extern int Actor_IsArmed(Ctl_NPCW* c);
extern int Random_Next(void);
extern int WeaponInv_GetClipSize(void* inv, int slot);
static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (Actor_IsArmed(c)) {
        void* inv = c->inv;
        self->burst = (self->ctl->seed & 7) + 3;
        if (Random_Next() & 1)
            self->burst++;
        if (self->burst > WeaponInv_GetClipSize(inv, 6)) {
            int h = WeaponInv_GetClipSize(inv, 6) / 2;
            if (h <= 0)
                h = 1;
            self->burst = h;
        }
    } else {
        self->burst = 0;
    }
    self->burstCount = 0;
}typedef struct { char pad[0x84]; unsigned char cur; } Inv_B9E0;
extern void WeaponInv_Cycle(Inv_B9E0* inv, int wrap);
void cNPC_v6A(NPC_W* self)
{
    Inv_B9E0* inv = (Inv_B9E0*)self->ctl->inv;
    WeaponInv_Cycle(inv, 1);
    if (inv->cur == 6)
        WeaponInv_Cycle(inv, 1);
    ResetBurst(self);
}