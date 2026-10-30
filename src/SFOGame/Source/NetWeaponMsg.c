/*
 * SFOGame/Source/NetWeaponMsg: 3 files, 00316BB0-00316C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316BB0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetRegisterMessage(char *, int, char *);
int NetRegisterMessageStart();
int NetMessageField(char *, char *, int, int);
int cMessage_RegisterFields(char *);
extern int D_0052ACD0;
struct Pk316D10;
extern int cNetWeaponMsg_WeaponMsgCallback(int a0, int a1, int a2, struct Pk316D10* arg);

unsigned char cNetWeaponMsg_InitNet(void) {
    struct { int f20[2]; int f28; int f2C; int f30; int f34[3]; } sl;
    unsigned char var_s0;

    var_s0 = 0;
    if ((NetRegisterMessageStart() == 0) && (cMessage_RegisterFields(sl.f20) != 0) && (NetMessageField(sl.f20, &sl.f30, 1, 1) == 0) && (NetMessageField(sl.f20, sl.f34, 4, 1) == 0) && (NetMessageField(sl.f20, &sl.f28, 1, 1) == 0) && (NetMessageField(sl.f20, &sl.f2C, 4, 1) == 0) && (NetRegisterMessage((char*)&D_0052ACD0, 2, (char*)cNetWeaponMsg_WeaponMsgCallback) == 0)) {
        var_s0 = 1;
    }
    return var_s0;
}
static inline void merge_flush_func_00316BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316BB0 */

/* merge_units: begin func_00316C80 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_U(b, 0x10) = MP_U(e, 0x34); MP_I(b, 0x14) = MP_I(e, 0x38);

DEFINE_MESSAGE_PACK(cNetWeaponMsg_Pack, 0x18, D_0052ACD0, PACK_BODY)
static inline void merge_flush_func_00316C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316C80 */

/* merge_units: begin func_00316D10 */
#pragma push /* merge_units */
typedef struct Pk316D10 { int f0; int f4; signed char f8; char p9[3]; int fC; unsigned char f10; char p11[3]; int f14; } Pk316D10;
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
