/*
 * SFOGame/Source/grenade: 3 files, 0025D470-0025DA40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025D470 */
#pragma push /* merge_units */
#include "types.h"
static const float dat_0048AF60[2] = { 5.0f, 0.0f };
static const float dat_0048AF68[2] = { 100.0f, 0.0f };
float cGrenade_FigureThrowDist(float t) {
    if (t > 1.0f) t = 1.0f;
    return (*(float*)dat_0048AF60) + t * ((*(float*)dat_0048AF68) - (*(float*)dat_0048AF60));
}
static inline void merge_flush_func_0025D470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025D470 */

/* merge_units: begin func_0025D4B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#pragma inline_depth(8)
/* cGrenade_SetInitialVelocity: solve the ballistic launch velocity and clamp its speed to the projectile type's range */
struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V& Unit(V& v) { V* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return *p; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline V UnitOf(const V& a) { V t(a); V& r = Unit(t); return r; }
struct Type { char pad[0xF0]; unsigned char cls; char padF1[0x104 - 0xF1]; int range; };
struct Projectile { char pad[0x70]; V pos; char pad80[0xF0 - 0x80]; V launch; char pad100[0x120 - 0x100]; Type* rec; };
extern "C" {
extern float D_004F7FE0;
extern float g_ThrowGravity;
extern float D_0048AF98;
void nPhysics_CalculateInitialVelocityForTrajectory(V* out, const V* from, const V* to, V* extra, float g, float k, float minAng);
void cGrenade_SetInitialVelocity(Projectile* p, V* to, float k);
}
void cGrenade_SetInitialVelocity(Projectile* p, V* to, float k)
{
    bool lob = p->rec->cls == 1;
    float minAng;
    minAng = !lob ? -1000.0f : D_004F7FE0;
    float g = g_ThrowGravity;
    if (p->rec->cls == 7) g += D_0048AF98;
    V vel;
    V* from = &p->pos;
    nPhysics_CalculateInitialVelocityForTrajectory(&vel, from, to, 0, g, k, minAng);
    V* pa = &vel;
    int r = p->rec->range;
    int rr = r * r;
    if (!(LenSq(pa) <= (float)rr)) {
        vel = UnitOf(*pa);
        ScaleV(&vel, &vel, (float)p->rec->range);
    }
    float f;
    if (lob) f = 0.1f;
    else f = 0.9f;
    float m = (float)p->rec->range * f;
    float mm = m * m;
    pa = &vel;
    if (LenSq(pa) < mm) {
        vel = UnitOf(*pa);
        ScaleV(&vel, &vel, (float)p->rec->range * f);
    }
    p->launch = vel;
}

/* cGrenade_ctor: set up a projectile object at the launcher's matrix */
struct VC { float x, y, z, w; VC() {}
    // 128-bit lq/sq quadword copy idiom (copy ctor and assignment)
    VC(const VC& o) { VC* d = this; const VC* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); } VC& operator=(const VC& o) { VC* d = this; const VC* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); return *this; } } __attribute__((aligned(16)));
struct M4P { V r0, r1, r2; VC r3;
    M4P() {}
    // 128-bit lq/sq quadword copy idiom (64 bytes, two registers)
    M4P(const M4P& o) { const M4P* s = &o; M4P* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
// VU0 unit matrix (COP2/MMI), not expressible in C
static inline void UM(void* p0) { void* p = p0; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
struct PNodeC { virtual void v0(); virtual void SetMatrix(const M4P& m); };
struct PTypeC { char pad[0xC0]; float fuse; char padC4[0xF0 - 0xC4]; unsigned char cls; };
struct POwnerC { char pad[0xC]; int serial; };
struct ProjC {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int on);
    VPAD8(d) VPAD4(e)
    virtual void SetName(const char* n, int f);
    char pad4[0x2B];
    unsigned char b2F;
    char pad30[0x50 - 0x30];
    PNodeC* node;
    char pad54[0x60 - 0x54];
    char phys[0x10];
    V pos;
    V prev;
    V vel;
    V accel;
    V force;
    V torque;
    int xD0;
    char padD4[0xE0 - 0xD4];
    float fuse;
    unsigned char retired;
    unsigned char rest;
    unsigned char first;
    char padE7;
    unsigned char stuck;
    char padE9[7];
    int xF0, xF4, xF8, xFC;
    char pad100[4];
    int age;
    char pad108[8];
    float sx, sy, sz;
    char pad11C[4];
    PTypeC* rec;
    POwnerC* owner;
    int ownerId;
};
extern "C" {
extern float D_0048AF30;
extern float D_0048AF38;
extern float D_004F7FE8;
extern float D_0048AF40;
extern float D_0048AF90;
extern char D_004DC6C0[];
extern char g_IdentityMatrix[];
void nGobjManager_GetNextId(int* id, int kind);
void cGOBJ_ctor(void* self, int* gid, int n, int* tag);
V* cVector_ctor_float_float_float_float(V* out, float x, float y, float z, float w);
void cVector_ctor_cVectorR(V* d, V* s);
V* cVector_GetZero(void);
void cPointMass_SetMass(void* p, float m);
void nGobjManager_AddGOBJ(void* o);
ProjC* cGrenade_ctor(ProjC* self, POwnerC* owner, M4P* mtx, PTypeC* rec);
}
// 128-bit lq/sq quadword copy idiom
static inline void CpA(VC* d0, const VC* s0) { const VC* s = s0; VC* d = d0; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
ProjC* cGrenade_ctor(ProjC* self, POwnerC* owner, M4P* mtx, PTypeC* rec)
{
    int id;
    int tag;
    float mass;
    tag = 0;
    nGobjManager_GetNextId(&id, 245);
    cGOBJ_ctor(self, &id, 3, &tag);
    *(char**)self = D_004DC6C0;
    mass = D_0048AF30;
    cVector_ctor_cVectorR(&self->pos, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 1.0f));
    cVector_ctor_cVectorR(&self->prev, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 1.0f));
    cVector_ctor_cVectorR(&self->vel, cVector_GetZero());
    cVector_ctor_cVectorR(&self->accel, cVector_GetZero());
    cVector_ctor_cVectorR(&self->force, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 0.0f));
    cVector_ctor_cVectorR(&self->torque, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 0.0f));
    self->xD0 = 0;
    cPointMass_SetMass(self->phys, mass);
    self->xF0 = 0;
    self->xF4 = 0;
    self->xF8 = 0;
    self->xFC = 0;
    self->ownerId = -2;
    self->owner = 0;
    self->b2F = 1;
    {
        VC p;
        CpA(&p, &mtx->r3);
        M4P m = *mtx;
        if (rec->cls == 1) {
            self->sx = D_0048AF38;
            self->sy = D_004F7FE8;
            self->sz = D_0048AF40;
        } else {
            self->sx = self->sy = self->sz = 0.0f;
            UM(&m);
            m.r3 = p;
            if (rec->cls == 7) self->sz = D_0048AF90;
        }
        { VC t(p); *(VC*)&self->pos = t; }
        self->first = 1;
        self->owner = owner;
        {
            int none;
            self->ownerId = *(owner ? &owner->serial : (none = -1, &none));
        }
        self->SetName(g_IdentityMatrix, 0);
        self->node->SetMatrix(m);
        self->Activate(1);
        nGobjManager_AddGOBJ(self);
        self->retired = 0;
        self->rest = 0;
        self->rec = rec;
        self->fuse = rec->fuse;
        self->age = 0;
        self->stuck = 0;
    }
    return self;
}
static inline void merge_flush_func_0025D4B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025D4B0 */

/* merge_units: begin func_0025DA40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(cLList_cAreaEffectPtr_dtor, func_0025DAA0)
static inline void merge_flush_func_0025DA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025DA40 */
