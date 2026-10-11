#pragma cplusplus on
#include "types.h"
extern "C" {
void func_0036E220(void* member, int flags);
void func_0041F370(void* self, int flags);
void operator_delete(void* allocation);
extern char D_004E1290[];
}
struct TM454080 { void* vtable; char base[0x4C]; char payload[0x48]; char memberA[0x9C]; char memberB[4]; };
extern "C" TM454080* func_00454080(TM454080* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E1290;
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        func_0041F370(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}