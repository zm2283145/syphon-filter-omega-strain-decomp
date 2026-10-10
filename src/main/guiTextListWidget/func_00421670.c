#include "guiTextListWidget_types.h"

/* Copy the state byte to the optional child widget. */
void func_00421670(TextListWidget* self, unsigned char state)
{
    self->state = state;
    if (self->child)
        self->child->state = state;
}
