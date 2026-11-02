/*
 * Libs/SFOLib/Source/particle: 2 files, 0039B3A0-0039B7B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0039B3A0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0039B3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039B3A0 */

/* merge_units: begin func_0039B7B0 */
#pragma push /* merge_units */
/* 0039B7B0 cParticleShatter::Render(float, unsigned int, float, float, float) (particle.cc).
 * k5's rs/n6.c (prototype DWARF rebuild) with symbol names fixed, the function-scope static colour's
 * guard/storage written on the extern objects, and the inline-depth changes marked below.
 * VU0 / quadword operations are inline asm (no C equivalent). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rotateloops off

struct V_0039B7B0 {
    float x, y, z, w;
    V_0039B7B0() {}
    V_0039B7B0* P() { return this; }
    V_0039B7B0(const V_0039B7B0* p, int) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(p), "r"(this) : "memory"); }
    V_0039B7B0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_0039B7B0(const V_0039B7B0& o) { void* xx = this; __int128 t; V_0039B7B0* dd = this; const V_0039B7B0* ps = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(ps), "r"(dd) : "memory"); }
    V_0039B7B0& operator=(const V_0039B7B0& o) { void* xx = this; V_0039B7B0* dd = this; const V_0039B7B0* ps = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(ps), "r"(dd) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct R { float f[12]; };
struct Mx;
extern "C" signed char D_0053BB28;
extern "C" V_0039B7B0 D_0053BB30;
extern "C" void cMatrix_SetWithAxisAngle(Mx* m, float a, float b, float c, float d);
struct Mx { R r; V_0039B7B0 t;
    Mx() {}
    Mx(float a, float b, float c, float d) { cMatrix_SetWithAxisAngle(this, a, b, c, d); }
    Mx(void* q);
    void SetRot(const Mx& rot) {
        r.f[0] = rot.r.f[0]; r.f[1] = rot.r.f[1]; r.f[2] = rot.r.f[2];
        r.f[4] = rot.r.f[4]; r.f[5] = rot.r.f[5]; r.f[6] = rot.r.f[6];
        r.f[8] = rot.r.f[8]; r.f[9] = rot.r.f[9]; r.f[10] = rot.r.f[10];
        r.f[3] = rot.r.f[3]; r.f[7] = rot.r.f[7]; r.f[11] = rot.r.f[11];
    }
} __attribute__((aligned(16)));

static inline void XformInPlace(V_0039B7B0* v, const Mx* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
static inline V_0039B7B0 Xform(const Mx& m, const V_0039B7B0& v) { V_0039B7B0 t = v; const V_0039B7B0* pt = &t; XformInPlace((V_0039B7B0*)pt, &m); return V_0039B7B0(pt, 0); }
/* operator+: `a` bound at the outer level, result/b inside a deeper helper (vreg creation order) */
static inline void AddS(V_0039B7B0* rp_, const V_0039B7B0* pa, const V_0039B7B0& b) { V_0039B7B0* rp = rp_; const V_0039B7B0* pb = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(pa), "r"(pb) : "memory"); }
static inline V_0039B7B0 AddQ(const V_0039B7B0& a, const V_0039B7B0& b) { const V_0039B7B0* pa = &a; V_0039B7B0 r; AddS(&r, pa, b); return r; }

struct Strip { char pad[0x80]; int idx[12]; char padB0[0x10]; };
struct Ent {
    char pad[0x24];
    Strip* strip;
    V_0039B7B0* pos;
    V_0039B7B0* c2C;
    V_0039B7B0* c30;
    V_0039B7B0* c34;
};
struct Rs {
    char pad[0xFB0];
    Ent ents[1];
};
struct Part {
    char pad0[0x10];
    V_0039B7B0 pos;
    char pad20[0x10];
    char q[0x10];
    V_0039B7B0 v[3];
    V_0039B7B0 uv[3];
    unsigned char dead;
    char padA1[0xF];
};
struct Desc {
    char pad0[0x38];
    int type;
    int n;
    float f40;
    float f44;
    float f48;
    char pad4C[4];
    float f50;
    float f54;
    int f58;
    char pad5C[8];
    unsigned char f64;
    char pad65[0xF];
    int f74;
    char pad78[8];
    char f80[0x30];
    long long fB0;
    long long fB8;
    long long fC0;
    long long fC8;
    long long fD0;
    long long fD8;
    char padE0[0x50];
    long long f130;
    char pad138[0x900 - 0x138];
    V_0039B7B0 f900[9];
    char pad990[0x920 - 0x990 + 0x90];
};
struct Obj_0039B7B0 {
    char pad0[0x64];
    float f64;
    char pad68[4];
    int n6C;
    int f70;
    char pad74[0x90 - 0x74];
    V_0039B7B0 f90[6];
    char padF0[0];
};
#define OF_(p, o, T) (*(T*)((char*)(p) + (o)))

extern "C" {
typedef struct G {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern long long D_004BC1B0[];
extern int* D_005381C8;

static inline unsigned int Unpack(unsigned int a, unsigned int n) { return (0x6C000000 | ((n) << 16) | (a)); }
static inline void QCopy(const void* s, void* d, int n)
{
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void QCopy1(void* d, int n, const void* s)
{
    __int128 t;
    const void* ss = s;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu d, d, 0x10
        addi n, n, -1
        addiu ss, ss, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void Vif_Put(unsigned int v)
{
    int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = v;
}
static inline void Vif_PutV(unsigned int v)
{
    unsigned int x = v;
    int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = x;
}
static inline void Vif_PadTo(unsigned int m)
{
    while (((unsigned int)D_005381C8 & 0xF) != m) {
        Vif_Put(0);
    }
}
extern char D_00537F80[];
extern char D_00538080[];
extern char D_0053B6A0[];
#if 0 /* merge_units */
extern unsigned char D_0053B540;
#endif /* merge_units */
#define D_0053B540 (*(unsigned char*)&D_0053B540) /* merge_units */

void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void XLib_DrawStrip(void* s);
void cVector_opAssign(V_0039B7B0* d, const V_0039B7B0* s);
void tIRGBA_opAssign_tRGBAR(V_0039B7B0* d, const V_0039B7B0* s);
float tVifFloatToInt_short_4_Bias(void);
V_0039B7B0* cVector_ctor_float_float_float_float(V_0039B7B0* o, float x, float y, float z, float w);
int Libc_Rand(void);
float cAxisAngle_X(void* q);
float cAxisAngle_Y(void* q);
float cAxisAngle_Z(void* q);
float cAxisAngle_Angle(void* q);
inline Mx::Mx(void* q) { float a = cAxisAngle_X(q); float b = cAxisAngle_Y(q); float c = cAxisAngle_Z(q); float d = cAxisAngle_Angle(q); cMatrix_SetWithAxisAngle(this, a, b, c, d); }

float Libc_Powf(float a, float b);
int* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void* p, int a, int b, int c, int d);
void cDmaMan_EndChain_int_ulongP(void* p, int a, void* q);
void* XLib_GetTexMan(void* s);
int cTexMan_GetHalTexture(void* a, int b);
long long* cTexture_GetTEX1_1(int a);
long long* cTexture_GetTEX0_1(int a);
void MEMCPY16(void* d, void* s, int n);
V_0039B7B0* cRandomVector_Vector(void* t, int i);
int cVU1Man_GetMSCAL(void* t, int i);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)
#define RS ((Rs*)g_Video)

static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Flush(void)
{
    Ent* e;
    D_00539238 = Prim();
    D_0053923C = Mode();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}
static inline V_0039B7B0* UVT1(float u, const V_0039B7B0& uv) { V_0039B7B0 tmp; return cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w); }
static inline V_0039B7B0* UVT0(float u, const V_0039B7B0& uv) { return UVT1(u, uv); }
static inline V_0039B7B0* UVT(float u, const V_0039B7B0& uv) { return UVT0(u, uv); }
static inline V_0039B7B0 operator+(const V_0039B7B0& a, const V_0039B7B0& b) {  return AddQ(a, b); }
static inline void Emit(const V_0039B7B0& pos, const V_0039B7B0& col, const V_0039B7B0& uv)
{
    Ent* e;
    float u;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    u = uv.x + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], UVT(u, uv));
    D_005381F8 = 6LL << 32;
}
static inline void EndStrip(void)
{
    if (D_00539220 > 0 && D_00539230 > 0) {
        int n = D_00539220 - 1;
        if (D_00539234 < 12) {
            Ent* e = &RS->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->strip[n].idx[D_00539234] = v;
            D_00539234++;
        } else {

            if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
            { int v; int j; Strip* s; v = D_00539238 - 1; s = ((Strip**)(g_Video + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->idx[j] = v; }
            D_00539230 = 0;
            D_00539234 = 0;
            D_00539228++;
            D_00539220++;
        }
    }
}
#define DRAW(m, e, col) { \
    m.SetRot(Mx(e->q)); \
    SetT4(m, e->pos); \
    Emit(Xform(m, e->v[0]) + e->pos, col, e->uv[0]); \
    Emit(Xform(m, e->v[1]) + e->pos, col, e->uv[1]); \
    Emit(Xform(m, e->v[2]) + e->pos, col, e->uv[2]); }
/* m.t = e->pos goes through four pass-through inline levels: MW creates the assignment's address
   registers after Xform's copy (inline expansion is breadth-first by depth), giving retail's colours */
static inline void SetT1(Mx& m, const V_0039B7B0& p) { m.t = p; }
static inline void SetT2(Mx& m, const V_0039B7B0& p) { SetT1(m, p); }
static inline void SetT3(Mx& m, const V_0039B7B0& p) { SetT2(m, p); }
static inline void SetT4(Mx& m, const V_0039B7B0& p) { SetT3(m, p); }
static inline int RandI(int lo, int hi)
{
    float m = 2147483648.0f;
    return (int)((float)lo + (float)(hi - lo) * ((float)Libc_Rand() / (1.0f + m)));
}

extern "C" void cParticleShatter_Render(Obj_0039B7B0* o, float t, float a, float b, float c)
{
    if (OF_(o, 0x170, int) >= 0) {
        int sel;
        int cnt;
        int i;
        Mx m;
        cTexMan_SetActive(g_TextureMgr, OF_(o, 0x170, int));
        { int mn = OF_(o, 0x160, int) >= OF_(o, 0x168, int) ? OF_(o, 0x168, int) : OF_(o, 0x160, int); }
        g_DrawMode = 5;
        D_005392D8 = D_004BC1B0[OF_(o, 0x120, Desc*)->type];
        /* function-scope `static cVector col(1,1,1,1)`: its guard byte and storage are linked as data, so the
           compiler's one-time initialisation is written out on the extern objects */
        if (D_0053BB28 == 0) { float f = 1.0f; D_0053BB28 = 1; D_0053BB30.x = f; D_0053BB30.y = f; D_0053BB30.z = f; D_0053BB30.w = f; }
        sel = RandI(0, OF_(o, 0x15C, int) - 1);
        cnt = 0;
        Flush();
        for (i = 0; i < OF_(o, 0x15C, int); i++) {
            Part* e = OF_(o, 0x124, Part*) + i;
            if (e->dead == 0 && i != sel) {
                DRAW(m, e, D_0053BB30)
                cnt++;
                EndStrip();
            }
        }
        if (cnt > 0) {
            XLib_DrawStrip(g_Video);
            Flush();
        }
        {
        Part* e = OF_(o, 0x124, Part*) + sel;
        if (e->dead == 0) {
            D_005392D8 = D_004BC1B0[1];
            DRAW(m, e, D_0053BB30)
            XLib_DrawStrip(g_Video);
        }
        }
        return;
    }
    if (o->n6C > 0) {
        float s, ds;
        float y = 0.0f;
        float z = y;
        float x;
        int i;
        Desc* d = OF_(o, 0x120, Desc*);
        x = t - o->f64;
        if (d->n > 0) {
            s = 30.0f * (x + (float)d->n * d->f40);
            ds = 30.0f * d->f40;
        } else {
            ds = y;
            s = 30.0f * x;
        }
        OF_(o, 0xAC, float) = a;
        OF_(o, 0xBC, float) = b;
        if (D_0053B540 == 0 || OF_(o, 0x120, Desc*)->f58 == 0) {
            OF_(OF_(o, 0x120, Desc*), 0x98C, float) = OF_(o, 0x120, Desc*)->f50 * c;
        } else {
            OF_(OF_(o, 0x120, Desc*), 0x98C, float) = OF_(o, 0x120, Desc*)->f54 * c;
        }
        for (i = 0; i < OF_(o, 0x120, Desc*)->n + 1; i++) {
            float r = Libc_Powf(s, OF_(OF_(o, 0x120, Desc*), 0x9A8, float));
            float rm = r * OF_(OF_(o, 0x120, Desc*), 0x9AC, float);
            OF_(o, 0xC0, V_0039B7B0) = V_0039B7B0(x, s, y, z);
            OF_(OF_(o, 0x120, Desc*), 0x920, float) = r;
            OF_(OF_(o, 0x120, Desc*), 0x930, float) = rm;
            D_005381C8 = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 0);
            Vif_PutV(0x11000000);
            Vif_Put(0);
            Vif_PadTo(0xC);
            Vif_Put(Unpack(0xF, 6));
            QCopy1(D_005381C8, 6, (char*)o + 0x90);
            D_005381C8 += 0x18;
            {
                char* sp2 = (char*)OF_(o, 0x120, Desc*) + 0x900;
                Vif_PadTo(0xC);
                Vif_Put(Unpack(0x15, 9));
                QCopy(sp2, D_005381C8, 9);
            }
            D_005381C8 += 0x24;
            Vif_PadTo(0);
            cDmaMan_EndChain_int_ulongP(D_00537F80, 1, D_005381C8);
            {
                Desc* p = OF_(o, 0x120, Desc*);
                int base = o->f70;
                int left;
                int max;
                long long* pk;
                s -= ds;
                left = o->n6C;
                y += p->f44;
                z += p->f48;
                p->fB0 = *cTexture_GetTEX1_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), p->f74));
                p->fC0 = *cTexture_GetTEX0_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), p->f74));
                max = 0x21;
                if (p->f64) {
                    p->fB8 = 0x15;
                    max = 0xE;
                    p->fC8 = 7;
                    p->fD0 = 1 | (0x612F4000LL << 32);
                    p->fD8 = 1 | (0x602F4000LL << 32);
                }
                pk = (long long*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 1);
                *pk = 0;
                pk++;
                while (left > 0) {
                    int n = left < max ? left : max;
                    p->f130 = (long long)n | (0x8000 | (0x602F4000LL << 32));
                    *pk = 0;
                    pk++;
                    *pk = 0x6C0D8000LL << 32;
                    pk++;
                    MEMCPY16(pk, p->f80, 12);
                    pk += 0x18;
                    *(V_0039B7B0*)pk = *cRandomVector_Vector(D_0053B6A0, base + left);
                    pk += 2;
                    *pk = (unsigned int)cVU1Man_GetMSCAL(D_00538080, 0x17);
                    pk++;
                    left -= n;
                    *pk = 0;
                    pk++;
                }
                cDmaMan_EndChain_int_ulongP(D_00537F80, 1, pk);
            }
        }
    }
}
#undef D_0053B540 /* merge_units */
static inline void merge_flush_func_0039B7B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039B7B0 */
