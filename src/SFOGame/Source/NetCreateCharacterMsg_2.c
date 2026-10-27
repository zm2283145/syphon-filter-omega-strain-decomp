/*
 * SFOGame/Source/NetCreateCharacterMsg: 2 files, 002C6B70-002C7110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C6B70 */
#pragma push /* merge_units */
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
struct Ang { float x, y, z; Ang(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Fv { float x, y, z, w; Fv& Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; return *this; } };
struct NetId { int v; };
struct Cfg { long long v; };
struct Blk { char c[0x40]; __int128 q[64]; };
struct RNode { RNode* next; };
struct GObj { char pad[0x1C]; RNode* owner; };
struct Msg {
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
struct Actor;
struct ActorV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void Activate(); };
struct Actor : ActorV {
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
extern char D_004AC940[];
GObj* cBaseObjList_LookupObj(RNode* reg, int* id);
void cNetObj_RemovePlayer_int(int);
void cBaseObjList_Remove(RNode*, GObj*);
void cSystem_ActualScheduleDelete(float, GObj*);
float COS(float);
float SIN(float);
void* cMatrix_Set_ColumnMajorForm(M4u* m, float a, float b, float c, float d, float e, float f,
                        float g, float h, float i);
void SKL_UncompressSKL(Blk*, char*);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Actor* cHuman_ctor_cMatrix_int_charP_int_etc_2(void* p, M4u* m, int a, int b, int health, Cfg* cfg, int c, int team,
                     NetId* id, int d, int e, Blk* blk);
void cWeapon_Add(void* w, int id, int a, int b, int c, int d);
void cWeapon_Select(void* w, int id);
void cBaseObjList_Add(RNode* reg, Actor* a);
void cGOBJ_SetHitpoints(Actor* a, int h, int f);
Comp* cNetPlayer_ctor(void* p, int a, Actor* o);
void cHuman_CreateGobjController(Actor* a, int n, int b, Comp* c);
unsigned char cHuman_IsInvulnerable(Game*);
void cHuman_SetInvulnerable(Actor* a, int f);
int cNetObj_AddSystem(int id, int b, Actor* a);
void cHuman_SetNetworkID(Actor* a, int id);
void cHuman_SetupNetworkFields(Actor* a, int r);
void Hud_AppendCalloutName(char*, Actor*, int, int);
void cHud_SetCallout(int, char*, char*, int, int, int, float, float);
}

static inline void* NewMem(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004AC940, line);
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
extern "C" void netCreatePlayer_HandleNetPlayerCreate(Msg* msg, int arg1)
{
    NetId id;
    Cfg cfg;
    Fv pos;
    M4u m;
    Blk blk;
    char buf[0x90];
    Actor* a;
    Comp* c;
    int team;
    int i;
    int rid;

    if (Lookup(msg->id.v)) {
        cNetObj_RemovePlayer_int(arg1);
        cBaseObjList_Remove(g_ActorList, Lookup(msg->id.v));
        cSystem_ActualScheduleDelete(0.1f, Lookup(msg->id.v));
    }
    SetEulerPos(&m, pos.Set(msg->px, msg->py, msg->pz, 1.0f), Ang(msg->rx, msg->ry, msg->rz));
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
        a = (Actor*)p;
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
