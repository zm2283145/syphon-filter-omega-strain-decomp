/*
 * SFOGame/Source/weapon: 13 files, 00140EA0-00141E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00140EA0 */
#pragma push /* merge_units */
// AddExtraBullets(cBullet*, cBulletInit&). cMatrix copy ctor = 2-temp volatile lq/sq asm (keeps binit in s1); cEulerAngle ctor gives retail's ang store/reload;
// Euler temps declared cycz,cysz,sycz,sysz; RandRange(-D,D) inline (no RandPM); MulM(d,m,p) w/ locals pp,mm fixes addr regs.
#pragma cplusplus on
#include "types.h"
#pragma fp_contract off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off

struct cMatrix { float m[4][4]; cMatrix() {} cMatrix(const cMatrix& o) { cMatrix* d = this; const cMatrix* s = &o; __int128 a, b; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(s), "r"(d) : "memory"); } } __attribute__((aligned(16)));
struct cEulerAngle_T { float x; float y; float z; unsigned int pad; cEulerAngle_T(float ax, float ay, float az) { x = ax; y = ay; z = az; } };
struct cBullet;
struct cBulletInit {
    cMatrix mat;
    float speed;
    char pad44[0xD6 - 0x44];
    unsigned char drawTracer;
};

extern "C" {
int Libc_Rand(void);
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(cMatrix* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
cBullet* cBulletManager_AddBullet(cBulletInit& binit);
void cBullet_AddBlastSibling(cBullet* a, cBullet* b);
extern float D_00489C38;
extern float D_00489C40;
extern float D_00489C48;
extern int D_00489DB0[4];
extern int D_00489DC0[4];
}

static inline float RandF() { float m = 2147483648.0f; return (float)Libc_Rand() / (1.0f + m); }
static inline float RandRange(float lo, float hi) { float l = lo; float h = hi; return l + (h - l) * RandF(); }

static inline float RandPM(float s) { return RandRange(-s, s); }

static inline void EulerToMatrix(cMatrix* m, const cEulerAngle_T& a)
{
    float az = a.z; float ax = a.x; float ay = a.y;
    float cz = COS(az); float sz = SIN(az);
    float cx = COS(ax); float sx = SIN(ax);
    float cy = COS(ay); float sy = SIN(ay);
    float cycz = cy * cz; float cysz = cy * sz; float sycz = sy * cz; float sysz = sy * sz;
    cMatrix_Set_ColumnMajorForm(m,
        cycz + sysz * sx, -cysz + sycz * sx, sy * cx,
        cx * sz, cx * cz, -sx,
        -sycz + cysz * sx, sysz + cycz * sx, cy * cx);
}

static inline void MulM(void* d, void* m, void* p) {
    void* pp = p; void* mm = m;
    asm {
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf8, 0x0(pp)
        lqc2 vf9, 0x10(pp)
        lqc2 vf10, 0x20(pp)
        lqc2 vf11, 0x30(pp)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(d)
        sqc2 vf9, 0x10(d)
        sqc2 vf10, 0x20(d)
        sqc2 vf11, 0x30(d)
    }
}

extern "C" void AddExtraBullets(cBullet* bullet, cBulletInit& binit)
{
    cMatrix oldMat = binit.mat;
    float oldSpeed = binit.speed;
    binit.drawTracer = 0;
    float baseYang = 6.28f * RandF();
    cBullet* bullets[5];
    bullets[0] = bullet;
    int i;
    for (i = 0; i < 4; i++) {
        float yang = baseYang + RandRange(-D_00489C40, D_00489C40);
        cEulerAngle_T ang(D_00489C38 * D_00489DB0[i], yang, D_00489C38 * D_00489DC0[i]);
        cMatrix offset;
        EulerToMatrix(&offset, ang);
        MulM(&offset, &oldMat, &offset);
        binit.mat.m[0][0] = offset.m[0][0];
        binit.mat.m[0][1] = offset.m[0][1];
        binit.mat.m[0][2] = offset.m[0][2];
        binit.mat.m[1][0] = offset.m[1][0];
        binit.mat.m[1][1] = offset.m[1][1];
        binit.mat.m[1][2] = offset.m[1][2];
        binit.mat.m[2][0] = offset.m[2][0];
        binit.mat.m[2][1] = offset.m[2][1];
        binit.mat.m[2][2] = offset.m[2][2];
        binit.mat.m[0][3] = offset.m[0][3];
        binit.mat.m[1][3] = offset.m[1][3];
        binit.mat.m[2][3] = offset.m[2][3];
        binit.speed = oldSpeed + RandRange(-D_00489C48, D_00489C48);
        bullets[i + 1] = cBulletManager_AddBullet(binit);
    }
    for (int i2 = 0; i2 < 5; i2++) {
        int j;
        for (j = 0; j < 5; j++) {
            if (i2 != j)
                cBullet_AddBlastSibling(bullets[i2], bullets[j]);
        }
    }
}
static inline void merge_flush_func_00140EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00140EA0 */

/* merge_units: begin func_00141240 */
#pragma push /* merge_units */
#include "vslot_pad.h"

typedef struct { int a; int id; int b; int count; } S141240;
typedef struct { char pad[0xF0]; unsigned char kind; } W141240;
extern void* g_WeaponDatabase;
#if 0 /* merge_units */
extern W141240* cWeaponDB_GetEntry(void*, int);
#endif /* merge_units */
char* cWeaponDB_GetEntry(void* db, int id); /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((W141240 *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

extern int cWeapon_ReadyToFire(void*, int);
int cWeapon_Ready(char* self) {
    unsigned char i = *(unsigned char*)(self + 0x84);
    S141240* s;
    if (i != 6) {
        s = (S141240*)(self + (i << 4) + 4);
        switch (cWeaponDB_GetEntry(g_WeaponDatabase, s->id)->kind) {
        case 0: case 8: case 9:
            return cWeapon_ReadyToFire(self, 0);
        case 1: case 7:
            return s->count > 0;
        case 3: case 4: case 5: case 10:
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141240(void) {}
#undef cWeaponDB_GetEntry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00141240 */

/* merge_units: begin func_00141300 */
#pragma push /* merge_units */
#pragma cplusplus on
class R_1300 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1300 { void* vt; char pad[0x20]; int id; char f28; char pad29[7]; };
struct SEv_1300 { void* vt; char pad4[0x1C]; char f20; char pad21[0x57]; char f78[0x9C]; char f114[0xAC]; };
struct Slot_1300 { int pad0; int id; int f8; int count; };
struct Own_1300 { char pad[0x14]; unsigned char f14; char pad15[0x43]; R_1300* recv; };
struct W_1300 { char pad[0x48]; unsigned char kind; char pad49[0xA7]; unsigned char fF0; };
struct S_1300 { int pad0; Slot_1300 slots[8]; unsigned char cur; char pad85[3]; Own_1300* own; };
extern "C" {
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004DAE30[];
extern char g_Game[];
extern char D_004F27F0[];
extern char D_004F2990[];
extern char D_004F2B30[];
#if 0 /* merge_units */
W_1300* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((W_1300 *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */




void cMessage_ctor_cMessageNameR(void* e, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* e, void* target, int a);
void cMessage_dtor(void* e, int f);
void cPlaySoundMsg_ctor_cSndFxR(void* e, void* preset, void* src);
void cFileMan_dtor(void* p, int a);
}
extern "C" int cWeapon_ReloadIfOutOfAmmo(S_1300* self)
{
    SEv_1300 se;
    Ev_1300 e;
    if (self->cur != 6) {
        Slot_1300* s = &self->slots[self->cur];
        W_1300* w = cWeaponDB_GetEntry(g_WeaponDatabase, s->id);
        if (!w->fF0 && !s->f8) {
            if (s->count > 0) {
                cMessage_ctor_cMessageNameR(&e, g_ActorActionMsgClass);
                e.f28 = 0;
                e.vt = D_004E0840;
                e.id = 0x3C;
                QueueMessage_cMessageR_cSystemP_int(&e, self->own, 0);
                e.vt = D_004E0840;
                cMessage_dtor(&e, 0);
                return 1;
            }
            if (self->own->f14) {
                unsigned char local = 0;
                R_1300* r = self->own->recv;
                if (r && r->IsLocal())
                    local = 1;
                if (local) {
                    char* preset;
                    switch (w->kind) {
                    case 2:
                        preset = D_004F2990;
                        break;
                    case 4:
                        preset = D_004F2B30;
                        break;
                    default:
                        preset = D_004F27F0;
                        break;
                    }
                    if (preset) {
                        cPlaySoundMsg_ctor_cSndFxR(&se, preset, self->own);
                        se.f20 = 1;
                        QueueMessage_cMessageR_cSystemP_int(&se, g_Game, 0);
                        se.vt = D_004DAE30;
                        cFileMan_dtor(se.f114, -1);
                        cFileMan_dtor(se.f78, -1);
                        cMessage_dtor(&se, 0);
                    }
                }
            }
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141300(void) {}
#undef cWeaponDB_GetEntry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00141300 */

/* merge_units: begin func_001414D0 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V Sub(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(&a0), "r"(&b0) : "memory");
    return r;
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Len(V* p) {
    float len;
    len = 0.0f;
    { __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(p) : "memory"); }
    return len;
}
struct E { float x, y, z; unsigned int pad; } __attribute__((aligned(16)));
class Ctrl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Test();
};
struct Mv { char pad[0x310]; V vel; };
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt();
    VPAD1(g)
    virtual unsigned char State();
    char pad04[0x8];
    int id;
    char pad10[0x3C];
    int w4C;
    char pad50[8];
    Ctrl* ctrl;
    char pad5C[0x3310 - 0x5C];
    Mv* mv;
};
struct Hnd { Actor* p; int id; };
static inline bool IdEq(Actor* p, Hnd* h) { return p->id == h->id; }
static inline Actor* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct WNode { WNode* prev; WNode* next; Hnd h; };
struct WIt2 {
    WNode* volatile n;
    WIt2() {}
    WIt2(WNode* a) { n = a; }
    Hnd& operator*() { return n->h; }
    WIt2& operator++() { n = n->next; return *this; }
    bool operator!=(const WIt2& o) const { return n != o.n; }
};
struct WList { int x0; int list; int x8; };
struct Self { char pad[0x88]; Actor* actor; };
extern "C" {
extern WList D_004F78DC;
extern int g_HumanActorClassKey[];
extern float D_00489D80;
extern float D_00489D88;
extern float D_00489D90;
extern float D_00489D98;
extern signed char D_004E1D88;
extern V D_004E1D90;
#if 0 /* merge_units */
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
#endif /* merge_units */
void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* self); /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(a0) ((WNode *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2((a0))) /* merge_units */

#if 0 /* merge_units */
int cHuman_IsInvulnerable(Actor* a);
#endif /* merge_units */
int cHuman_IsInvulnerable(void*); /* merge_units */
#define cHuman_IsInvulnerable(a0) (cHuman_IsInvulnerable((void *)(a0))) /* merge_units */

void GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(Actor* a, Actor* b, E* out);
}
static inline WIt2 WBegin(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)->next); return r; }
static inline WIt2 WEnd(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)); return r; }
static inline int Team() { int* p = g_HumanActorClassKey; return *p; }
static inline bool CtrlBusy(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->Test()) r = true; return r; }
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline const V& Vel(Actor* a) { return *(a->mv ? &a->mv->vel : &Zero()); }
static inline float Sq(float x) { return x * x; }

extern "C" Actor* cWeapon_GetStabTarget(Self* self, unsigned char* isSlash)
{
    WList& gobjs = D_004F78DC;
    WIt2 g = WBegin(gobjs);
    WIt2 end = WEnd(gobjs);
    V mLoc = self->actor->GetPos();
    float bestDistSquared = Sq(D_00489D90);
    Actor* bestHuman = 0;
    for (; g != end; ++g) {
        Actor* gobj = HGet(&*g);
        if (!gobj) continue;
        if (gobj == self->actor) continue;
        if (CtrlBusy(gobj)) continue;
        if (Downed(gobj)) continue;
        if (gobj->w4C != Team()) continue;
        V loc = gobj->GetPos();
        V diff = Sub(loc, mLoc);
        float distSquared = diff.x * diff.x + Sq(diff.y);
        if (distSquared < bestDistSquared) {
            if (Abs(diff.z) < D_00489D88) {
                E dir;
                GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(self->actor, gobj, &dir);
                if (Abs(dir.z) < D_00489D80) {
                    bestDistSquared = distSquared;
                    bestHuman = gobj;
                }
            }
        }
    }
    *isSlash = 0;
    if (bestHuman && !cHuman_IsInvulnerable(bestHuman)) {
        E dir;
        GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(bestHuman, self->actor, &dir);
        if (!(Abs(dir.z) <= D_00489D98)) {
            const V* src = bestHuman->mv ? &bestHuman->mv->vel : &Zero(); V velVec; V* d4 = &velVec; __int128 t4 = *(__int128*)src; *(__int128*)d4 = t4;
            float vel = Len(&velVec);
            if (vel < 1.0f)
                *isSlash = 1;
        }
    }
    return bestHuman;
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2 /* merge_units */
#undef cHuman_IsInvulnerable /* merge_units */
static inline void merge_flush_func_001414D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001414D0 */

/* merge_units: begin func_00141850 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } FObj;

/* Returns 3 if the float at +0x40 truncates to 0, else 0. */
int cGOBJ_GetHealthState(FObj* self)
{
    return (int)self->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141850 */

/* merge_units: begin func_00141870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141870 */

/* merge_units: begin func_00141880 */
#pragma push /* merge_units */
#pragma cplusplus on

static inline V Sub_00141880(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory");
    return r;
}
static inline void Normalize(V* v) {
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}
struct Query {
    struct WV { float x, y, z, w; } __attribute__((aligned(16))) v[3];
    char pad30[0x10];
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    char pad43[0x1D];
    int w60;
    int w64;
    int pad68[2];
    Query() { Query* s = this; WV* p = s->v; do { ++p; } while (p != s->v + 3); s->b40 = 0; s->b42 = 0; s->w60 = 0; s->w64 = 0; }
};
struct Hit { int w[4]; };
struct HV { char pad[0x4C]; float f4C; };
class Actor_00141880;
class Actor_00141880 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt(float dmg, Actor_00141880* src, int kind, int type, int* p, int a, int b);
    VPAD1(g)
    virtual unsigned char State();
    char pad04[0x48];
    int w4C;
    char pad50[8];
    Ctrl* ctrl;
};
struct Slot { int a; int b; int id; int c; };
struct Self_00141880 { Slot slots[8]; int pad80; unsigned char cur; char pad85[3]; Actor_00141880* actor; };
extern "C" {
extern char g_LosCheckService[];
extern unsigned char g_DoKnifeDmg;
}
extern "C" {
char* cWeaponDB_GetEntry(void* db, int id);
void* cSystemContainer_GetSystem(void* a, void* b);
int cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(void* mgr, Hit* a, Query* b, V* c, const V& d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k);
#if 0 /* merge_units */
int cHuman_IsInvulnerable(Actor_00141880* a);
#endif /* merge_units */
#define cHuman_IsInvulnerable(a0) (cHuman_IsInvulnerable((void *)(a0))) /* merge_units */

void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_AddScore(void* a, int b, int c);
void cHuman_Shock(Actor_00141880* a, int b, int c, float d, float e);
void Actor_Ignite(Actor_00141880* a, int b, Actor_00141880* c, int d, int e, float f);
void cHuman_BulletBlood(Actor_00141880* a, V* b, V* c, int d, HV* e);
}
static inline bool CtrlBusy_00141880(Actor_00141880* a) { bool r = false; if (a->ctrl && a->ctrl->Test()) r = true; return r; }
static inline bool Downed_00141880(Actor_00141880* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
extern "C" void Melee_ApplyHit(Self_00141880* self, Actor_00141880* target, int heavy)
{
    int extra;
    if (self->cur != 5) return;
    unsigned char* w = (unsigned char*)cWeaponDB_GetEntry(g_WeaponDatabase, ((Slot*)((char*)self + (self->cur << 4)))->id);
    unsigned char t = w[0xF0];
    if (t != 3 && t != 4 && t != 0xA) return;
    if (!g_DoKnifeDmg) return;
    if (CtrlBusy_00141880(target)) return;
    V from(self->actor->GetPos());
    V d(Sub_00141880(target->GetPos(), from));
    void* mgr = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
    Hit hit;
    Query q;
    if ((unsigned char)cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(mgr, &hit, &q, &from, d, 0, 0, 0, 0x58, 0, 0, 0)) return;
    int type = w[0xF0] == 4 ? 7 : 9;
    extra = *(int*)(w + 0xF8);
    if (w[0xF0] == 4) {
        if (Downed_00141880(target)) return;
        if (target->w4C != Team()) return;
        if (((unsigned char*)target)[0x346A]) return;
        if (CtrlBusy_00141880(self->actor) && ((unsigned char*)self->actor)[0x14] && !cHuman_IsInvulnerable(target))
            cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 6, 1);
        cHuman_Shock(target, 0, 1, 0.5f, 10000.0f);
        return;
    }
    if (w[0xF0] == 0xA) {
        if (Downed_00141880(target)) return;
        if (target->w4C != Team()) return;
        Actor_Ignite(target, 1, self->actor, 0, 0, -1.0f);
        return;
    }
    float dmg = (float)*(int*)(w + 0x64);
    int kind = 3;
    if (heavy) {
        dmg = 100000.0f;
        kind = 2;
    } else if (target->w4C == Team()) {
        HV hv;
        Normalize(&d);
        d.w = 1.0f;
        hv.f4C = 1.0f;
        cHuman_BulletBlood(target, &from, &d, 2, &hv);
    }
    target->Hurt(dmg, self->actor, kind, type, &extra, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141880(void) {}
#undef cHuman_IsInvulnerable /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00141880 */

/* merge_units: begin func_00141CD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class R_1CD0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1CD0 { void* vt; char pad[0x20]; int id; char pad28[8]; };
struct Slot_1CD0 { int pad0; int id; int pad8; int count; };
struct Own_1CD0 { char pad[0x58]; R_1CD0* recv; char pad5C[4]; char equip[4]; };
struct W_1CD0 { char pad[0x13C]; int slot; };
struct S_1CD0 { int pad0; Slot_1CD0 slots[8]; unsigned char cur; char pad85[3]; Own_1CD0* own; char pad8C[0x63]; unsigned char busy; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char g_OutOfAmmoMsgClass[];
extern char D_004D91E0[];
#if 0 /* merge_units */
W_1CD0* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((W_1CD0 *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */



void cMan_AddGun(void* eq, int a, int slot);
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Ev_1CD0* e, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(Ev_1CD0* e, void* target, int a);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(Ev_1CD0* e, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void cWeapon_SelectNext(S_1CD0* self, int a);
}
extern "C" void cWeapon_ReloadThrow(S_1CD0* self)
{
    self->busy = 0;
    if (self->cur == 4 || self->cur == 5) {
        Slot_1CD0* s = &self->slots[self->cur];
        unsigned char local;
        R_1CD0* r;
        if (s->count > 0) {
            cMan_AddGun(self->own->equip, 0, cWeaponDB_GetEntry(g_WeaponDatabase, s->id)->slot);
            return;
        }
        local = 0;
        r = self->own->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && !g_IsMultiplayer) {
            int id = s->id;
            Ev_1CD0 e;
            cMessage_ctor_cMessageNameR(&e, g_OutOfAmmoMsgClass);
            e.id = id;
            e.vt = D_004D91E0;
            QueueMessage_cMessageR_cSystemP_int(&e, self->own->recv, 0);
            e.vt = D_004D91E0;
            cMessage_dtor(&e, 0);
        }
        s->id = -1;
        cWeapon_SelectNext(self, 1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141CD0(void) {}
#undef cWeaponDB_GetEntry /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00141CD0 */

/* merge_units: begin func_00141E20 */
#pragma push /* merge_units */
/* cWeapon_Throw: spawn a projectile at the muzzle transform and launch it at the target or aim point */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V_00141E20 {
    float x, y, z, w;
    V_00141E20() {}
    V_00141E20(const V_00141E20& o) { const V_00141E20* s = &o; V_00141E20* d = this; register __int128 q; asm volatile { lq q, 0x0(s)
 sq q, 0x0(d) } }
} __attribute__((aligned(16)));
struct M {
    V_00141E20 r0, r1, r2, t;
    M() {}
};
static inline void Apply(V_00141E20* o, M* m, V_00141E20* v) { __asm__("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }

class Obj {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(d2)
    virtual V_00141E20 GetPos();
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
class Actor_00141E20 : public Obj {
public:
    char pad04[0x8];
    int id;
    char pad10[0x48];
    Ctl* ctl;
    char pad5C[4];
    char equip[4];
};
struct W { char pad[0xB8]; float fB8; char padBC[0x34]; unsigned char fF0; };
struct Slot_00141E20 { int a; int id; int b; int count; };
struct Self_00141E20 { int pad0; Slot_00141E20 slots[8]; unsigned char cur; char pad85[3]; Actor_00141E20* actor; char pad8C[0xD]; unsigned char b99; };
struct Proj;
extern "C" {
extern signed char D_0049D02C;
extern int g_NoneWord;
extern char D_004EE5C0[];
extern char D_004D92A0[];
extern char D_0049B1D0[];
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cSKM_GOBJ_GetSkeleton_void(Actor_00141E20* a);
M cSkeleton_GetBoneToWorldMatrix(void* skel, int code);
void cMan_RemoveGun(void* e, int z);
#if 0 /* merge_units */
W* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((W *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

void* cMemMan_Allocate(int pool, int size, char* file, int line);
Proj* cGrenade_ctor(void* p, Actor_00141E20* owner, M* m, W* w);
void cGrenade_SetInitialVelocity(Proj* p, V_00141E20* to, float k);
void cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(void* msg, int* sender, int action, float a, float b);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* to, int imm);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* msg, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

void cWeapon_AddShotStat(Self_00141E20* self, unsigned char b);
void cWeapon_Throw(Self_00141E20* self, int* id, V_00141E20* at, float k);
}
struct FireMsg {
    void* vt; char d[0x34];
    FireMsg(int* id, int act, float a, float b) { int* i = id; cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(this, i, act, a, b); }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FireMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); }
};
void cWeapon_Throw(Self_00141E20* self, int* id, V_00141E20* at, float k)
{
    Slot_00141E20* s = &self->slots[self->cur];
    Obj* tgt = nGobjManager_LookupGOBJ_cObjectIdR(id);
    W* w;
    Proj* p;
    Actor_00141E20* a = self->actor;
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
        V_00141E20 dst = *at;
        if (dst.w == 0.0f) {
            dst.w = 1.0f;
            M m = self->actor->GetMatrix();
            Apply(&dst, &m, &dst);
        }
        cGrenade_SetInitialVelocity(p, &dst, k);
    } else {
        V_00141E20 pos = tgt->GetPos();
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
#undef cWeaponDB_GetEntry /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
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
#if 0 /* merge_units */
extern void cWeapon_RemoveWeapon(INV* self, unsigned char slot, int a, int b, int c);
#endif /* merge_units */
void cWeapon_RemoveWeapon(void* self, unsigned char slot, int a, int b, int c); /* merge_units */
#define cWeapon_RemoveWeapon(a0, a1, a2, a3, a4) (cWeapon_RemoveWeapon((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

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
#undef cWeapon_RemoveWeapon /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142320 */

/* merge_units: begin func_001423E0 */
#pragma push /* merge_units */
typedef struct { int a0; int a4; int id; int ac; } S23E0;
extern void cWeapon_RemoveWeapon(void* self, unsigned char slot, int a, int b, int c);


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
#pragma pop /* merge_units */
/* merge_units: end func_001423E0 */
