#include "loose05_types.h"

extern void func_0043BC70(GuiWidget43BEF0* self, unsigned char mode, int value,
                         int lower, int upper);

/* Synchronize the optional range widget with the text's current extent. */
void func_0043E290(MLTextWidget* self) {
    if (self->rangeWidget != 0) {
        func_0043BC70(self->rangeWidget, 0, self->unk68, 0,
                     self->unk70 - self->unk64);
    }
}
