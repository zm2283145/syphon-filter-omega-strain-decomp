/*
 * SFOGame/Source/weapon: 4 files, 00140EA0-00141240
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
extern W141240* cWeaponDB_GetEntry(void*, int);
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
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
int cHuman_IsInvulnerable(Actor* a);
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
static inline void merge_flush_func_001414D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001414D0 */
