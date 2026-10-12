#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* D_004FFD30;
typedef struct { char pad[0x70]; int x70; } WD_38E0;
extern WD_38E0* WeaponDb_Get(void* db, int id);
int WeaponInv_GetClipSize(INV* self, char slot)
{
    if ((unsigned char)slot == 6)
        slot = self->cur;
    if ((unsigned char)slot != 6)
        return WeaponDb_Get(D_004FFD30, *(int*)((char*)self + (unsigned char)slot * 16 + 8))->x70;
    return 0;
}