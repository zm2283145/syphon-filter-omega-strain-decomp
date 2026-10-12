#include "types.h"
typedef struct { int pad0; int pad4; int id; int padC; } Slot_39B0;
typedef struct { Slot_39B0 slots[6]; } S_39B0;
int WeaponInv_CanChangeMode(S_39B0* self);
void WeaponInv_HolsterCurrent(S_39B0* self);
int WeaponInv_SlotOfItem(int id);
void WeaponInv_Equip(S_39B0* self, int slot);
unsigned char WeaponInv_EquipItem(S_39B0* self, int id)
{
    unsigned char r = 0;
    if (WeaponInv_CanChangeMode(self)) {
        if (id == -1) {
            WeaponInv_HolsterCurrent(self);
            r = 1;
        } else {
            int slot = WeaponInv_SlotOfItem(id);
            int* p = (int*)((char*)&self->slots[0].id + ((unsigned char)slot << 4));
            if (id == *p) {
                WeaponInv_Equip(self, slot);
                r = (id == *p);
            }
        }
    }
    return r;
}