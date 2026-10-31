#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

#pragma inline_depth(8)
struct V4_A { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx_A {
    V4_A r[4];
    Mtx_A() {}
    Mtx_A(const Mtx_A& o) {
        __int128 a, b;
        __asm__ volatile("lq %0,0(%2); lq %1,0x10(%2); sq %0,0(%3); lq %0,0x20(%2); sq %1,0x10(%3); lq %1,0x30(%2); sq %0,0x20(%3); sq %1,0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(&o), "r"(this) : "memory");
    }
    inline Mtx_A& operator=(const Mtx_A& o) {
        __int128 a, b;
        __asm__ volatile("lq %0,0(%2); lq %1,0x10(%2); sq %0,0(%3); lq %0,0x20(%2); sq %1,0x10(%3); lq %1,0x30(%2); sq %0,0x20(%3); sq %1,0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(&o), "r"(this) : "memory");
        return *this;
    }
};
struct MtxP_A { V4_A r[4]; };
struct Ref_A { char* p; int n; Ref_A() {} Ref_A(char* a, int b) { p = a; n = b; } };
struct NpcO_A;
struct Hnd_A { NpcO_A* t; int serial; Hnd_A(NpcO_A* p); };
struct It_A { void* p; };
struct List_A;
extern "C" void std_list_deleter_cSafePtr_cGOBJ_insert(It_A* out, List_A* list, It_A* pos, const Hnd_A* h);
struct List_A { int count; char sent[8]; void push_back(const Hnd_A& h) { void* s = sent; It_A r; It_A pos; pos.p = s; It_A* pp = &pos; std_list_deleter_cSafePtr_cGOBJ_insert(&r, this, pp, &h); } };
struct Sub_A { char pad[0x150]; int x150; };
struct NpcO_A {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void Activate();
    char p4[0x8];
    int serial;
    int x10;
    unsigned char b14;
    char p15[0x7];
    void* x1C;
    char p20[0x38];
    Sub_A* x58;
    char p5C[0x3598 - 0x5C];
    unsigned char b3598;
};
struct Info_A {
    char pad[0x30];
    V4_A pos;
    float x40, x44, x48;
    char p4C[4];
    int x50;
    int x54;
    int x58;
    int x5C;
    int x60;
};
struct Gen_A {
    char pad[0xC];
    char key[0x20];
    bool b2C, b2D; unsigned char b2E;
    char p2F[0x35];
    int x64;
    char p68[4];
    char x6C[4];
    char p70[0x20];
    List_A list90;
    List_A list9C;
    char xA8[4];
    char pAC[0x10];
    int xBC;
    int xC0;
    int xC4;
    int xC8;
    char pCC[6];
    unsigned char bD2;
};
struct EvM_A {
    char* vt;
    char p4[0x20];
    signed char b24;
    char p25[0xB];
    Mtx_A m;
    EvM_A(const Mtx_A& mm);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~EvM_A();
};

extern "C" {
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(Mtx_A* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
NpcO_A* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* p, MtxP_A m, int a, int b, int c, char* d, int e, char* f, const unsigned int& g, const Ref_A& h, int i, int j);
void cBaseObjList_Add(void* reg, NpcO_A* o);
void cHuman_SetNetworkID(NpcO_A* o, int v);
void cGenInfoObject_ctor(void* ctx);
int cGenInfoObject_GetOwner(void* ctx, void* key);
void* cNetNPC_ctor(void* p, int a, NpcO_A* o);
void cHuman_CreateGobjController(NpcO_A* o, int n, Ref_A* r, void* c);
void cNetObj_AddSystem(int id, int v, NpcO_A* o);
void cNPCInfoObject_ctor(void* o);
void cNPCInfoObject_SetOwner_cObjectIdR_int(void* o, int* id, int v);
void cNPCInfoObject_dtor(void* o, int f);
void cMessage_ctor_cMessageNameR(EvM_A* e, char* type);
void QueueMessage_cMessageR_cSystemP_int_int(EvM_A* e, NpcO_A* o, int a, int b);
void cMessage_dtor(EvM_A* e, int f);
int cNetObj_GetNetSystem(int id);
void cHuman_SetupNetworkFields(NpcO_A* o, int v);
extern char D_004A4A90[];
extern char g_TeleportMsgClass[];
extern char D_004D9360[];
extern void* g_ActorList;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
}

inline Hnd_A::Hnd_A(NpcO_A* o) { int none; int m = -1; serial = m; t = o; serial = *(o ? &o->serial : (none = m, &none)); }


static inline bool NotE(Gen_A* s) { return !s->b2E; }
inline EvM_A::~EvM_A() { vt = D_004D9360; cMessage_dtor(this, 0); }
inline EvM_A::EvM_A(const Mtx_A& mm) { EvM_A* t = this; cMessage_ctor_cMessageNameR(t, g_TeleportMsgClass); t->vt = D_004D9360; t->b24 = 2; t->m = mm; }
static inline void SendM(NpcO_A* p, const Mtx_A& m) {
        EvM_A e(m);
        QueueMessage_cMessageR_cSystemP_int_int(&e, p, 1, 0);
}
static inline void SetEuler(Mtx_A* m, float ax, float ay, float az)
{
    float cy = COS(ay); float sy = SIN(ay);
    float cx = COS(ax); float sx = SIN(ax);
    float cz = COS(az); float sz = SIN(az);
    float czcy = cz * cy; float czsy = cz * sy; float szcy = sz * cy; float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(m, czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                                szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                                -cx * sy, sx, cx * cy);
}
#pragma push
#pragma inline_depth(8)
extern "C" void cGenerator_NetSpawn(Gen_A* self, Info_A* info)
{
    char ctx[4];
    char ctx2[4];
    char o[4];
    unsigned int g;
    Mtx_A m;
    float ey = info->x44; float ex = info->x40; float ez = info->x48;
    SetEuler(&m, ex, ey, ez);
    {
        V4_A* ps = &info->pos; V4_A* pd = &m.r[3]; __int128 x;
        __asm__ volatile("lq %0,0(%1); sq %0,0(%2)" : "=r"(x) : "r"(ps), "r"(pd) : "memory");
    }
    NpcO_A* p;
    {
        AllocGuard g;
        p = (NpcO_A*)cMemMan_Allocate(0, 0x35A0, D_004A4A90, 0x777);
    }
    if (p) {
        int a = info->x60; int c = info->x58; g = info->x50; Ref_A r(self->key, self->xC0);
        int i = info->x5C;
        MtxP_A cp;
        { MtxP_A* d = &cp; const Mtx_A* s = &m; __int128 t1, t0; __asm__ volatile("lq %0,0(%2); lq %1,0x10(%2); sq %0,0(%3); lq %0,0x20(%2); sq %1,0x10(%3); lq %1,0x30(%2); sq %0,0x20(%3); sq %1,0x30(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); }
        p = cHuman_ctor_cMatrix_int_charP_int_etc_2(p, cp, a, self->x64, c, self->x6C, 4, self->xA8, g, r, i, 0);
    }
    {
        void* reg = g_ActorList;
        p->x1C = reg;
        cBaseObjList_Add(reg, p);
    }
    p->b14 = 0;
    cHuman_SetNetworkID(p, info->x54);
    cGenInfoObject_ctor(ctx);
    bool act = false;
    {
        bool b = false;
        if (self->b2D) {
            if (self->b2C)
                b = true;
        }
        if (b) {
            if (NotE(self))
                act = true;
        }
    }
    if (act) {
        p->Activate();
        self->xC0++;
    } else {
        if (self->bD2)
            self->xC0++;
        char* kk = self->key;
        int n = self->xC0;
        Ref_A r(kk, n);
        void* c;
        {
            AllocGuard g;
            c = cMemMan_Allocate(0, 0x220, D_004A4A90, 0x791);
        }
        if (c)
            c = cNetNPC_ctor(c, 0, p);
        cHuman_CreateGobjController(p, 4, &r, c);
        int id = p->x10;
        void* k = self->key; cNetObj_AddSystem(id, cGenInfoObject_GetOwner(ctx, k), p);
    }
    unsigned char net;
    if (g_IsMultiplayer)
        net = D_005721C0;
    else
        net = 1;
    if (net) {
        cGenInfoObject_ctor(ctx2);
        cNPCInfoObject_ctor(o);
        void* k2 = self->key;
        int* sp = &p->serial;
        cNPCInfoObject_SetOwner_cObjectIdR_int(o, sp, cGenInfoObject_GetOwner(ctx2, k2));
        cNPCInfoObject_dtor(o, -1);
    }
    SendM(p, m);
    {
        int n = cNetObj_GetNetSystem(p->x10);
        if (n)
            cHuman_SetupNetworkFields(p, n);
    }
    p->b3598 = 1;
    {
        Sub_A* s = p->x58;
        if (s)
            s->x150 = *(int*)self->key;
    }
    self->list90.push_back(Hnd_A(p));
    self->list9C.push_back(Hnd_A(p));
    self->xBC = 0;
    self->xC8 = self->xC4;
}
#pragma pop
