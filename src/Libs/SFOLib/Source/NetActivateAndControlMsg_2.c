/*
 * Libs/SFOLib/Source/NetActivateAndControlMsg: 4 files, 0042CAA0-0042CCC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042CAA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
struct V2CAA0 { union { struct { unsigned int a, b; char* c; } l; struct { unsigned char f : 1; unsigned char n : 7; char buf[11]; } s; } u; };
extern "C" char D_004DFD80[];
extern "C" char D_004E0EA0[];
MSG_CLONE_BEGIN(cNetActivateAndControlMsg_Clone, 0x30, "NetActivateAndControlMsg.hh", 0x1C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0EA0;
    F(V2CAA0, 0x24) = S(V2CAA0, 0x24);
MSG_CLONE_END
static inline void merge_flush_func_0042CAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CAA0 */

/* merge_units: begin func_0042CBB0 */
#pragma push /* merge_units */
#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_00582688;
extern int cNetActivateAndControlMsg_ActivateAndControlCallback(int, int, int, void*);
unsigned char cNetActivateAndControlMsg_InitNet(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && cMessage_RegisterFields(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 && NetRegisterMessage(&D_00582688, 2, cNetActivateAndControlMsg_ActivateAndControlCallback) == 0) {
        r = 1;
    }
    return r;
}
static inline void merge_flush_func_0042CBB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CBB0 */

/* merge_units: begin func_0042CC40 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_PRE(e)
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK_PRE(cNetActivateAndControlMsg_Pack, 12, D_00582688, PACK_PRE, PACK_BODY)
static inline void merge_flush_func_0042CC40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CC40 */

/* merge_units: begin func_0042CCC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { char pad[0xC]; int fC; } Obj0042CCC0;
typedef struct { void* vt; char p4[0x18]; int f1C; char p20[0xC]; int f2C; } Ev2_0042CCC0;
typedef struct { char pad[0x10]; Obj0042CCC0* val; } Node0042CCC0;
typedef struct { void* vt; char p4[0x18]; int f1C; char p20[0xC]; int f2C; char p30[0xC]; } Evt0042CCC0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0042CCC0;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt0042CCC0* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt0042CCC0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0042CCC0* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node0042CCC0** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0042CCC0** out, void* in);
extern char D_004E0EA0[];
extern char D_00582680[];
extern unsigned char D_005721D0;
}
static inline int Eq0042CCC0(Node0042CCC0* a, Node0042CCC0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNetActivateAndControlMsg_ActivateAndControlCallback(int a0, int a1, int a2, void* packet) {
    Arg0042CCC0* arg = (Arg0042CCC0*)packet;
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0042CCC0 e;
        int k[1];
        Node0042CCC0* end[1];
        Node0042CCC0* it[1];
        int tmp[1];
        Node0042CCC0* n;
        Arg0042CCC0* a = arg;
        cMessage_ctor_cMessageNameR(&e, D_00582680);
        e.vt = D_004E0EA0;
        e.f2C = a->a8;
        k[0] = a->a4;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0042CCC0(n, end[0]) ^ 1) {
            Obj0042CCC0* o = n->val;
            if (o) {
                Ev2_0042CCC0 e2;
                int v = o->fC;
                cMessage_ctor_cMessageNameR((Evt0042CCC0*)&e2, D_00582680);
                e2.vt = D_004E0EA0;
                e2.f1C = 0x40;
                e2.f2C = v;
                QueueMessage_cMessageR_cSystemP_int_int((Evt0042CCC0*)&e2, o, 0, 0);
                e2.vt = D_004E0EA0;
                cMessage_dtor((Evt0042CCC0*)&e2, 0);
            }
        }
        e.vt = D_004E0EA0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
static inline void merge_flush_func_0042CCC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CCC0 */
