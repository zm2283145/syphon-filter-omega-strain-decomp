/*
 * main/human: range (2 files, 001B9FC0-001BA0D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop

/* merge_units: begin func_001B9FC0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern "C" {
char D_0049EDE0[] = "charEventMsg.hh";
}
DEFINE_NET_MSG_CLONE1(cCharEventMsg_Clone, 0x30, D_0049EDE0, 0x4D, D_004DA950, NMC_W(0x24); NMC_W(0x28); NMC_W(0x2C))
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B9FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B9FC0 */

/* merge_units: begin func_001BA0D0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_VT8_CHAIN_DTOR(cHumanRespawnCB_dtor, D_004DA970, D_004D9DE0)
#pragma pop /* merge_units */
/* merge_units: end func_001BA0D0 */
