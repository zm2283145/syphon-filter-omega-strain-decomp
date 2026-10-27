#include "types.h"
typedef struct { char pad[0x85]; unsigned char item; } Inv3CF0;
extern void cWeapon_DrawWeapon_eWpnSlot(Inv3CF0* p, int item);
void cWeapon_DrawLastWeaponUsed(Inv3CF0* p) {
    if (p->item != 6) {
        cWeapon_DrawWeapon_eWpnSlot(p, ((signed char*)p)[0x85]);
    }
}