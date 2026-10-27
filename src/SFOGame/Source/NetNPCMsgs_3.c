/*
 * SFOGame/Source/NetNPCMsgs: 4 files, 002D7100-002D7360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D7100 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_I(b, 0x10) = MP_I(e, 0x34); MP_I(b, 0x14) = MP_I(e, 0x38);

DEFINE_MESSAGE_PACK(cNetNPCMsgs_Pack, 0x18, D_0051F0A0, PACK_BODY)
static inline void merge_flush_func_002D7100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7100 */

/* merge_units: begin func_002D7190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { int f0; int f4; signed char f8; char p9[3]; int fC; int f10; int f14; } Pk2D7190;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; signed char f2C; char p2D[3]; int f30; int f34; int f38; } Msg2D7190;
extern "C" {
extern unsigned char D_005721D0;
extern unsigned char g_GameState;
extern char D_0051F0A8[], D_004DE4D0[];
extern void cMessage_ctor_cMessageNameR(Msg2D7190* e, void* type);
extern void** cNetObj_GetNetSystem(int);
extern void cNetNPCMsgs_DoNPCMethod(void*, int, int, int, int);
extern void cMessage_dtor(Msg2D7190*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetNPCMsgs_NetNPCMsgsCallback(int a0, int a1, int a2, Pk2D7190* arg) {
    NetRecvGuard g;
    if (D_005721D0 && g_GameState != 0x14) {
        Msg2D7190 msg;
        void** obj;
        Pk2D7190* p = arg;
        cMessage_ctor_cMessageNameR(&msg, D_0051F0A8);
        msg.vt = D_004DE4D0;
        msg.f24 = p->f0;
        msg.f28 = p->f4;
        msg.f2C = p->f8;
        msg.f30 = p->fC;
        msg.f34 = p->f10;
        msg.f38 = p->f14;
        obj = cNetObj_GetNetSystem(p->f4);
        if (obj && *obj) cNetNPCMsgs_DoNPCMethod(*obj, p->f8, p->fC, p->f10, p->f14);
        msg.vt = D_004DE4D0;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
#pragma pop
static inline void merge_flush_func_002D7190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7190 */

/* merge_units: begin func_002D7290 */
#pragma push /* merge_units */
typedef struct NetEventMsg {
    void* vtbl;
    char pad04[0x18];
    int size;              /* 0x1C */
    unsigned char len;     /* 0x20 */
    char pad21[0xB];
    unsigned char type;    /* 0x2C */
    char pad2D[3];
    int a;                 /* 0x30 */
    int b;                 /* 0x34 */
    int c;                 /* 0x38 */
    char pad3C[4];
} NetEventMsg;

extern char D_0051F0A8[];
extern char D_004DE4D0[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(NetEventMsg* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg2D7190 *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int(NetEventMsg* msg, void* target, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(NetEventMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg2D7190 *)(a0), (a1))) /* merge_units */


/* Builds a network event message (type, len, three payload words) and sends it to target. */
void cNetNPCMsgs_SendMessage(void* target, int type, int len, int a, int b, int c, int flags) {
    NetEventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_0051F0A8);
    msg.vtbl = D_004DE4D0;
    msg.type = type;
    msg.size = 0x40;
    msg.a = a;
    msg.b = b;
    msg.c = c;
    msg.len = len;
    QueueMessage_cMessageR_cSystemP_int(&msg, target, flags);
    msg.vtbl = D_004DE4D0;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002D7290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7290 */

/* merge_units: begin func_002D7360 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { float f[9]; } Blk9G5;
typedef struct { void* vt; int a[7]; signed char b; char pad21[3]; Blk9G5 d; } ObjEvG5;
extern "C" {
extern char D_004DFD80[];
extern char D_004DE4F0[];
void* cMemMan_Allocate(int, int, char*, int);
}
static inline void* AllocL_G5(int size, char* file, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, file, line);
}
extern "C" ObjEvG5* cNetObjectiveMsg_Clone(ObjEvG5* self)
{
    ObjEvG5* p = (ObjEvG5*)AllocL_G5(0x48, "NetObjectiveMsg.hh", 0x28);
    if (p) {
        p->vt = D_004DFD80;
        p->a[0] = self->a[0];
        p->a[1] = self->a[1];
        p->a[2] = self->a[2];
        p->a[3] = self->a[3];
        p->a[4] = self->a[4];
        p->a[5] = self->a[5];
        p->a[6] = self->a[6];
        p->b = self->b;
        p->vt = D_004DE4F0;
        p->d = self->d;
    }
    return p;
}
static inline void merge_flush_func_002D7360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7360 */
