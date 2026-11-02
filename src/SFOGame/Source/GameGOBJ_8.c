/*
 * SFOGame/Source/GameGOBJ: 6 files, 002115E0-002118D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002115E0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_recv_guard.h"
#pragma pop
#include "message_pack.h"
#include "vslot_pad.h"

#pragma cplusplus on
typedef struct { int kind; int id; int floor; unsigned char lock; } Pk2115E0;
extern "C" {
extern unsigned char D_005721D0;
void** cNetObj_GetNetSystem(int);
void cElevatorGOBJ_LockFloor(void*, int, int);
void cElevatorGOBJ_UnlockFloor(void*, int, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetLockElevatorMsg_NetLockElevatorMsgCallback(int a0, int a1, int a2, Pk2115E0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk2115E0* p = arg;
        void** obj = cNetObj_GetNetSystem(p->id);
        if (obj) {
            if (p->lock) cElevatorGOBJ_LockFloor(*obj, p->floor, 1);
            else cElevatorGOBJ_UnlockFloor(*obj, p->floor, 1);
        }
    }
    return 0x10;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002115E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002115E0 */

/* merge_units: begin func_00211680 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24); MP_U(b, 0xC) = MP_U(e, 0x28);

DEFINE_MESSAGE_PACK_NOTYPE(cNetLockElevatorMsg_Pack, 16, D_004F54C0, PACK_BODY)
static inline void merge_flush_func_00211680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211680 */

/* merge_units: begin func_00211700 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int kind; int id; unsigned short h8; short pA; int fC; int f10; int f14; } Pk211700;
typedef struct { void* vt; char p4[0x14]; int f18; char p1C[8]; int f24; int f28; int f2C; int f30; char p34[4]; } Msg211700;
struct Obj211700 { VPAD8(a) VPAD2(b) virtual int Accept(Msg211700* m); };
extern "C" {
extern char g_TriggerMsgKey[], D_004DAF10[];
void cMessage_ctor_cMessageNameR_messagebaseR(Msg211700*, void*, Pk211700*);
void* nGobjManager_LookupGOBJ_cObjectIdR(int*);
void QueueMessage_cMessageR_cSystemP_int_int(Msg211700*, void*, int, int);
void cMessage_dtor(Msg211700*, int);
}
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int cGOBJTriggerEventMsg_NetGOBJTriggerEventCallback(int a0, int a1, int a2, Pk211700* arg) {
    NetRecvGuard g;
    Pk211700* p;
    p = arg;
    if (D_005721D0) {
        Msg211700 msg;
        void** obj;
        cMessage_ctor_cMessageNameR_messagebaseR(&msg, g_TriggerMsgKey, p);
        msg.vt = D_004DAF10;
        msg.f24 = p->h8;
        msg.f28 = p->fC;
        msg.f2C = p->f14;
        msg.f30 = p->f10;
        obj = cNetObj_GetNetSystem(p->id);
        if (obj) {
            int id = msg.f2C;
            Obj211700* o = (Obj211700*)nGobjManager_LookupGOBJ_cObjectIdR(&id);
            if (o == 0 || (o != 0 && o->Accept(&msg))) QueueMessage_cMessageR_cSystemP_int_int(&msg, *obj, msg.f18, 0);
        }
        msg.vt = D_004DAF10;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211700 */

/* merge_units: begin func_00211820 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { short a; int b; int c; } Proto_00211820;
#if 0 /* merge_units */
extern char D_004F5470[];
#endif /* merge_units */
extern int D_004F5470; /* merge_units */
#define D_004F5470 ((char*)&D_004F5470) /* merge_units */

#if 0 /* merge_units */
extern void cGOBJTriggerEventMsg_NetGOBJTriggerEventCallback(void);
#endif /* merge_units */


NETREG_BEGIN(cGOBJTriggerEventMsg_InitNet, Proto_00211820)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_004F5470, cGOBJTriggerEventMsg_NetGOBJTriggerEventCallback)
#undef D_004F5470 /* merge_units */
static inline void merge_flush_func_00211820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211820 */

/* merge_units: begin func_002118D0 */
#pragma push /* merge_units */
#undef PACK_BODY /* merge_units */
#define PACK_BODY(e, b) MP_H(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x30); MP_I(b, 0x14) = MP_I(e, 0x2C); MP_I(e, 0x1C) = 0x40;

DEFINE_MESSAGE_PACK_NOTYPE(cGOBJTriggerEventMsg_Pack, 24, D_004F5470, PACK_BODY)
static inline void merge_flush_func_002118D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002118D0 */

/* merge_units: begin func_00211970 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cElevatorGOBJ_CreateElevatorInfo(cElevatorGOBJ* lift);

int cElevatorGOBJ_InitNetwork(cElevatorGOBJ* lift) {
    return cElevatorGOBJ_CreateElevatorInfo(lift);
}
static inline void merge_flush_func_00211970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211970 */
