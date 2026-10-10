#include "types.h"
typedef struct { char pad[0x40C]; unsigned char type; } EquipItem;
typedef struct { char pad[0x2410]; EquipItem* slots[8]; } EquipState;
extern void Equip_Init(EquipState* e, int slot, EquipItem* it);
void Equip_SetSlot(EquipState* e, int slot, EquipItem* it) {
    if (it) {
        int t = it->type;
        if (t < 0 || t >= 8) return;
    }
    e->slots[slot] = it;
    Equip_Init(e, slot, it);
}