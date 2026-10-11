#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* D_004FFD30;
typedef struct { char pad[0x78]; unsigned char x78; } WD_3820;
extern WD_3820* WeaponDb_Get(void* db, int id);
int func_00143820(INV* self)
{
    return self->cur != 6 ? WeaponDb_Get(D_004FFD30, *(int*)((char*)self + self->cur * 16 + 8))->x78 == 1 : 0;
}