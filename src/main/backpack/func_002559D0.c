#include "types.h"
typedef struct { unsigned char type; char pad[0xCF]; unsigned char flag; char pad2[3]; } Slot2559;
typedef struct { char pad[0x64]; Slot2559 slots[3]; } Pack2559;
extern int WeaponInv_SlotOfItem(int key);
#pragma opt_rotateloops off
unsigned char func_002559D0(Pack2559* s, int key) {
    Slot2559* p; int i;
    int t;
    t = WeaponInv_SlotOfItem(key); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) return p->flag;
    }
    return 0;
}
#pragma opt_rotateloops reset
