#pragma cplusplus on
#include "types.h"
extern "C" {
extern char D_004DACB0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_001C9F10(void* self, short deleteFlag);
void Receiver_Destruct(void* self, int flags);
void operator_delete(void* p);
}
struct O1CA750 { void* vtable; char pad[0x2C]; char items[0x32][0x1B0]; };
extern "C" O1CA750* func_001CA750(O1CA750* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DACB0;
        __destroy_array(self->items, (void*)func_001C9F10, 0x1B0, 0x32);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}