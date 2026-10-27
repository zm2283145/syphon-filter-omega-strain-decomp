/* cWeapon_Throw: spawn a projectile at the muzzle transform and launch it at the target or aim point */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; register __int128 q; asm volatile { lq q, 0x0(s)
 sq q, 0x0(d) } }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
};
static inline void Apply(V* o, M* m, V* v) { __asm__("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }

class Obj {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(d2)
    virtual V GetPos();
    VPAD2(e) VPAD1(e2)
    virtual M GetMatrix();
};
class Ctl {
public:
    VPAD16(a) VPAD4(b)
    virtual int Active();
    VPAD16(c) VPAD8(d) VPAD4(e)
    virtual void Fired(Obj* t, int z);
};
class Actor : public Obj {
public:
    char pad04[0x8];
    int id;
    char pad10[0x48];
    Ctl* ctl;
    char pad5C[4];
    char equip[4];
};
struct W { char pad[0xB8]; float fB8; char padBC[0x34]; unsigned char fF0; };
struct Slot { int a; int id; int b; int count; };
struct Self { int pad0; Slot slots[8]; unsigned char cur; char pad85[3]; Actor* actor; char pad8C[0xD]; unsigned char b99; };
struct Proj;
extern "C" {
extern void* g_WeaponDatabase;
extern signed char D_0049D02C;
extern int g_NoneWord;
extern char g_Game[];
extern char D_004EE5C0[];
extern char D_004D92A0[];
extern char D_0049B1D0[];
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cSKM_GOBJ_GetSkeleton_void(Actor* a);
M cSkeleton_GetBoneToWorldMatrix(void* skel, int code);
void cMan_RemoveGun(void* e, int z);
W* cWeaponDB_GetEntry(void* db, int id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Proj* cGrenade_ctor(void* p, Actor* owner, M* m, W* w);
void cGrenade_SetInitialVelocity(Proj* p, V* to, float k);
void* cSystemContainer_GetSystem(void* a, void* b);
void cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(void* msg, int* sender, int action, float a, float b);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* to, int imm);
void cMessage_dtor(void* msg, int f);
void cWeapon_AddShotStat(Self* self, unsigned char b);
void cWeapon_Throw(Self* self, int* id, V* at, float k);
}
struct FireMsg {
    void* vt; char d[0x34];
    FireMsg(int* id, int act, float a, float b) { int* i = id; cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(this, i, act, a, b); }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FireMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); }
};
void cWeapon_Throw(Self* self, int* id, V* at, float k)
{
    Slot* s = &self->slots[self->cur];
    Obj* tgt = nGobjManager_LookupGOBJ_cObjectIdR(id);
    W* w;
    Proj* p;
    Actor* a = self->actor;
    char* eq = a->equip;
    M xf = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(a), D_0049D02C);
    cMan_RemoveGun(eq, 0);
    w = cWeaponDB_GetEntry(g_WeaponDatabase, s->id);
    {
        AllocGuard guard;
        p = (Proj*)cMemMan_Allocate(0, 0x130, D_0049B1D0, 0x91C);
    }
    if (p) p = cGrenade_ctor(p, self->actor, &xf, w);
    if (!tgt || *id == g_NoneWord) {
        V dst = *at;
        if (dst.w == 0.0f) {
            dst.w = 1.0f;
            M m = self->actor->GetMatrix();
            Apply(&dst, &m, &dst);
        }
        cGrenade_SetInitialVelocity(p, &dst, k);
    } else {
        V pos = tgt->GetPos();
        cGrenade_SetInitialVelocity(p, &pos, k);
    }
    if (self->actor->ctl && self->actor->ctl->Active()) {
        self->actor->ctl->Fired(tgt, 0);
        void* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
        FireMsg m(&self->actor->id, 4, 1.0f, w->fB8);
        m.Send(svc);
    }
    if (!self->b99) s->count--;
    if (w->fF0 == 7) { bool b = at->w == 1.0f; cWeapon_AddShotStat(self, b); }
}








