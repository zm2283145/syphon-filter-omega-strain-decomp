/*
 * SFOGame/Source/weapon: 5 files, 00141E20-00142140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00141E20 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00141E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00141E20 */

/* merge_units: begin func_00142140 */
#pragma push /* merge_units */
extern void cAirTaser_Reset(int);

void cWeapon_SetAmmoPlayerDeath(int a0) {
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00142160;
    cAirTaser_Reset(a0);
L00142160:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142140 */

/* merge_units: begin func_00142170 */
#pragma push /* merge_units */
typedef struct {
    int a;
    int id;
    int ammo;
    int extra;
} Slot_142170;
typedef struct {
    int pad0;
    Slot_142170 slots[6];
    char pad64[0x24];
    int actor;
} Inv_142170;
typedef struct {
    char pad0[0x70];
    int clip;
    int f74;
    char pad78[0x78];
    unsigned char fF0;
} Wpn_142170;
#if 0 /* merge_units */
extern int g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(int*)&g_WeaponDatabase) /* merge_units */

extern float MaxNpcAmmoPct;
extern float D_00489C20;
#if 0 /* merge_units */
Wpn_142170* cWeaponDB_GetEntry(int, int);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((Wpn_142170 *)cWeaponDB_GetEntry((void *)(a0), (a1))) /* merge_units */

int cHuman_AdjustMaxClips(int, int);
int Libc_Rand(void);
static inline float frand(void) { return Libc_Rand() / 2147483648.0f; }

void cWeapon_SetAmmoNpcDeath(Inv_142170* inv)
{
    int i;
    for (i = 0; i < 6; i++) {
        Slot_142170* s = &inv->slots[i];
        if (s->id != -1) {
            Wpn_142170* w = cWeaponDB_GetEntry(g_WeaponDatabase, s->id);
            int total = w->clip * cHuman_AdjustMaxClips(inv->actor, w->f74);
            float pct;
            int n;
            pct = frand();
            pct *= D_00489C20 - MaxNpcAmmoPct;
            pct += MaxNpcAmmoPct;
            if (total < 10) pct *= 2.0f;
            n = (int)(total * pct);
            if (w->fF0 == 1) {
                s->extra = n;
                s->ammo = 0;
            } else {
                if (w->clip < n) {
                    s->extra = n - w->clip;
                    n -= s->extra;
                } else {
                    s->extra = 0;
                }
                s->ammo = n;
                if (s->extra > 0) {
                    int r = (int)(w->clip * (frand()));
                    s->ammo -= r;
                    s->extra += r;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142170(void) {}
#undef g_WeaponDatabase /* merge_units */
#undef cWeaponDB_GetEntry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142170 */

/* merge_units: begin func_00142320 */
#pragma push /* merge_units */
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { char pad[0xA8]; unsigned char xA8; } WDef_2320;

#if 0 /* merge_units */
extern WDef_2320* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((WDef_2320 *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */


extern void cBackpack_AddWeapon(void* o, int id, int d, int c, int z);
extern void cWeapon_RemoveWeapon(INV* self, unsigned char slot, int a, int b, int c);
void cWeapon_InitBackpack(INV* self, void* o)
{
    int i;
    if (self->lock)
        return;
    for (i = 7; i >= 0; i--) {
        E_INV* e = (E_INV*)((char*)self + i * 16 + 4);
        if (e->id != -1 && cWeaponDB_GetEntry(g_WeaponDatabase, e->id)->xA8) {
            cBackpack_AddWeapon(o, e->id, e->d, e->c, 0);
            cWeapon_RemoveWeapon(self, i, 0, 0, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142320(void) {}
#undef cWeaponDB_GetEntry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142320 */

/* merge_units: begin func_001423E0 */
#pragma push /* merge_units */
typedef struct { int a0; int a4; int id; int ac; } S23E0;
#if 0 /* merge_units */
extern void cWeapon_RemoveWeapon(void* self, unsigned char slot, int a, int b, int c);
#endif /* merge_units */
#define cWeapon_RemoveWeapon(a0, a1, a2, a3, a4) (cWeapon_RemoveWeapon((INV *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


void cWeapon_RemoveAllWeapons(S23E0* self)
{
    int i;
    S23E0* p;
    i = 0;
    p = self;
    do {
        if (p->id != -1)
            cWeapon_RemoveWeapon(self, i, 0, 1, 0);
        i++;
        p++;
    } while (i < 6);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001423E0(void) {}
#undef cWeapon_RemoveWeapon /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001423E0 */
