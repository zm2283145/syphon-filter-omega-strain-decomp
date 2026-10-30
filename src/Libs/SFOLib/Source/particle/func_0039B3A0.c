#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"

struct W { int x, y, z, w; W() {} W(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; } W& operator=(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    void Set2(const V& o) { __int128 t; __asm__("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o)); }
    void Set(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct M {
    V r0, r1, r2, r3;
    M() {}
    void SetB(const M& o) { __int128 qa; __int128 qb; const M* s = &o; M* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    void SetX(const M& o) { void* xx = this; __int128 qa; __int128 qb; const M* s = &o; M* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M& TrP() { M* p = this; float f; f = p->r0.y; p->r0.y = p->r1.x; p->r1.x = f; f = p->r0.z; p->r0.z = p->r2.x; p->r2.x = f; f = p->r1.z; p->r1.z = p->r2.y; p->r2.y = f; return *p; }
    M& TrT() { float f; f = r0.y; r0.y = r1.x; r1.x = f; f = r0.z; r0.z = r2.x; r2.x = f; f = r1.z; r1.z = r2.y; r2.y = f; return *this; }
    M& operator=(const M& o) { void* xx = this; __int128 qa; __int128 qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { __int128 qa; __int128 qb; const M* s = &o; M* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

/* VU0 4x4 matrix multiply, in place into d */
static inline void MulM(M* d, const M* a)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "lqc2 $vf8, 0x0(%0); lqc2 $vf9, 0x10(%0); lqc2 $vf10, 0x20(%0); lqc2 $vf11, 0x30(%0)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(a) : "memory");
}
static inline M& MulInto(M* t, const M* a) { M* p = t; MulM(p, a); return *p; }

/* VU0 3x3 rotate of a vector by a matrix */
static inline void Rot(V* o, const V* v, const M* m)
{
    __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}

struct Elem {
    char pad0[0x14];
    float x14;
    char pad18[0xE0 - 0x18];
};
struct Def {
    char pad0[0x14];
    float x14;
    char pad18[0x64 - 0x18];
    unsigned char x64;
    char pad65[0x180 - 0x65];
    int count;              /* 0x180 */
    char pad184[0x190 - 0x184];
    Elem elems[8];          /* 0x190 */
    char pad890[0x8B0 - 0x890];
    M m;               /* 0x8B0 */
    char pad8F0[0x9B0 - 0x8F0];
    float f9B0, f9B4, f9B8, f9BC;
};
struct Obj {
    void* vt;
    char pad4[0x8];
    unsigned char xC;
    char padD[3];
    M m;               /* 0x10 */
    V v50;             /* 0x50 */
    float x60;
    char pad64[0x90 - 0x64];
    V a[6];            /* 0x90 */
    V xF0;             /* 0xF0 */
    Def* def;          /* 0x100 */
    int owner;         /* 0x104 */
    int pieceBlockPtr; /* 0x108 */
    char pad10C[0x12C - 0x10C];
    int floorCollisionChildId; /* 0x12C */
};
#define V40(s) (*(V*)((char*)(s) + 0x40))
#define V10(s) (*(V*)((char*)(s) + 0x10))

extern "C" Obj* cParticleBase_ctor(Obj* self, Obj* parent, Def* def, float f);
extern void* const D_004DFAF0[];
extern "C" int GetEffectID__15cParticleSystemCFRC1(void* sys, Elem* e);
extern char D_0053B540;
extern W D_00538350;
extern V D_004BC550;

static inline void Compose3(Obj* self, Obj* parent, M* m, M& r)
{
    M* pm;
    M t = *m;
    const M* pa = &parent->m;
    M& rr = (r = MulInto(&t, pa));
    void* xx = &self->m;
    pm = &self->m;
    *pm = rr;
}
static inline void Compose2(Obj* self, Obj* parent, M* m, M& r) { Compose3(self, parent, m, r); }
static inline void Compose(Obj* self, Obj* parent, M* m, M& r) { Compose2(self, parent, m, r); }

static inline M& Transpose(M& a)
{
    M* p = &a;
    float f;
    f = p->r0.y; p->r0.y = p->r1.x; p->r1.x = f;
    f = p->r0.z; p->r0.z = p->r2.x; p->r2.x = f;
    f = p->r1.z; p->r1.z = p->r2.y; p->r2.y = f;
    return *p;
}
static inline V& RotBy(M b, V& v) { Rot(&v, &v, &b); return v; }
static inline M Transposed(const M* m) { M a; a.SetX(*m); return Transpose(a); }
static inline V& RotT3(V& v, const M* m) { return RotBy(Transposed(m), v); }

extern "C" Obj* cParticleBox_ctor(Obj* self, Obj* parent, Def* def, M* m, float st)
{
    M r;
    W c;

    cParticleBase_ctor(self, parent, def, st);
    self->vt = (void*)D_004DFAF0;
    {
        V* q = self->a;
        V* e = self->a + 6;
        do { q++; } while (q != e);
    }
    self->def = def;
    if (!parent) {
        self->m = def->m;
        self->a[2] = V10(m);
    } else {
        Compose3(self, parent, m, r);
        self->a[2].Set(parent->a[2]);
        float w = self->a[5].w; self->a[5].Set(parent->a[5]); self->a[5].w = w;
    }
    self->a[0] = V40(self);
    self->a[0].w = def->x14;
    c = D_00538350;
    *(W*)&self->a[1] = c;
    self->a[4].Set(D_004BC550);
    self->a[4] = RotT3(self->a[4], m);
    self->a[4].w = (float)def->x64;
    self->x60 = def->f9BC + (def->f9B8 + (def->f9B0 + def->f9B4));
    self->owner = 0;
    self->floorCollisionChildId = -1;
    for (int i = 0; i < def->count; i++) {
        float triggerFrame = def->elems[i].x14;
        if (triggerFrame < 0.0f) {
            self->floorCollisionChildId = GetEffectID__15cParticleSystemCFRC1(&D_0053B540, &def->elems[i]);
        }
    }
    self->pieceBlockPtr = 0;
    return self;
}