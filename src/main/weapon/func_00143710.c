#include "types.h"
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { int a; int b; int id; int d; } Slot_3710;
typedef struct { char pad[0x70]; int x70; } WDef_3710;
extern void* D_004FFD30;
extern WDef_3710* WeaponDb_Get(void* db, int id);
int func_00143710(INV* self, int id)
{
    if (id == -1 && self->cur != 6) id = self->e[self->cur].id;
    return id != -1 ? WeaponDb_Get(D_004FFD30, id)->x70 != 0 : 0;
}