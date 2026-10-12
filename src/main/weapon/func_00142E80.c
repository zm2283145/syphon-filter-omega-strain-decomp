#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* D_004FFD30;
typedef struct { char pad[0xF4]; int xF4; } WD_2E80;
extern WD_2E80* WeaponDb_Get(void* db, int id);
int WeaponInv_GetCarriedValue(INV* self)
{
    int best = 0;
    int i = 0;
    INV* p = self;
    do {
        if ((p->e[0].flag || i == self->cur) && p->e[0].id != -1) {
            int v = WeaponDb_Get(D_004FFD30, p->e[0].id)->xF4;
            if (best < v)
                best = v;
        }
        i++;
        p = (INV*)((char*)p + 16);
    } while (i < 6);
    return best;
}