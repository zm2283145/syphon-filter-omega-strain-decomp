#include "types.h"

typedef struct { char pad[0xA]; unsigned char mask; } MaskObj;
extern int GuiKeyboard_GetModifierIndex(void* self, MaskObj* obj);

/* Tests the mask bit (4 << slot) of obj, where slot comes from GuiKeyboard_GetModifierIndex. */
int func_0032C290(void* self, MaskObj* obj)
{
    int slot = GuiKeyboard_GetModifierIndex(self, obj);
    return (obj->mask & (4 << slot)) != 0;
}
