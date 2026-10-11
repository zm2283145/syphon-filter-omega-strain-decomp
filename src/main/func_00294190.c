#pragma cplusplus on
#include "types.h"
extern "C" {
extern char D_004DD4F0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_00138350(void* self, short deleteFlag);
void func_0033D430(void* self, int flags);
void operator_delete(void* p);
}
struct O294190 { void* vtable; char pad[0x200]; char items[0x11][0xC]; };
extern "C" O294190* func_00294190(O294190* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DD4F0;
        __destroy_array(self->items, (void*)func_00138350, 0xC, 0x11);
        func_0033D430(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}