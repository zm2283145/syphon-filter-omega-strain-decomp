#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
extern "C" char D_004E0840[];
static inline void QCopy_1B9D50(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v0, -0x10(d)
        .set reorder
    }
}
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
            p->vtable = (char*)D_004E0840;                                    \
            NMC_W(0x24); NMC_B(0x28);                                         \
            p->vtable = vtableSym;                                            \
            copy;                                                             \
        }                                                                     \
        return p;                                                             \
    }


extern "C" { char D_0049EDC8[] = "character.hh"; }
DEFINE_NET_MSG_CLONE1(cCharActionMsg_ObjectId_AnimName_Scalar_Bool_Clone, 0x70, D_0049EDC8, 0x356, D_004DA910, NMC_W(0x2C); QCopy_1B9D50((char*)p + 0x30, (char*)self + 0x30); NMC_F(0x60); NMC_UB(0x64))
