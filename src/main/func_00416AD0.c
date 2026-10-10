#include "loose04_types.h"

extern char D_004E09B0[];
extern int D_00572130;
extern void operator_delete(void* allocation);

/* Restore the base vtable, release the instance count, and optionally delete. */
GuiObject* func_00416AD0(GuiObject* self, short deleteFlag) {
    if (self != 0) {
        self->vtable = D_004E09B0;
        D_00572130--;
        if (deleteFlag > 0) {
            operator_delete(self);
        }
    }
    return self;
}
