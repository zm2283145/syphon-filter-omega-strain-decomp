#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"

class VObj { public: virtual ~VObj(); };
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Net { char pad[0x24]; int w24; };
struct Msg {
    void* vt;
    char pad4[0x20 - 0x4];
    unsigned char b20;
    char pad21[0x78 - 0x21];
    char sub78[0x114 - 0x78];
    char sub114[0x1D4 - 0x114];
};

struct Npc {
    void* vt;
    char pad4[0xC - 0x4];
    char aC[0x10 - 0xC];
    int w10;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    Vis* p58;
    char pad5C[0x3030 - 0x5C];
    char m3030[0x3050 - 0x3030];
    char m3050[0x3088 - 0x3050];
    char m3088[0x30F0 - 0x3088];
    char m30F0[0x31FC - 0x30F0];
    unsigned char b31FC;
    char pad31FD[0x320C - 0x31FD];
    char m320C[0x3220 - 0x320C];
    char m3220[0x3234 - 0x3220];
    char m3234[0x3248 - 0x3234];
    char m3248[0x3250 - 0x3248];
    char m3250[0x3258 - 0x3250];
    char m3258[0x3264 - 0x3258];
    void* p3264;
    char pad3268[0x32A0 - 0x3268];
    void* vt32A0;
    char pad32A4[0x32E0 - 0x32A4];
    char m32E0[0x3310 - 0x32E0];
    VObj* w3310;
    VObj* w3314;
    char pad3318[0x33BC - 0x3318];
    float f33BC;
    char pad33C0[0x33EC - 0x33C0];
    void* p33EC;
    char m33F0[0x3524 - 0x33F0];
    void* p3524;
    void* p3528;
    char pad352C[0x3584 - 0x352C];
    Net* p3584;
};

extern "C" {
extern char D_004DA690[];
extern char D_004DA2F0[];
extern char D_004DADF0[];
extern char D_0049EDB8[];
extern char D_0049D8D0[];
extern char D_0055C7A0[];
extern char D_004F12D0[];
extern char D_004FFB50[];
extern unsigned char D_005721C8;
void Mem_Free(int, void*, char*, int);
void WeaponInv_Dtor(void*, int);
void Node_ReleaseComponent58(Npc*);
void Actor_ShockReaction(Npc*, unsigned char, int, float);
int func_002D2210(Net*);
void func_002EC2A8(int);
void func_001B31A0(Iter*, char*);
void func_001B3170(Iter*, char*, int*);
int func_001B3150(Iter*, Iter*);
int ReceiverMap_Erase(char*, Iter*);
void func_00436C00(int*);
void func_00433CE0(int*, void*);
void func_00436BA0(int*, int);
void func_003FB720(Npc*);
void Flashlight_Destroy(void*, int);
void func_001BE780(void*, int);
void SoundStopMsg_Ctor(Msg*, char*, Npc*);
void Event_Send(Msg*, char*, int);
void FileMan_Release(void*, int);
void cMessage_dtor(Msg*, int);
void Actor_UnlinkAll(Npc*);
void cCheckpoint_dtor(void*, int);
void func_00136300(void*, int);
void func_00136350(void*, int);
void func_001B5F90(void*, int);
void func_001B5F40(void*, int);
void func_0017ED20(void*, int);
void func_001B5ED0(void*, int);
void func_001B5E70(void*, int);
void func_001B5E20(void*, int);
void Actor_Destroy(Npc*, int);
void operator_delete(void*);
}

static inline void Unreg(int key)
{
    Iter e, f;
    func_001B31A0(&e, D_0055C7A0);
    func_001B3170(&f, D_0055C7A0, &key);
    if (func_001B3150(&e, &f)) {
        Iter g;
        func_001B3170(&g, D_0055C7A0, &key);
        ReceiverMap_Erase(D_0055C7A0, &g);
    }
}
static inline void SendDeath(Npc* a)
{
    Msg m;
    SoundStopMsg_Ctor(&m, D_004F12D0, a);
    m.b20 = 1;
    Event_Send(&m, D_004FFB50, 1);
    m.vt = D_004DADF0;
    FileMan_Release(m.sub114, -1);
    FileMan_Release(m.sub78, -1);
    cMessage_dtor(&m, 0);
}
static inline bool IsOn(Npc* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}

extern "C" Npc* Npc_Dtor(Npc* a, short flag)
{
    int loc;
    if (a) {
        int i;
        a->vt = D_004DA690;
        {
            void* p = a->p3264;
            if (p) {
                {
                    AllocGuard g;
                    Mem_Free(0, p, D_0049EDB8, 0x39A);
                }
                a->p3264 = 0;
            }
        }
        {
            void* p = a->p3524;
            AllocGuard g;
            WeaponInv_Dtor(p, -1);
            Mem_Free(0, p, D_0049D8D0, 0x3E9);
        }
        if (a->b31FC) {
            Node_ReleaseComponent58(a);
            a->b31FC = 0;
        }
        for (i = 0; i < 3; i++) Actor_ShockReaction(a, i, 0, 1.0f);
        if (D_005721C8) {
            Net* n = a->p3584;
            if (n) {
                if (func_002D2210(n)) func_002EC2A8(n->w24);
                a->p3584 = 0;
            }
            Unreg(a->w10);
            func_00436C00(&loc);
            func_00433CE0(&loc, a->aC);
            func_00436BA0(&loc, -1);
        }
        if (IsOn(a)) func_003FB720(a);
        {
            void* p = a->p33EC;
            if (p) {
                AllocGuard g;
                Flashlight_Destroy(p, -1);
                Mem_Free(0, p, D_0049D8D0, 0x402);
            }
        }
        int v = a->b2D != 0;
        if (v) v = a->b2C != 0;
        v = v ? (a->b2E != 0) ^ 1 : v; /* ternary: no pad nop before the join label */
        if (v) {
            VObj* o = a->w3310;
            if (o) {
                {
                    AllocGuard g;
                    o->~VObj();
                    Mem_Free(0, o, D_0049D8D0, 0x408);
                }
                a->w3310 = 0;
            }
            o = a->w3314;
            if (o) {
                {
                    AllocGuard g;
                    o->~VObj();
                    Mem_Free(0, o, D_0049D8D0, 0x40D);
                }
                a->w3314 = 0;
            }
        }
        {
            void* p = a->p3528;
            AllocGuard g;
            if (p) if (p) if (p) if (p) func_001BE780(p, 0);
            Mem_Free(0, p, D_0049D8D0, 0x412);
        }
        if (!(a->f33BC < 0.0f)) SendDeath(a);
        Actor_UnlinkAll(a);
        cCheckpoint_dtor(a->m33F0, -1);
        if (&a->vt32A0) {
            a->vt32A0 = D_004DA2F0;
            func_00136300(a->m32E0, -1);
            func_00136350(&a->vt32A0, 0);
        }
        if (a->m320C) {
            func_001B5F90(a->m3258, -1);
            func_001B5F90(a->m3250, -1);
            func_001B5F90(a->m3248, -1);
            func_001B5F40(a->m3234, -1);
            func_001B5F40(a->m3220, -1);
            func_001B5F40(a->m320C, -1);
        }
        if (a->m3030) {
            func_0017ED20(a->m30F0, -1);
            func_001B5ED0(a->m3088, -1);
            func_001B5E70(a->m3050, -1);
            func_001B5E20(a->m3030, -1);
        }
        Actor_Destroy(a, 0);
        if (flag > 0) operator_delete(a);
    }
    return a;
}


