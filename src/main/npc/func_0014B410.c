#include "types.h"
typedef struct { char pad[0xC]; int id; } Item_B410;
typedef struct {
    char pad[0x90]; float f90;
    char pad2[0x141 - 0x94];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 3;
    char pad3[0x1C8 - 0x142];
    Item_B410* item; int itemId;
} NPC_B410;
void cNPC_v65(NPC_B410* self, Item_B410* item, int flag, float f)
{
    int none;
    int* p;
    self->item = item;
    if (item)
        p = &item->id;
    else {
        none = -1;
        p = &none;
    }
    self->itemId = *p;
    self->f90 = f;
    self->b4 = flag;
}