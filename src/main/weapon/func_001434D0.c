#include "types.h"
typedef struct { int unk0; int unk4; int id; int unkC; } D6InvSlot;
int Inventory_HasAnyItem(D6InvSlot* s)
{
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s->id != -1) {
            return 1;
        }
    }
    return 0;
}