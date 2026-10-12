#include "types.h"
typedef struct { char pad[0x85]; unsigned char item; } Inv3CF0;
extern void WeaponInv_Equip(Inv3CF0* p, int item);
void func_00143CF0(Inv3CF0* p) {
    if (p->item != 6) {
        WeaponInv_Equip(p, ((signed char*)p)[0x85]);
    }
}