#pragma cplusplus on
#include "types.h"
struct InvSlot_253DD0 { int a; int b; int item; int c; };
struct Inv_253DD0 { InvSlot_253DD0 s[8]; };
struct Tables_253DD0 { char pad[0x3524]; Inv_253DD0* inv; };
struct World_253DD0 { char pad[0x30]; Tables_253DD0* t; };
struct BP_253DD0 { char pad0[0x2F0]; unsigned char b2F0; char pad2F1[2]; unsigned char b2F3; };
extern "C" {
extern World_253DD0* g_LocalPlayer;
void cBackpack_Clear(BP_253DD0* bp, int a);
int cWeapon_GetAmmo(Inv_253DD0* inv, unsigned char slot);
int cWeapon_GetClipAmmo(Inv_253DD0* inv, unsigned char slot);
void cWeapon_RemoveWeapon(Inv_253DD0* inv, unsigned char slot, int a, int b, int c);
void cBackpack_AddWeapon(BP_253DD0* bp, int item, int spare, int clip, int e);
void cBackpack_CheckForRemoval(BP_253DD0* bp);
}
static inline void Steal(BP_253DD0* bp, Inv_253DD0* inv, unsigned char slot)
{
    if (slot != 8) {
        int spare;
        int item = inv->s[slot].item;
        if (item > -1) {
            spare = cWeapon_GetAmmo(inv, slot);
            cBackpack_AddWeapon(bp, item, spare, cWeapon_GetClipAmmo(inv, slot), 0);
            cWeapon_RemoveWeapon(inv, slot, 0, 0, 0);
        }
    }
}
extern "C" void cBackpack_StealPlayerWeapons(BP_253DD0* bp, unsigned char a, unsigned char b, unsigned char c)
{
    Inv_253DD0* inv = g_LocalPlayer->t->inv;
    cBackpack_Clear(bp, 1);
    bp->b2F3 = 1;
    bp->b2F0 = 0;
    Steal(bp, inv, a);
    Steal(bp, inv, b);
    Steal(bp, inv, c);
    cBackpack_CheckForRemoval(bp);
}


