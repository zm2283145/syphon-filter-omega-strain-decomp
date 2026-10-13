#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* D_004FFD30;
typedef struct { char pad[0x10C]; int x10C; } WD_3670;
extern WD_3670* WeaponDb_Get(void* db, int id);
int WeaponInv_HasSpareOfAmmoType(INV* self, int kind)
{
    int i;
    for (i = 0; i < 6; i++) {
        E_INV* e = &self->e[0];
        if (e->id != -1) {
            WD_3670* w = WeaponDb_Get(D_004FFD30, e->id);
            if (w->x10C == kind && e->ammo > 0)
                return 1;
        }
        self = (INV*)((char*)self + 16);
    }
    return 0;
}