#include "types.h"
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { char pad[0x24A2]; unsigned char flags[8]; } Own_2E00;
extern unsigned char D_00489D70[];
void WeaponInv_SetSlotModelState(INV* self, unsigned char slot, char v)
{
    if (*(int*)((char*)self + slot * 16 + 8) != -1)
        { Own_2E00* ow = (Own_2E00*)self->owner; ow->flags[D_00489D70[slot]] = v; }
}