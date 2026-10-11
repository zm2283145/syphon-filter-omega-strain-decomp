#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* func_003A61E0(void* self, short deleteFlag);

typedef struct { int pad0; int member; } Obj_3A6240;

extern "C" Obj_3A6240* func_003A6240(Obj_3A6240* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            func_003A61E0(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}