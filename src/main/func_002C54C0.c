#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMessage_ctor_cMessageR(void* self, void* src);
void cNetworkTransferNpc_ctor_cNetworkTransferNpcR(void* dst, void* src);
extern char D_004DE110[];
}
struct Msg54C0 { void* vtable; char pad[0x20]; int value; char pad2[8]; char payload[0x10]; };
extern "C" Msg54C0* cNetCopyMsg_Clone(Msg54C0* src)
{
    Msg54C0* p;
    {
        AllocGuard guard;
        p = (Msg54C0*)cMemMan_Allocate(0, 0x310, "NetCopyMsg.hh", 0x16);
    }
    if (p) {
        cMessage_ctor_cMessageR(p, src);
        p->vtable = D_004DE110;
        p->value = src->value;
        cNetworkTransferNpc_ctor_cNetworkTransferNpcR(p->payload, src->payload);
    }
    return p;
}