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
            p = (NetMsgHeader*)cMemMan_Allocate(0, (size), fileSym, (line));         \
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
extern "C" { char D_0049EE00[] = "ska.hh"; }
DEFINE_NET_MSG_CLONE1(cSkaAnimEndedMessage_Clone, 0x38, D_0049EE00, 0xC8A, D_004DA930, NMC_W(0x24); NMC_B(0x28); NMC_W(0x2C); NMC_UB(0x30); NMC_F(0x34))
