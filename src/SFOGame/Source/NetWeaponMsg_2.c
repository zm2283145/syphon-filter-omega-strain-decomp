/*
 * SFOGame/Source/NetWeaponMsg: 2 files, 00316C80-00316D10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316C80 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_U(b, 0x10) = MP_U(e, 0x34); MP_I(b, 0x14) = MP_I(e, 0x38);

DEFINE_MESSAGE_PACK(cNetWeaponMsg_Pack, 0x18, D_0052ACD0, PACK_BODY)
static inline void merge_flush_func_00316C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316C80 */

/* merge_units: begin func_00316D10 */
#pragma push /* merge_units */
typedef struct { int f0; int f4; signed char f8; char p9[3]; int fC; unsigned char f10; char p11[3]; int f14; } Pk316D10;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; signed char f2C; char p2D[3]; int f30; unsigned char f34; char p35[3]; int f38; } Msg316D10;
extern unsigned char D_005723C8, D_005721D0;
extern char D_0052ACC8[], D_004DE610[];
extern void cMessage_ctor_cMessageNameR(Msg316D10* e, void* type);
extern void** cNetObj_GetNetSystem(int);
extern void QueueMessage_cMessageR_cSystemP_int_int(Msg316D10*, void*, int, int);
extern void cMessage_dtor(Msg316D10*, int);
#pragma push
#pragma opt_propagation off
int cNetWeaponMsg_WeaponMsgCallback(int a0, int a1, int a2, Pk316D10* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Msg316D10 msg;
        void** obj;
        Pk316D10* p = arg;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACC8);
        msg.vt = D_004DE610;
        msg.f24 = p->f0;
        msg.f28 = p->f4;
        msg.f2C = p->f8;
        msg.f30 = p->fC;
        msg.f34 = p->f10;
        msg.f38 = p->f14;
        obj = cNetObj_GetNetSystem(p->f4);
        if (obj) QueueMessage_cMessageR_cSystemP_int_int(&msg, *obj, 0, 0);
        msg.vt = D_004DE610;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x18;
}
#pragma pop
static inline void merge_flush_func_00316D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316D10 */
