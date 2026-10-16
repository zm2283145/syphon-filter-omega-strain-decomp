#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Tgt4081E0 { char pad[0x38]; int kind; };
struct Sub4081E0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int Check(); };
struct Obj4081E0 { VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e) virtual void Hit(float amt, Tgt4081E0* src, int a, int b, int c, int d, int e); char pad[0x10]; unsigned char b14; char p15[0x43]; Sub4081E0* sub; };
typedef struct { int kind; int id; unsigned char b8; char p9[3]; int fC; short h10; short h12; unsigned short h14; } Pk4081E0;
typedef struct { void* vt; char p4[0x20]; int amt; Tgt4081E0* tgt; signed char b2C; signed char b2D; char p2E[6]; int tid; } Evt4081E0;
extern "C" {
extern unsigned char D_005721D0;
extern char g_MsgLibDamageRequestKey[], D_004E08A0[];
extern void Event_Construct(Evt4081E0* e, void* type);
void* Object_LookupById(int*);
Obj4081E0** NetMap_Lookup(int);
void MsgQueue_QueueClone(Evt4081E0*, void*, int, int);
void cMessage_dtor(Evt4081E0*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_004081E0(int a0, int a1, int a2, Pk4081E0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt4081E0 e;
        int k[1];
        Obj4081E0** look;
        Evt4081E0* p = &e;
Tgt4081E0** pt;
Pk4081E0* a = arg;
Obj4081E0* o;
        Event_Construct(p, g_MsgLibDamageRequestKey);
        e.vt = D_004E08A0;
        e.tid = a->fC;
        p->tgt = (Tgt4081E0*)Object_LookupById((int*)((char*)&e + 0x34));
        p->b2D = a->h10;
        p->amt = a->h14;
        p->b2C = a->h12;
        look = NetMap_Lookup(a->id);
        if (!look) { k[0] = a->id; o = (Obj4081E0*)Object_LookupById(k); } else o = *look;
        pt = &e.tgt;
        if (o && *pt) {
            if (a->b8) MsgQueue_QueueClone(&e, o, 0, 0);
            else {
                unsigned char ok = 0;
                if (o->sub && o->sub->Check()) ok = 1;
                if (ok && o->b14) {
                    if ((*pt)->kind != 0x80) o->Hit((float)e.amt, *pt, e.b2D, e.b2C, 0, 1, 0);
                } else o->Hit((float)e.amt, *pt, e.b2D, e.b2C, 0, 1, 0);
            }
        }
        e.vt = D_004E08A0;
        cMessage_dtor(&e, 0);
    }
    return 0x18;
}
#pragma pop
