#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void cMessage_ctor(void* self, void* src);
void func_002C5590(void* dst, void* src);
extern char D_004DE110[];
}
struct Msg54C0 { void* vtable; char pad[0x20]; int value; char pad2[8]; char payload[0x10]; };
extern "C" Msg54C0* func_002C54C0(Msg54C0* src)
{
    Msg54C0* p;
    {
        AllocGuard guard;
        p = (Msg54C0*)Mem_Alloc(0, 0x310, "NetCopyMsg.hh", 0x16);
    }
    if (p) {
        cMessage_ctor(p, src);
        p->vtable = D_004DE110;
        p->value = src->value;
        func_002C5590(p->payload, src->payload);
    }
    return p;
}