/*
 * SFOGame/Source/NetScoreMsg: 4 files, 00316370-00316600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316370 */
#pragma push /* merge_units */
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
extern "C" { char D_004B3560[] = "NetScoreMsg.hh"; }
DEFINE_NET_MSG_CLONE1(cNetScoreMsg_Clone, 0x30, D_004B3560, 0x17, D_004DE5D0, NMC_W(0x24); NMC_W(0x28); NMC_W(0x2C))
static inline void merge_flush_func_00316370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316370 */

/* merge_units: begin func_00316480 */
#pragma push /* merge_units */
typedef struct { int kind; int f4; int f8; int fC; int f10; } Pk316480;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; int f2C; int p30; } Msg316480;
extern unsigned char D_005723C8, D_005721D0;
extern char D_0052ACB0[], D_004DE5D0[];
extern void cMessage_ctor_cMessageNameR(Msg316480* e, void* type);
extern void** cNetObj_GetNetSystem(int);
extern void QueueMessage_cMessageR_cSystemP_int_int(Msg316480*, void*, int, int);
extern void cMessage_dtor(Msg316480*, int);
#pragma push
#pragma opt_propagation off
int cNetScoreMsg_ScoreMsgCallback(int a0, int a1, int a2, void* packet) {
    Pk316480* arg = (Pk316480*)packet;
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Msg316480 msg;
        void** obj;
        Pk316480* p = arg;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACB0);
        msg.vt = D_004DE5D0;
        msg.f2C = p->f8;
        msg.f24 = p->fC;
        msg.f28 = p->f10;
        obj = cNetObj_GetNetSystem(p->f8);
        if (obj) QueueMessage_cMessageR_cSystemP_int_int(&msg, *obj, 0, 0);
        msg.vt = D_004DE5D0;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x14;
}
#pragma pop
static inline void merge_flush_func_00316480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316480 */

/* merge_units: begin func_00316550 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { int a; int b; int c; } Proto_00316550;
extern int D_0052ACA8;
extern int cNetScoreMsg_ScoreMsgCallback(int a0, int a1, int a2, void* packet);

NETREG_BEGIN(cNetScoreMsg_InitNet, Proto_00316550)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(&D_0052ACA8, cNetScoreMsg_ScoreMsgCallback)
static inline void merge_flush_func_00316550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316550 */

/* merge_units: begin func_00316600 */
#pragma push /* merge_units */
#include "message_pack.h"
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x28); MP_I(b, 0xC) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK(cNetScoreMsg_Pack, 20, D_0052ACA8, PACK_BODY)
static inline void merge_flush_func_00316600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316600 */
