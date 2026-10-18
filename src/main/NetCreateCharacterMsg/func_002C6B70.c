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
extern RNode* D_004FFD44;
extern World* D_004FFC0C;
extern int D_004FFC2C;
extern Cfg D_0048C0C8;
extern char D_004AC940[];
GObj* ObjRegistry_Find(RNode* reg, int* id);
void func_003FB750(int);
void ActorWorld_RequestRemove(RNode*, GObj*);
void Object_DeleteLater(float, GObj*);
float Math_CosThunk(float);
float Math_SinThunk(float);
void* Mtx44_SetRotation(M4u* m, float a, float b, float c, float d, float e, float f,
                        float g, float h, float i);
void func_00406EC0(Blk*, char*);
void* Mem_Alloc(int pool, int size, char* file, int line);
Actor* Actor_Construct2(void* p, M4u* m, int a, int b, int health, Cfg* cfg, int c, int team,
                     NetId* id, int d, int e, Blk* blk);
void WeaponInv_Add(void* w, int id, int a, int b, int c, int d);
void WeaponInv_EquipItem(void* w, int id);
void ObjRegistry_AppendRecursive(RNode* reg, Actor* a);
void Actor_SetHealth(Actor* a, int h, int f);
Comp* func_002D85D0(void* p, int a, Actor* o);
void Actor_InitComponents(Actor* a, int n, int b, Comp* c);
unsigned char Actor_IsInvulnerable(Game*);
void Actor_SetInvulnerable(Actor* a, int f);
int NetMap_BindReceiver(int id, int b, Actor* a);
void func_00185940(Actor* a, int id);
void func_00185970(Actor* a, int r);
void Hud_AppendCalloutName(char*, Actor*, int, int);
void Hud_ShowCallout(int, char*, char*, int, int, int, float, float);
}

static inline void* NewMem(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004AC940, line);
}

static inline GObj* Lookup(int id)
{
    RNode* reg = D_004FFD44;
    GObj* o = ObjRegistry_Find(reg, &id);
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
    float cy = Math_CosThunk(y);
    float sy = Math_SinThunk(y);
    float cx = Math_CosThunk(x);
    float sx = Math_SinThunk(x);
    float cz = Math_CosThunk(z);
    float sz = Math_SinThunk(z);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    Mtx44_SetRotation(m,
                      czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);

}
extern "C" void Coop_CreatePartnerActor(Msg* msg, int arg1)
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
        func_003FB750(arg1);
        ActorWorld_RequestRemove(D_004FFD44, Lookup(msg->id.v));
        Object_DeleteLater(0.1f, Lookup(msg->id.v));
    }
    SetEulerPos(&m, pos.Set(msg->px, msg->py, msg->pz, 1.0f), Ang(msg->rx, msg->ry, msg->rz));
    SetRow(&m.r3, pos);
    id = msg->id;
    func_00406EC0(&blk, msg->name);
    {
        World* wd = D_004FFC0C;
        Game* g = wd->game;
        team = g->team;
        { const Cfg* ps = &D_0048C0C8; Cfg* pd = &cfg; *pd = *ps; }
    }
    {
        void* p = NewMem(0x35A0, 0x1AF);
        if (p) {
            M4u mc; { M4u* dd; __int128 a; __int128 b; const M4u* ss = &m; dd = &mc; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b), "+r"(dd) : "r"(ss) : "memory"); }
            p = Actor_Construct2(p, &mc, -1, 0, msg->health, &cfg, 3, team, &id, 0, -1, &blk);
        }
        a = (Actor*)p;
    }
    a->b14 = 0;
    for (i = 0; i < 6; i++) {
        short it = *(short*)((char*)msg->items + (i << 1));
        if (it != -1) WeaponInv_Add(a->inv, it, 1, 0, 1, 1);
    }
    if (msg->items[0] != -1) WeaponInv_EquipItem(a->inv, msg->items[0]);
    {
        RNode* reg = D_004FFD44;
        a->owner = reg;
        ObjRegistry_AppendRecursive(reg, a);
    }
    {
        int h = msg->health;
        a->health = h;
        Actor_SetHealth(a, h, 0);
    }
    a->comp->SetMtx(&m);
    {
        void* p = NewMem(0x54, 0x1C9);
        if (p) p = func_002D85D0(p, 0, a);
        c = (Comp*)p;
    }
    Actor_InitComponents(a, 3, 0, c);
    Actor_SetInvulnerable(a, Actor_IsInvulnerable(D_004FFC0C->game));
    a->Activate();
    rid = NetMap_BindReceiver(msg->id.v, arg1, a);
    func_00185940(a, msg->id.v);
    func_00185970(a, rid);
    buf[0] = 0;
    Hud_AppendCalloutName(buf, a, arg1, 1);
    Hud_ShowCallout(D_004FFC2C, a->nameC, buf + 1, 0, 0, 0, -1.0f, 0.0f);
}
