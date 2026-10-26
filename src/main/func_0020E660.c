#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void cMessage_ctor(void* self, void* src);
void cSndFx_ctor_cSndFxR(void* dst, void* src);
extern char D_004DADF0[];
}
struct Msg0E660 { void* vtable; char pad[0x2C]; char payload[0x190]; unsigned char b1C0; };
extern "C" Msg0E660* func_0020E660(Msg0E660* src)
{
    Msg0E660* p;
    {
        AllocGuard guard;
        p = (Msg0E660*)Mem_Alloc(0, 0x1D0, "gameSound_msg.hh", 0x7E);
    }
    if (p) {
        cMessage_ctor(p, src);
        p->vtable = D_004DADF0;
        cSndFx_ctor_cSndFxR(p->payload, src->payload);
        p->b1C0 = src->b1C0;
    }
    return p;
}