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
extern char g_Game[];
extern unsigned char g_IsMultiplayer;
void cMemMan_Deallocate(int, void*, char*, int);
void cWeapon_dtor(void*, int);
void cGOBJ_DeleteController(Npc*);
void cHuman_SetParticleEffect(Npc*, unsigned char, int, float);
int func_002D2210(Net*);
void NetFreeObject(int);
void cAssocArray_int_netSystemField_End(Iter*, char*);
void cAssocArray_int_netSystemField_Find(Iter*, char*, int*);
int cAssocArray_int_netSystemField_Iterator_opNe(Iter*, Iter*);
int cAssocArray_int_netSystemField_Erase(char*, Iter*);
void cNPCInfoObject_ctor(int*);
void cNPCInfoObject_Deactivate(int*, void*);
void cNPCInfoObject_dtor(int*, int);
void cNetObj_RemovePlayer_cGOBJP(Npc*);
void cFlashlight_dtor(void*, int);
void std_vector_deleter_tItem_dtor(void*, int);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Msg*, char*, Npc*);
void QueueMessage_cMessageR_cSystemP_int(Msg*, char*, int);
void cFileMan_dtor(void*, int);
void cMessage_dtor(Msg*, int);
void Actor_UnlinkAll(Npc*);
void cCheckpoint_dtor(void*, int);
void cActivationTracker_dtor(void*, int);
void cCollisionModelList_dtor(void*, int);
void cAimComponentList_dtor(void*, int);
void cArray_FixedSize_bool_10_dtor(void*, int);
void func_0017ED20(void*, int);
void cHumanMotionParams_cTargetZRotationStack_dtor(void*, int);
void cSplinedMotion_Angle_dtor(void*, int);
void cStatesWithHistory_1_dtor(void*, int);
void cSKM_GOBJ_dtor(Npc*, int);
void operator_delete(void*);
}

static inline void Unreg(int key)
{
    Iter e, f;
    cAssocArray_int_netSystemField_End(&e, D_0055C7A0);
    cAssocArray_int_netSystemField_Find(&f, D_0055C7A0, &key);
    if (cAssocArray_int_netSystemField_Iterator_opNe(&e, &f)) {
        Iter g;
        cAssocArray_int_netSystemField_Find(&g, D_0055C7A0, &key);
        cAssocArray_int_netSystemField_Erase(D_0055C7A0, &g);
    }
}
static inline void SendDeath(Npc* a)
{
    Msg m;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&m, D_004F12D0, a);
    m.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
    m.vt = D_004DADF0;
    cFileMan_dtor(m.sub114, -1);
    cFileMan_dtor(m.sub78, -1);
    cMessage_dtor(&m, 0);
}
static inline bool IsOn(Npc* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}

extern "C" Npc* cHuman_dtor(Npc* a, short flag)
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
                    cMemMan_Deallocate(0, p, D_0049EDB8, 0x39A);
                }
                a->p3264 = 0;
            }
        }
        {
            void* p = a->p3524;
            AllocGuard g;
            cWeapon_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_0049D8D0, 0x3E9);
        }
        if (a->b31FC) {
            cGOBJ_DeleteController(a);
            a->b31FC = 0;
        }
        for (i = 0; i < 3; i++) cHuman_SetParticleEffect(a, i, 0, 1.0f);
        if (g_IsMultiplayer) {
            Net* n = a->p3584;
            if (n) {
                if (func_002D2210(n)) NetFreeObject(n->w24);
                a->p3584 = 0;
            }
            Unreg(a->w10);
            cNPCInfoObject_ctor(&loc);
            cNPCInfoObject_Deactivate(&loc, a->aC);
            cNPCInfoObject_dtor(&loc, -1);
        }
        if (IsOn(a)) cNetObj_RemovePlayer_cGOBJP(a);
        {
            void* p = a->p33EC;
            if (p) {
                AllocGuard g;
                cFlashlight_dtor(p, -1);
                cMemMan_Deallocate(0, p, D_0049D8D0, 0x402);
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
                    cMemMan_Deallocate(0, o, D_0049D8D0, 0x408);
                }
                a->w3310 = 0;
            }
            o = a->w3314;
            if (o) {
                {
                    AllocGuard g;
                    o->~VObj();
                    cMemMan_Deallocate(0, o, D_0049D8D0, 0x40D);
                }
                a->w3314 = 0;
            }
        }
        {
            void* p = a->p3528;
            AllocGuard g;
            if (p) if (p) if (p) if (p) std_vector_deleter_tItem_dtor(p, 0);
            cMemMan_Deallocate(0, p, D_0049D8D0, 0x412);
        }
        if (!(a->f33BC < 0.0f)) SendDeath(a);
        Actor_UnlinkAll(a);
        cCheckpoint_dtor(a->m33F0, -1);
        if (&a->vt32A0) {
            a->vt32A0 = D_004DA2F0;
            cActivationTracker_dtor(a->m32E0, -1);
            cCollisionModelList_dtor(&a->vt32A0, 0);
        }
        if (a->m320C) {
            cAimComponentList_dtor(a->m3258, -1);
            cAimComponentList_dtor(a->m3250, -1);
            cAimComponentList_dtor(a->m3248, -1);
            cArray_FixedSize_bool_10_dtor(a->m3234, -1);
            cArray_FixedSize_bool_10_dtor(a->m3220, -1);
            cArray_FixedSize_bool_10_dtor(a->m320C, -1);
        }
        if (a->m3030) {
            func_0017ED20(a->m30F0, -1);
            cHumanMotionParams_cTargetZRotationStack_dtor(a->m3088, -1);
            cSplinedMotion_Angle_dtor(a->m3050, -1);
            cStatesWithHistory_1_dtor(a->m3030, -1);
        }
        cSKM_GOBJ_dtor(a, 0);
        if (flag > 0) operator_delete(a);
    }
    return a;
}


