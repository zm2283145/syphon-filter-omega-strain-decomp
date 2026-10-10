#include "types.h"
typedef struct { char pad0[2]; unsigned char valid; char pad1[0x6D]; int mask; char pad2[0x2C]; } HgSlot;
typedef struct { char pad0[0x3E0]; HgSlot slots[7]; } HgActor;
int func_001E9290(HgActor* a)
{
    HgSlot* s;
    s = &a->slots[6];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[5];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[3];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    return 0;
}
