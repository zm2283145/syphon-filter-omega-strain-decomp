#include "types.h"

typedef struct { char pad[0x40A]; short id; } Item_2BF370;
typedef struct { char pad[0x2410]; Item_2BF370* items[10]; } Inv_2BF370;
typedef struct { char pad[0x60]; Inv_2BF370 inv; } Owner_2BF370;
typedef struct {
    char pad0[0x4C];
    Owner_2BF370* owner;
    char pad50[0x94 - 0x50];
    void* list;
    int x;
    int total;
    int base;
    int step;
    char padA8[0x104 - 0xA8];
    int count;
    int sel;
    short ids[10];
} Self_2BF370;

extern void GuiWidget_SetPosition(void*, float, float);
extern void GuiEquipmentModify_UpdateList(Self_2BF370*);
extern void GuiEquipmentModify_UpdateCurrent(Self_2BF370*);
extern void GuiEquipmentModify_UpdateSelection(Self_2BF370*);

void GuiEquipmentModify_UpdateSelectionHand(Self_2BF370* self)
{
    int i;
    int span;
    int first;
    int off;
    int q;

    self->count = 0;
    for (i = 0; i < 10; i++) {
        if (i != 1 && i != 4 && i != 6 && i != 7) {
            Item_2BF370* it = ((Inv_2BF370*)((int)self->owner + 0x60))->items[i];
            if (it) {
                self->ids[self->count] = it->id;
                self->count++;
            }
        }
    }
    if (self->sel >= self->count)
        self->sel = 0;
    span = self->total - self->base;
    q = span / self->step;
    first = q - (self->count >> 1);
    off = span - q * self->step - 1;
    if (first < 0)
        first = 0;
    GuiWidget_SetPosition(self->list, (float)self->x, (float)(self->total - off - first * self->step));
    GuiEquipmentModify_UpdateList(self);
    GuiEquipmentModify_UpdateCurrent(self);
    GuiEquipmentModify_UpdateSelection(self);
}
