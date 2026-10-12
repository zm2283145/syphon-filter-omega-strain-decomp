#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void AnimSelector_Evaluate();
extern "C" void func_003B4630();
extern void * const D_004DFBB0[];
void* func_001F2A50(void* self, short deleteFlag);
void* func_001F2A00(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O1F2990 { void* vtable; char pad[0x20]; char member[4]; };
extern "C" O1F2990* func_001F2990(O1F2990* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFBB0);
        func_001F2A50(self->member, -1);
        func_001F2A00(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFBB0[8] = { (void*)0x0, (void*)0x0, (void*)func_001F2990, (void*)AnimSelector_Evaluate, (void*)func_003B4630, (void*)0x0, (void*)0x0, (void*)0x0 };
