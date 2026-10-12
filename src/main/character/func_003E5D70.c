#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004E0100[];
void func_003E5E40(void* dst, void* src);
void cMessage_ctor3(void* self, void* other);
}
struct PM5D70 { void* vtable; char pad[8]; int wC; char pad2[0x20]; char payload[0x30]; };
extern "C" PM5D70* func_003E5D70(PM5D70* self)
{
    PM5D70* p;
    {
        AllocGuard guard;
        p = (PM5D70*)Mem_Alloc(0, 0x60, "character.hh", 0x40E);
    }
    if (p) {
        cMessage_ctor3(p, self);
        func_003E5E40(p->payload, self->payload);
        p->vtable = D_004E0100;
    }
    p->wC = self->wC;
    return p;
}