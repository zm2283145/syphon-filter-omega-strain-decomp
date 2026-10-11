#include "types.h"
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { char pad[0xA8]; unsigned char xA8; } WDef_2320;
extern void* D_004FFD30;
extern WDef_2320* WeaponDb_Get(void* db, int id);
extern void func_00255AF0(void* o, int id, int d, int c, int z);
extern void func_00142450(INV* self, unsigned char slot, int a, int b, int c);
void func_00142320(INV* self, void* o)
{
    int i;
    if (self->lock)
        return;
    for (i = 7; i >= 0; i--) {
        E_INV* e = (E_INV*)((char*)self + i * 16 + 4);
        if (e->id != -1 && WeaponDb_Get(D_004FFD30, e->id)->xA8) {
            func_00255AF0(o, e->id, e->d, e->c, 0);
            func_00142450(self, i, 0, 0, 0);
        }
    }
}