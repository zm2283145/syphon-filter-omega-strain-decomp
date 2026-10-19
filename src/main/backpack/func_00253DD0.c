#pragma cplusplus on
#include "types.h"
struct InvSlot_253DD0 { int a; int b; int item; int c; };
struct Inv_253DD0 { InvSlot_253DD0 s[8]; };
struct Tables_253DD0 { char pad[0x3524]; Inv_253DD0* inv; };
struct World_253DD0 { char pad[0x30]; Tables_253DD0* t; };
struct BP_253DD0 { char pad0[0x2F0]; unsigned char b2F0; char pad2F1[2]; unsigned char b2F3; };
extern "C" {
extern World_253DD0* g_LocalPlayer;
void Backpack_Reset(BP_253DD0* bp, int a);
int WeaponInv_GetSpare(Inv_253DD0* inv, unsigned char slot);
int WeaponInv_GetClip(Inv_253DD0* inv, unsigned char slot);
void WeaponInv_RemoveSlot(Inv_253DD0* inv, unsigned char slot, int a, int b, int c);
void Backpack_AddWeapon(BP_253DD0* bp, int item, int spare, int clip, int e);
void Backpack_CheckEmpty(BP_253DD0* bp);
}
static inline void Steal(BP_253DD0* bp, Inv_253DD0* inv, unsigned char slot)
{
    if (slot != 8) {
        int spare;
        int item = inv->s[slot].item;
        if (item > -1) {
            spare = WeaponInv_GetSpare(inv, slot);
            Backpack_AddWeapon(bp, item, spare, WeaponInv_GetClip(inv, slot), 0);
            WeaponInv_RemoveSlot(inv, slot, 0, 0, 0);
        }
    }
}
extern "C" void cBackpack_StealPlayerWeapons(BP_253DD0* bp, unsigned char a, unsigned char b, unsigned char c)
{
    Inv_253DD0* inv = g_LocalPlayer->t->inv;
    Backpack_Reset(bp, 1);
    bp->b2F3 = 1;
    bp->b2F0 = 0;
    Steal(bp, inv, a);
    Steal(bp, inv, b);
    Steal(bp, inv, c);
    Backpack_CheckEmpty(bp);
}


