#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } S23E0;
extern void WeaponInv_RemoveSlot(void* self, unsigned char slot, int a, int b, int c);
void WeaponInv_ClearSlots(S23E0* self)
{
    int i;
    S23E0* p;
    i = 0;
    p = self;
    do {
        if (p->id != -1)
            WeaponInv_RemoveSlot(self, i, 0, 1, 0);
        i++;
        p++;
    } while (i < 6);
}