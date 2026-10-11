#pragma cplusplus on

#include "types.h"

/* Deleting destructor of a class with nothing to destroy: restore the vtable, delete. */
extern "C" {
extern char D_004DF6A0[];
void operator_delete(void* allocation);
}
struct O36FC80 { void* vtable; };
extern "C" O36FC80* func_0036FC80(O36FC80* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DF6A0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}