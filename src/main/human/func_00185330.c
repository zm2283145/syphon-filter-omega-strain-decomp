#include "types.h"
typedef struct { char pad[0x3524]; void* weapons; } H_185330;
typedef struct { char pad[0x30]; H_185330* player; } G_185330;
extern G_185330* D_004FFC0C;
extern void WeaponInv_ClearSlots(void* w);
extern void WeaponInv_Add(void* w, int id, int a, int b, int c, int d);
extern int WeaponInv_SlotOfItem(int id);
extern void WeaponInv_Equip(void* w, int slot);
int Script_SetPlayerWeapons(int* args)
{
    volatile int b;
    volatile int a;
    int pa;
    int pb;
    void* w;
    b = args[1];
    pb = b;
    a = args[0];
    pa = a;
    w = D_004FFC0C->player->weapons;
    WeaponInv_ClearSlots(w);
    if (pa > -1) WeaponInv_Add(w, pa, 1, 0, 1, 0);
    if (pb > -1) {
        WeaponInv_Add(w, pb, 1, 0, 1, 0);
        if (pa < 0) pa = pb;
    }
    if (pa >= 0) WeaponInv_Equip(w, WeaponInv_SlotOfItem(pa));
    return 0;
}
