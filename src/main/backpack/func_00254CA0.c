#include "types.h"
typedef struct { char pad[0x24]; int id; } Ent_4CA0;
typedef struct { union { unsigned char type; Ent_4CA0 ents[5]; } u; int pad; int count; unsigned char flag; char pad2[3]; } Slot_4CA0;
typedef struct { char pad[0x64]; Slot_4CA0 slots[3]; } Pack_4CA0;
extern int WeaponInv_SlotOfItem(int key);
#pragma opt_rotateloops off

int func_00254CA0(Pack_4CA0* s, int id, int back)
{
    Slot_4CA0* p; int i;
    int t;
     t = WeaponInv_SlotOfItem(id); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->u.type == (unsigned char)t) {
            int j = 0;
            if (j < p->count) {
                do {
                    if ((void*)p->u.ents[j].id == (void*)id) {
                        j += back ? -1 : 1;
                        if (j < 0) j = p->count - 1;
                        else if (j >= p->count) j = 0;
                        return p->u.ents[j].id;
                    }
                    j++;
                } while (j < p->count);
            }
        }
    }
    return id;
}
#pragma opt_rotateloops reset