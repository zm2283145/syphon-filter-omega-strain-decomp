#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* func_002782B0(void* self, short deleteFlag);

typedef struct { int pad0[0x78/4]; int member; } Obj_00351FC0;

extern "C" Obj_00351FC0* func_00278250(Obj_00351FC0* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            func_002782B0(m, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}