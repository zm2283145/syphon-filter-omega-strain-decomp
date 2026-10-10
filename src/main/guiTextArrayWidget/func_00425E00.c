#include "guiTextArrayWidget_types.h"

/* Copy the state byte to the optional child widget. */
void func_00425E00(guiTextArrayWidget* self, unsigned char state)
{
    self->unk98 = state;
    if (self->child)
        self->child->state = state;
}
