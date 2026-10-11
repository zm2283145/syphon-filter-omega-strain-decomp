#pragma cplusplus on

#include "types.h"

/* Deleting destructor: restore the vtable of the subobject at +0x8A74, release the handle at +0. */
extern "C" {
extern char D_004DF630[];
extern int D_00539248;
void operator_delete(void* allocation);
void func_003813A0(int mgr, int handle, int flags);
}
struct O36AF40 { int handle; char pad[0x8A70]; void* vtable; };
extern "C" O36AF40* func_0036AF40(O36AF40* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DF630;
        func_003813A0(D_00539248, self->handle, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}