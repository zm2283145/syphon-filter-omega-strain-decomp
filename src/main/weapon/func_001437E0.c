#include "types.h"
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
extern void* D_004FFD30;
extern void* WeaponDb_Get(void* db, int id);
void* func_001437E0(INV* self)
{
    return self->cur != 6 ? WeaponDb_Get(D_004FFD30, *(int*)((char*)self + self->cur * 16 + 8)) : 0;
}