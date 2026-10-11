#pragma cplusplus on
#include "types.h"
extern "C" { extern char D_004E08B8[]; void func_0036AF40(void* self, int flags); void operator_delete(void* p); }
struct V411730 { char pad[0x8A74]; void* vtable; };
extern "C" V411730* func_00411730(V411730* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E08B8;
        func_0036AF40(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}