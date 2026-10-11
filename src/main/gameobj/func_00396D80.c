#pragma cplusplus on
#include "types.h"
extern "C" { void func_00396DF0(void* member, int flags); void func_00397120(void* member, int flags); void operator_delete(void* p); }
struct P1C9F10 { char pad[0x10]; char memberA[0x110]; char memberB[4]; };
extern "C" P1C9F10* func_00396D80(P1C9F10* self, short deleteFlag)
{
    if (self) {
        if (self->memberA) {
            func_00397120(self->memberB, -1);
            func_00396DF0(self->memberA, -1);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}