#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } E3A60;
typedef struct { E3A60 e[8]; char pad[4]; unsigned char cur; } S3A60;
extern int WeaponInv_CanChangeMode(S3A60* self);
extern void WeaponInv_EquipFirst(S3A60* self);
extern void WeaponInv_Equip(S3A60* self, unsigned char slot, int a, unsigned char prev);
extern void WeaponInv_Holster(S3A60* self, char slot, int a, unsigned char prev);
#pragma opt_rotateloops off
#pragma opt_propagation off
void WeaponInv_Cycle(S3A60* self, int wrap)
{
    unsigned char cur;
    int i;
    unsigned char stop;
    int one;
    if (WeaponInv_CanChangeMode(self)) {
        cur = self->cur;
        if (cur == 6) {
            WeaponInv_EquipFirst(self);
            return;
        }
        i = cur + 1;
        stop = wrap ? 6 : *(char*)&self->cur;
        one = 1;
        while (i != stop && (i == one || self->e[i].id == -1 || i == 6)) {
            i++;
            if (!wrap && i >= 6)
                i = 0;
        }
        if (i != cur && i != 6) {
            WeaponInv_Equip(self, i, one, cur);
            return;
        }
        if (wrap)
            WeaponInv_Holster(self, *(char*)&self->cur, one, cur);
    }
}
#pragma opt_rotateloops reset
#pragma opt_propagation reset
