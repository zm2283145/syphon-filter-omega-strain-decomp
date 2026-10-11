#pragma cplusplus on
#include "types.h"
extern "C" { void func_0036E220(void* member, int flags); void operator_delete(void* p); }
struct P1C9F10 { char pad[0x20]; char payload[0x48]; char memberA[0x9C]; char memberB[4]; };
extern "C" P1C9F10* func_001C9F10(P1C9F10* self, short deleteFlag)
{
    if (self) {
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}