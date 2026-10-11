#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
#define DEFINE_NET_MSG_CLONE1(name, size, fileSym, line, vtableSym, copy)      \
    extern "C" { extern char fileSym[]; extern char vtableSym[]; }            \
    extern "C" NetMsgHeader* name(NetMsgHeader* self)                         \
    {                                                                         \
        NetMsgHeader* p;                                                      \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (NetMsgHeader*)Mem_Alloc(0, (size), fileSym, (line));         \
        }                                                                     \
        if (p) {                                                              \
            p->vtable = D_004DFD80;                                           \
            p->w4 = self->w4;                                                 \
            p->w8 = self->w8;                                                 \
            p->wC = self->wC;                                                 \
            p->w10 = self->w10;                                               \
            p->w14 = self->w14;                                               \
            p->w18 = self->w18;                                               \
            p->w1C = self->w1C;                                               \
            p->b20 = self->b20;                                               \
            p->vtable = vtableSym;                                            \
            copy;                                                             \
        }                                                                     \
        return p;                                                             \
    }
DEFINE_NET_MSG_CLONE1(func_001B9FC0, 0x30, D_0049EDE0, 0x4D, D_004DA950, NMC_W(0x24); NMC_W(0x28); NMC_W(0x2C))
