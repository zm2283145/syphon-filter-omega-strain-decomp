#include "guiTextWidget_types.h"

/* Copy the state byte to the optional child widget. */
void func_0041C0F0(GuiTextStateOwnerF0* self, unsigned char state)
{
    self->state = state;
    if (self->child)
        self->child->state = state;
}
