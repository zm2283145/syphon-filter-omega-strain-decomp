#include "types.h"
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
extern int func_001B16C0(Ctl_NPCW* c);
extern int Random_Next(void);
extern int WeaponInv_GetClipSize(void* inv, int slot);
static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (func_001B16C0(c)) {
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
}extern int WeaponInv_SlotOfItem(int w);
extern void WeaponInv_RemoveSlot(void* inv, int slot, int a, int b, int c);
void cNPC_RemoveWeapon(NPC_W* self, int w)
{
    void* inv = self->ctl->inv;
    WeaponInv_RemoveSlot(inv, WeaponInv_SlotOfItem(w), 0, 0, 0);
    ResetBurst(self);
}