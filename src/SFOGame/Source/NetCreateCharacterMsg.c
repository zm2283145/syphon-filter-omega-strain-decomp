/*
 * SFOGame/Source/NetCreateCharacterMsg: 5 files, 002C6690-002C72A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C6690 */
#pragma push /* merge_units */
/* netCreateNPC_HandleNetNPCCreate: network actor-update message handler (NetCreateCharacterMsg.cc): reposition an
 * existing actor, rebuild its components and replay its state events. */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "v4_asm_copy.h"
static inline void StRR(void* d, __int128 t) { asm { .set reorder
 sq t, 0(d) } }
static inline void StR(void* d, __int128 t) { asm { sq t, 0(d) } }
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
struct V4u { __int128 q; };
struct M4u {
    __int128 r0, r1, r2, r3;
    M4u() {}
    M4u(const M4u& s)
    {
        const M4u* ps = &s;
        M4u* pd = this;
        __int128 a, b;
        __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(ps), "r"(pd) : "memory");
    }
};
struct Ang { float x, y, z, w; Ang(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Fv { float x, y, z, w; Fv& Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; return *this; } };
struct NetId { int v; };
struct Msg {
    char pad0[4];
    NetId id;
    float rx, ry, rz;
    float px, py, pz;
    char pad20[0x4C - 0x20];
    unsigned char b4C;
    unsigned char b4D;
    short health;
};
struct Q4 { __int128 q; };
struct Ev30 { char* vt; char pad04[0x20]; int f24; unsigned char f28; char pad29[3]; int f2C; };
struct Ev50 { char* vt; char pad04[0x20]; int f24; unsigned char f28; char pad29[7]; Q4 q30; float f40; float f44; unsigned char f48; char pad49[7]; };
struct Ev70 { char* vt; char pad04[0x20]; unsigned char f24; char pad25[0xB]; M4u m; };
struct Comp;
struct Actor {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void Activate();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual M4u GetXf();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char Kind();
    char pad4[0x10];
    unsigned char b14;
    char pad15[0x3398 - 0x15];
    int health;
};
extern "C" {
extern char D_004AC940[];
extern char g_ActorActionMsgClass[];
extern char g_TeleportMsgClass[];
extern char D_004E0840[];
extern char D_004E01E0[];
extern char D_004E0120[];
extern char D_004D9360[];
float COS(float);
float SIN(float);
void* cMatrix_Set_ColumnMajorForm(M4u* m, float a, float b, float c, float d, float e, float f,
                        float g, float h, float i);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Actor* nGobjManager_LookupGOBJ_cObjectIdR(NetId* id);
Comp* cNetNPC_ctor(void* p, int a, Actor* o);
#if 0 /* merge_units */
void cHuman_CreateGobjController(Actor* a, int n, int b, Comp* c);
#endif /* merge_units */
void cHuman_CreateGobjController(void*, int, int, void*); /* merge_units */
#define cHuman_CreateGobjController(a0, a1, a2, a3) (cHuman_CreateGobjController((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

#if 0 /* merge_units */
void cGOBJ_SetHitpoints(Actor* a, int h, int f);
#endif /* merge_units */
void cGOBJ_SetHitpoints(void*, int, int); /* merge_units */
#define cGOBJ_SetHitpoints(a0, a1, a2) (cGOBJ_SetHitpoints((void *)(a0), (a1), (a2))) /* merge_units */

void cMessage_ctor_cMessageNameR(void* e, char* t);
void QueueMessage_cMessageR_cSystemP_int(void* e, Actor* a, int f);
void cMessage_dtor(void* e, int f);
#if 0 /* merge_units */
int cNetObj_AddSystem(int id, int b, Actor* a);
#endif /* merge_units */
int cNetObj_AddSystem(int, int, void*); /* merge_units */
#define cNetObj_AddSystem(a0, a1, a2) (cNetObj_AddSystem((a0), (a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
void cHuman_SetNetworkID(Actor* a, int id);
#endif /* merge_units */
void cHuman_SetNetworkID(void*, int); /* merge_units */
#define cHuman_SetNetworkID(a0, a1) (cHuman_SetNetworkID((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cHuman_SetupNetworkFields(Actor* a, int r);
#endif /* merge_units */
void cHuman_SetupNetworkFields(void*, int); /* merge_units */
#define cHuman_SetupNetworkFields(a0, a1) (cHuman_SetupNetworkFields((void *)(a0), (a1))) /* merge_units */

}

static inline void* NewMem(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004AC940, line);
}

static inline void SetRow(__int128* d0, const Fv& v)
{
    __int128 tp;
    __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(tp) : "r"(d0), "r"(&v) : "memory");
}

static inline void SetEulerPos(M4u* m, const Fv& p, const Ang& r)
{
    float y = r.y;
    float x = r.x;
    float z = r.z;
    float cy = COS(y);
    float sy = SIN(y);
    float cx = COS(x);
    float sx = SIN(x);
    float cz = COS(z);
    float sz = SIN(z);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(m,
                      czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);

}

static inline void EvInit(Ev30* e, int id, unsigned char b)
{
    cMessage_ctor_cMessageNameR(e, g_ActorActionMsgClass);
    e->vt = D_004E0840;
    e->f24 = id;
    e->f28 = b;
}

static inline void Ev50Init(Ev50* e, const __int128& v, float a, float b, unsigned char k)
{
    cMessage_ctor_cMessageNameR(e, g_ActorActionMsgClass);
    e->vt = D_004E0840;
    e->f24 = 0;
    e->f28 = 0xC;
    {
        void* d = &e->q30; __int128 tp; const void* src = &v;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(tp) : "r"(d), "r"(src) : "memory");
    }
    e->f40 = a;
    e->f44 = b;
    e->f48 = k;
    e->vt = D_004E0120;
}

static inline void MCopy(M4u* d0, const M4u* s0)
{
    void* d = d0; __int128 qa; __int128 qb; const void* s = s0;
    __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
}

extern "C" void netCreateNPC_HandleNetNPCCreate(Msg* msg, int arg1)
{
    NetId id;
    Ang r(msg->rx, msg->ry, msg->rz);
    Fv pos;
    M4u m;
    Actor* a;
    Comp* c;

    SetEulerPos(&m, pos.Set(msg->px, msg->py, msg->pz, 1.0f), r);
    SetRow(&m.r3, pos);
    id = msg->id;
    a = nGobjManager_LookupGOBJ_cObjectIdR(&id);
    if (a) {
        {
            void* p = NewMem(0x220, 0x21B);
            if (p) p = cNetNPC_ctor(p, 0, a);
            c = (Comp*)p;
        }
        cHuman_CreateGobjController(a, 4, 0, c);
        {
            int h = msg->health;
            a->health = h;
            cGOBJ_SetHitpoints(a, h, 0);
        }
        if (a->Kind() == 3) {
            {
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x3A, 0);
                QueueMessage_cMessageR_cSystemP_int(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x3F, 0);
                QueueMessage_cMessageR_cSystemP_int(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                int v = msg->b4D;
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x42, 2);
                p->vt = D_004E01E0;
                p->f2C = v;
                QueueMessage_cMessageR_cSystemP_int(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                const M4u& t = a->GetXf();
                Ev50 e;
                Ev50* p = &e;
                const __int128& r = t.r1;
                Ev50Init(p, r, 0.0f, 0.0f, 2);
                QueueMessage_cMessageR_cSystemP_int(&e, a, 1);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
        }
        if (msg->b4C) a->Activate();
        {
            Ev70 e;
            Ev70* p = &e;
            cMessage_ctor_cMessageNameR(p, g_TeleportMsgClass);
            p->vt = D_004D9360;
            p->f24 = 2;
            MCopy(&p->m, &m);
            QueueMessage_cMessageR_cSystemP_int(&e, a, 1);
            e.vt = D_004D9360;
            cMessage_dtor(p, 0);
        }
        a->b14 = 0;
        cHuman_SetNetworkID(a, msg->id.v);
        cHuman_SetupNetworkFields(a, cNetObj_AddSystem(msg->id.v, arg1, a));
    } else {
        cNetObj_AddSystem(msg->id.v, arg1, a);
    }
}
#undef cHuman_CreateGobjController /* merge_units */
#undef cGOBJ_SetHitpoints /* merge_units */
#undef cNetObj_AddSystem /* merge_units */
#undef cHuman_SetNetworkID /* merge_units */
#undef cHuman_SetupNetworkFields /* merge_units */
static inline void merge_flush_func_002C6690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C6690 */

/* merge_units: begin func_002C6B70 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma opt_rotateloops off
#pragma opt_strength_reduction off

struct Ang_002C6B70 { float x, y, z; Ang_002C6B70(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Cfg { long long v; };
struct Blk { char c[0x40]; __int128 q[64]; };
struct RNode { RNode* next; };
struct GObj { char pad[0x1C]; RNode* owner; };
struct Msg_002C6B70 {
    char pad0[4];
    NetId id;
    float rx, ry, rz;
    float px, py, pz;
    int health;
    short items[6];
    char name[0x10];
};
struct Comp;
struct Comp { virtual void v0(); virtual void SetMtx(M4u*); };
struct Actor_002C6B70;
struct ActorV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Activate(); };
struct Actor_002C6B70 : ActorV {
    char pad4[8];
    char nameC[8];
    unsigned char b14;
    char pad15[7];
    RNode* owner;
    char pad20[0x30];
    Comp* comp;
    char pad54[0x3398 - 0x54];
    int health;
    char pad339C[0x3524 - 0x339C];
    void* inv;
};
struct Game { char pad[0x3264]; int team; };
struct World { char pad[0x30]; Game* game; };
extern "C" {
extern RNode* g_ActorList;
extern World* g_LocalPlayer;
extern int g_Hud;
extern Cfg D_0048C0C8;
GObj* cBaseObjList_LookupObj(RNode* reg, int* id);
void cNetObj_RemovePlayer_int(int);
void cBaseObjList_Remove(RNode*, GObj*);
void cSystem_ActualScheduleDelete(float, GObj*);
void SKL_UncompressSKL(Blk*, char*);
Actor_002C6B70* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* p, M4u* m, int a, int b, int health, Cfg* cfg, int c, int team,
                     NetId* id, int d, int e, Blk* blk);
void cWeapon_Add(void* w, int id, int a, int b, int c, int d);
void cWeapon_Select(void* w, int id);
void cBaseObjList_Add(RNode* reg, Actor_002C6B70* a);
#if 0 /* merge_units */
void cGOBJ_SetHitpoints(Actor_002C6B70* a, int h, int f);
#endif /* merge_units */
#define cGOBJ_SetHitpoints(a0, a1, a2) (cGOBJ_SetHitpoints((void *)(a0), (a1), (a2))) /* merge_units */

Comp* cNetPlayer_ctor(void* p, int a, Actor_002C6B70* o);
#if 0 /* merge_units */
void cHuman_CreateGobjController(Actor_002C6B70* a, int n, int b, Comp* c);
#endif /* merge_units */
#define cHuman_CreateGobjController(a0, a1, a2, a3) (cHuman_CreateGobjController((void *)(a0), (a1), (a2), (void *)(a3))) /* merge_units */

unsigned char cHuman_IsInvulnerable(Game*);
void cHuman_SetInvulnerable(Actor_002C6B70* a, int f);
#if 0 /* merge_units */
int cNetObj_AddSystem(int id, int b, Actor_002C6B70* a);
#endif /* merge_units */
#define cNetObj_AddSystem(a0, a1, a2) (cNetObj_AddSystem((a0), (a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
void cHuman_SetNetworkID(Actor_002C6B70* a, int id);
#endif /* merge_units */
#define cHuman_SetNetworkID(a0, a1) (cHuman_SetNetworkID((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cHuman_SetupNetworkFields(Actor_002C6B70* a, int r);
#endif /* merge_units */
#define cHuman_SetupNetworkFields(a0, a1) (cHuman_SetupNetworkFields((void *)(a0), (a1))) /* merge_units */

void Hud_AppendCalloutName(char*, Actor_002C6B70*, int, int);
void cHud_SetCallout(int, char*, char*, int, int, int, float, float);
}

static inline GObj* Lookup(int id)
{
    RNode* reg = g_ActorList;
    GObj* o = cBaseObjList_LookupObj(reg, &id);
    if (o) {
        RNode* n = o->owner;
        while (n) {
            if (n == reg) return o;
            n = n->next;
        }
    }
    return 0;
}

static inline void SetEulerPos_002C6B70(M4u* m, const Fv& p, const Ang_002C6B70& r)
{
    float y = r.y;
    float x = r.x;
    float z = r.z;
    float cy = COS(y);
    float sy = SIN(y);
    float cx = COS(x);
    float sx = SIN(x);
    float cz = COS(z);
    float sz = SIN(z);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(m,
                      czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);

}
extern "C" void netCreatePlayer_HandleNetPlayerCreate(Msg_002C6B70* msg, int arg1)
{
    NetId id;
    Cfg cfg;
    Fv pos;
    M4u m;
    Blk blk;
    char buf[0x90];
    Actor_002C6B70* a;
    Comp* c;
    int team;
    int i;
    int rid;

    if (Lookup(msg->id.v)) {
        cNetObj_RemovePlayer_int(arg1);
        cBaseObjList_Remove(g_ActorList, Lookup(msg->id.v));
        cSystem_ActualScheduleDelete(0.1f, Lookup(msg->id.v));
    }
    SetEulerPos_002C6B70(&m, pos.Set(msg->px, msg->py, msg->pz, 1.0f), Ang_002C6B70(msg->rx, msg->ry, msg->rz));
    SetRow(&m.r3, pos);
    id = msg->id;
    SKL_UncompressSKL(&blk, msg->name);
    {
        World* wd = g_LocalPlayer;
        Game* g = wd->game;
        team = g->team;
        { const Cfg* ps = &D_0048C0C8; Cfg* pd = &cfg; *pd = *ps; }
    }
    {
        void* p = NewMem(0x35A0, 0x1AF);
        if (p) {
            M4u mc; { M4u* dd; __int128 a; __int128 b; const M4u* ss = &m; dd = &mc; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b), "+r"(dd) : "r"(ss) : "memory"); }
            p = cHuman_ctor_cMatrix_int_charP_int_etc_2(p, &mc, -1, 0, msg->health, &cfg, 3, team, &id, 0, -1, &blk);
        }
        a = (Actor_002C6B70*)p;
    }
    a->b14 = 0;
    for (i = 0; i < 6; i++) {
        short it = *(short*)((char*)msg->items + (i << 1));
        if (it != -1) cWeapon_Add(a->inv, it, 1, 0, 1, 1);
    }
    if (msg->items[0] != -1) cWeapon_Select(a->inv, msg->items[0]);
    {
        RNode* reg = g_ActorList;
        a->owner = reg;
        cBaseObjList_Add(reg, a);
    }
    {
        int h = msg->health;
        a->health = h;
        cGOBJ_SetHitpoints(a, h, 0);
    }
    a->comp->SetMtx(&m);
    {
        void* p = NewMem(0x54, 0x1C9);
        if (p) p = cNetPlayer_ctor(p, 0, a);
        c = (Comp*)p;
    }
    cHuman_CreateGobjController(a, 3, 0, c);
    cHuman_SetInvulnerable(a, cHuman_IsInvulnerable(g_LocalPlayer->game));
    a->Activate();
    rid = cNetObj_AddSystem(msg->id.v, arg1, a);
    cHuman_SetNetworkID(a, msg->id.v);
    cHuman_SetupNetworkFields(a, rid);
    buf[0] = 0;
    Hud_AppendCalloutName(buf, a, arg1, 1);
    cHud_SetCallout(g_Hud, a->nameC, buf + 1, 0, 0, 0, -1.0f, 0.0f);
}
#undef cGOBJ_SetHitpoints /* merge_units */
#undef cHuman_CreateGobjController /* merge_units */
#undef cNetObj_AddSystem /* merge_units */
#undef cHuman_SetNetworkID /* merge_units */
#undef cHuman_SetupNetworkFields /* merge_units */
static inline void merge_flush_func_002C6B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C6B70 */

/* merge_units: begin func_002C7110 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z; } V3;
struct V4 { float x, y, z, w; V4() {} V4(const V4& o) { __int128 t; const V4* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } } } __attribute__((aligned(16)));
typedef struct { V4 r[4]; } M4;
typedef struct {
    char* name;
    int a1;
    V3 rot;
    V3 pos;
    short arr[6];
    char str[0x20];
    unsigned char b1;
    unsigned char b2;
    short s;
} __attribute__((aligned(16))) Msg7110;
extern "C" {
extern unsigned char D_0055C780[];
extern char D_004DE158[];
extern int D_0051EE78;
extern void cEulerAngle_T_1_2_ctor_cMatrixR(V4* out, M4* m);
extern bool cNetObj_SendMessage_int_int_ucharP_int_etc(int a, int b, void* c, int target, int type);
bool netCreateNPC_SendCreated(int idx, int a1, int a2, M4* m, const char* str, short* sh, unsigned char b1, unsigned char b2, int sv);
void* memset(void* d, int c, unsigned int n);
unsigned int strlen(const char* s);
char* strncpy(char* d, const char* s, unsigned int n);
}

static inline void Q1(void* d, const void* s) { __int128 q; asm volatile { lq q, 0(s)
 sq q, 0(d) } }
static inline bool IsConnected(int idx)
{
    bool ok = true;
    unsigned char st = D_0055C780[idx];
    if (st != 1 && st != 2) ok = false;
    return ok;
}

#pragma opt_unroll_loops off
#pragma opt_rotateloops off

bool netCreateNPC_SendCreated(int idx, int a1, int a2, M4* m, const char* str, short* sh, unsigned char b1, unsigned char b2, int sv)
{
    Msg7110 msg;
    V4 e;
    V4 p;
    int i;
    bool ret = false;
    if (IsConnected(idx)) {
        msg.name = D_004DE158;
        msg.a1 = a1;
        cEulerAngle_T_1_2_ctor_cMatrixR(&e, m);
        msg.rot.x = e.x; msg.rot.y = e.y; msg.rot.z = e.z;
        Q1(&p, &m->r[3]);
        msg.pos.x = p.x;
        msg.pos.y = p.y;
        msg.pos.z = p.z;
        memset(msg.str, 0, 0x20);
        strncpy(msg.str, str, strlen(str));
        msg.s = sv;
        for (i = 0; i != 6; i++) msg.arr[i] = sh[i];
        msg.b1 = b1;
        msg.b2 = b2;
        Msg7110* pm = &msg; if (cNetObj_SendMessage_int_int_ucharP_int_etc(D_0051EE78, 0x50, pm, idx, 0x40)) ret = true;
    }
    return ret;
}
static inline void merge_flush_func_002C7110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C7110 */

/* merge_units: begin func_002C72A0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct {
    char* name;
    int a1;
    V3 rot;
    V3 pos;
    int s1;
    short arr[6];
    char buf[0x400];
} __attribute__((aligned(16))) Msg72A0;
extern "C" {
extern char D_004DE148[];
extern int D_0051EE70;
extern void* SKL_CompressSKL(void* data, int* len);
bool netCreatePlayer_SendCreated(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1);
}

static inline void QCopy(void* dst0, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    void* dst = dst0;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}

#pragma opt_unroll_loops off
#pragma opt_rotateloops off

bool netCreatePlayer_SendCreated(int idx, int a1, int a2, M4* m, void* data, short* sh, int s1)
{
    int len;
    Msg72A0 msg;
    V4 e;
    V4 p;
    int i;
    bool ret = false;
    if (IsConnected(idx)) {
        msg.name = D_004DE148;
        msg.a1 = a1;
        cEulerAngle_T_1_2_ctor_cMatrixR(&e, m);
        msg.rot.x = e.x; msg.rot.y = e.y; msg.rot.z = e.z;
        Q1(&p, &m->r[3]);
        msg.pos.x = p.x;
        msg.pos.y = p.y;
        msg.pos.z = p.z;
        msg.s1 = s1;
        for (i = 0; i != 6; i++) msg.arr[i] = sh[i];
        void* d = SKL_CompressSKL(data, &len);
        QCopy(msg.buf, d, len);
        Msg72A0* pm = &msg; if (cNetObj_SendMessage_int_int_ucharP_int_etc(D_0051EE70, 0x430, pm, idx, 0x40)) ret = true;
    }
    return ret;
}
static inline void merge_flush_func_002C72A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C72A0 */

/* merge_units: begin func_002C7460 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    int version;
    int ids[6];
    short values[6];
    char name[0x20];
    unsigned char flagA;
    unsigned char flagB;
    short count;
    char pad60[0xC];
} SaveHeader;
extern int NetRegisterMessageStart(void* stream);
extern int NetMessageField(SaveHeader* hdr, void* dst, int size, int count);
extern int NetRegisterApplicationMessage(int* out, void (*cb)(void));
extern void netCreateNPC_netCreateNPCCallback(void);

/* Reads the save header fields in order; returns the first error, or 0. */
int netCreateNPC_InitNet(void* stream)
{
    SaveHeader hdr;
    int handle;
    int err;
    hdr.vtable = D_004DE158;
    err = NetRegisterMessageStart(stream);
    if (err == 0) {
        err = NetMessageField(&hdr, &hdr.version, 4, 1);
        if (err == 0) {
            err = NetMessageField(&hdr, hdr.ids, 4, 6);
            if (err == 0) {
                err = NetMessageField(&hdr, hdr.name, 1, 0x20);
                if (err == 0) {
                    err = NetMessageField(&hdr, &hdr.count, 2, 1);
                    if (err == 0) {
                        err = NetMessageField(&hdr, hdr.values, 2, 6);
                        if (err == 0) {
                            err = NetMessageField(&hdr, &hdr.flagA, 1, 1);
                            if (err == 0) {
                                err = NetMessageField(&hdr, &hdr.flagB, 1, 1);
                                if (err == 0) {
                                    err = NetRegisterApplicationMessage(&handle, netCreateNPC_netCreateNPCCallback);
                                    if (err == 0) {
                                        D_0051EE78 = handle;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return err;
}
static inline void merge_flush_func_002C7460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C7460 */
