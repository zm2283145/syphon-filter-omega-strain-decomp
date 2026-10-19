#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

struct V;
extern "C" {
void* Ptr_Identity(void*);
V* Vec4_Assign(V* d, const V* s);
V Vec4_Add(const V& a, const V& b);
V Vec4_Scale(const V& a, float s);
void Vec4_Scale_1E5920(V* d, const V* s, float k);
void Vec4_Subtract(V* d, const V* a, const V* b);
void Vec4_Sub(V* d, const V* a, const V* b);
V* Vec4_NormalizeXYZ_1D10C0(V* v, float* len);
V* Vec4_NormalizeXYZInPlace(V* v);
void Vec4_NormalizeXYZ_132060(V* d, const V* s);
void Vec4_Cross(V* d, const V* a, const V* b);
int Vec4_IsZeroXYZ(const V* v);
V Sphere_FromCenter(const V& c, const V& r);
void Vec4_CrossW0(V* d, const V* a, const V* b);
void* Vec4_Set(void*, float, float, float, float);
void Mtx_FromRowsAndTranslation(void* m, const V* a, const V* b, const V* c, void* t);
void Mtx_FrameFromAxis(void* m, const V* a);
void Mtx_SetIdentity(void* m);
V* Mtx_DotRowsVec3(void* m, void* v);
void* ParticleDefs_FindByName(void* a, void* b);
void ParticleEmitter_SpawnChildren(void* a, void* b, void* c, void* m, float t);
void ParticleEmitterBase_Update(void* o, void* a, void* b, void* c, float t);
void func_00136DA0(void*);
void func_0012F530(void*, int);
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
extern char D_004BC5D0[];
extern char D_0053BB08;
extern float D_0053BB10[4];
extern int D_005383C8;
extern V D_004BC550;
extern int D_0053BB20;
extern char D_0053B540[];
}

struct W;
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { Vec4_Assign(this, &o); }
    V& operator=(const V& o) { const V* s0 = &o; V* d = this; void* xx = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    void A2(const V& o) { const V* s0 = &o; const V* s = &o; void* xx = this; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void A3(const V& o) { const V* s = &o; const V* s0 = &o; V* d = this; void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void A4(const V& o) { const V* s = &o; const V* s0 = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); void* xx = this; V* d = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    void A5(const V& o) { const V* s = &o; const V* s0 = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); V* d = this; void* xx = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    void A6(const V& o) { __int128 t; const V* s0 = &o; V* d = this; void* xx = this; const V* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void A7(const V& o) { const V* s0 = &o; V* d = this; void* xx = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    void A9(const V& o) { const V* s = &o; const V* s0 = &o; __int128 q = *(const __int128*)s; void* xx = this; V* d = this; *(__int128*)d = q; }
    void AE(const V& o) { __int128 t; V* d = this; void* xx = this; const V* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void AC(const V& o) { __int128 t; V* d = this; void* xx = this; const V* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void AF(const V& o) { const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); V* d = this; void* xx = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    void AG(const V& o) { const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); void* xx = this; V* d = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    void AH(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void AI(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    void AP(const void* p) { V* d = this; const V* s = (const V*)p; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    V(const V& o, int) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    void Set(const V& o) { void* xx = this; const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    inline W operator-() const;
    void Set3(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    V& operator*=(float s) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(this), "f"(s) : "memory"); return *this; }
    float Len() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    float Dot(const V& b) const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory"); return r; }
} __attribute__((aligned(16)));

struct U {
    float a, b, c, d;
    U() {}
    U(float x, float y, float z, float w) { a = x; b = y; c = z; d = w; }
    void Set4(float x, float y, float z, float w) { a = x; b = y; c = z; d = w; }
    void SetW(const W& v);
    void SetU(const U& o) { a = o.a; b = o.b; c = o.c; d = o.d; }
};

static inline V SubP(const V& a, const V& b) { V r; const V* p = &a; Ptr_Identity(&r); Vec4_Subtract(&r, p, &b); return r; }
static inline V Sub(const V& a, const V& b) { V r; Ptr_Identity(&r); Vec4_Subtract(&r, &a, &b); return r; }
static inline V Sub2(const V& a, const V& b) { V r; Ptr_Identity(&r); Vec4_Sub(&r, &a, &b); return r; }
static inline V Mul(const V& a, float k) { V r; Ptr_Identity(&r); Vec4_Scale_1E5920(&r, &a, k); return r; }
static inline V MulP_(const V& a, float k) { V r; const V* p = &a; Ptr_Identity(&r); Vec4_Scale_1E5920(&r, p, k); return r; }
struct N { float x, y, z, w; N(const V& a) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(&a), "r"(this) : "memory"); } } __attribute__((aligned(16)));
struct W { float x, y, z, w; W() {} void FromN(const N& o) { __int128 t; W* d = this; void* xx = this; const N* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); } W(const N& o) { __int128 t; W* d = this; void* xx = this; const N* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); } W(const V& a, int) { __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&a) : "memory"); } } __attribute__((aligned(16)));
inline W V::operator-() const { return W(N(*this)); }
static inline U ToU(const W& v) { return U(v.x, v.y, v.z, 0.0f); }
static inline W Neg(const V& a) { return W(a, 0); }
static inline void ToUTo(U* d, const W& v) { *d = U(v.x, v.y, v.z, 0.0f); }
static inline void ToUTo2(U* d, const V& f) { ToUTo(d, N(f)); }
inline void U::SetW(const W& v) { a = v.x; b = v.y; c = v.z; d = 0.0f; }
inline void* operator new(unsigned int, void* p) { return p; }
static inline void Fin(U* d, const U& u_, const W& w_, const V& f) { const_cast<W&>(w_).FromN(N(f)); const_cast<U&>(u_).SetW(w_); *d = u_; }
static inline void Fin2(U* d, const U& u_, const W& w_, const V& f) { W* w = (W*)&w_; U* u = (U*)&u_; *w = N(f); *u = U(w->x, w->y, w->z, 0.0f); *d = *u; }
static inline void ToUTo3(U* d, const V& f) { W w = N(f); *d = U(w.x, w.y, w.z, 0.0f); }
static inline V F3EEF0(const V& a, const V& b) { V r; Ptr_Identity(&r); Vec4_CrossW0(&r, &a, &b); return r; }
static inline V Normalized_(const V& a) { const V* p = &a; V v; return *Vec4_NormalizeXYZInPlace(Vec4_Assign(&v, p)); }
static inline V NormalizedLen_(const V& a, float* len) { V v; return *Vec4_NormalizeXYZ_1D10C0(Vec4_Assign(&v, &a), len); }
static inline float Sqrt(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }
static inline float SqrtI(float x) { float r = 0.0f; asm { sqrt.s x, x } return x; }
static inline float SqrtG(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float SqrtJ(float x) { float r = 0.0f; r = x; asm { sqrt.s r, r } return r; }

#pragma define_section G_DTOR ".dtors_drop" far_absolute RX
struct G {
    char pad[4];
    G() { func_00136DA0(this); }
    /* out-of-line copy is weak and dropped at link (merged into func_0012F530 in retail) */
    __declspec(weak) __declspec(G_DTOR) ~G() { func_0012F530(this, -1); }
};
static inline void* Alloc(int size, int line) { G g; return Mem_Alloc(0, size, D_004BC5D0, line); }
static inline void Free(void* p, int line) { G g; Mem_Free(0, p, D_004BC5D0, line); }

static inline bool Eq(const V& a, const V& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
static inline void Ident(V* m) { void* xx = m; __int128 t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $0; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $0; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void FrameFrom_(V* m, const V& up, const V& n)
{
    V c;
    Vec4_Cross(&c, &up, &n);
    if (!Vec4_IsZeroXYZ(&c)) {
        V a;
        Vec4_NormalizeXYZ_132060(&a, &up);
        V b(*Vec4_NormalizeXYZInPlace(&c));
        V d;
        V tr;
        Vec4_Cross(&d, &b, &a);
        Mtx_FromRowsAndTranslation(m, &b, &a, &d, Vec4_Set(&tr, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!Vec4_IsZeroXYZ(&up)) {
        Mtx_FrameFromAxis(m, &up);
    } else {
        Mtx_SetIdentity(m);
    }
}
static inline void FrameFrom(V* m, const V& up, const V& n) { FrameFrom_(m, up, n); }
static inline V MulP(const V& a, float k) { return MulP_(a, k); }
static inline V MulW(const V& a, float k) { return Mul(a, k); }
static inline V Normalized(const V& a) { return Normalized_(a); }
static inline V NormalizedLen(const V& a, float* len) { return NormalizedLen_(a, len); }
static inline V MulW2(const V& a, float k) { return MulW(a, k); }
struct Vtx9C { V p; U uv; };
struct Tri9C {
    float f0, f4;
    char pad8[8];
    V c;
    V vel;
    U n;
    V d[3];
    U uv[3];
    unsigned char dead;
    char padA1[0xF];
};
struct Emit9C { char pad[0x190]; char x190[0x14]; float f1A4; };
struct EmitE0 { char x0[0x14]; float f14; char pad[0xE0 - 0x18]; };
struct Desc9C {
    char pad0[0x68];
    float f68;
    char pad6C[0x180 - 0x6C];
    int nEmit;
    char pad184[0x190 - 0x184];
    EmitE0 em[8];
    char pad890[0x8F4 - 0x890];
    int b8F4;
    char pad8F8[0x998 - 0x8F8];
    float f998, f99C, f9A0, f9A4, f9A8, f9AC;
};
struct Ctx9C { char pad[0x30]; V v30; char pad40[0x28]; unsigned char b68; };
struct Obj9C {
    char pad0[0xC];
    unsigned char bC;
    char padD[0x40 - 0xD];
    V v40;
    char pad50[0x10];
    float f60;
    float f64;
    char pad68[0x84 - 0x68];
    unsigned char b84;
    char pad85[0x90 - 0x85];
    V v90;
    char padA0[0x10];
    V vB0;
    char padC0[0x20];
    V size;
    char padF0[0x10];
    V v100;
    V v110;
    Desc9C* desc;
    Tri9C* tris;
    char pad128[8];
    V min;
    V max;
    char pad150[4];
    float f154;
    int nV;
    int nT;
    int nx, ny, nz;
    unsigned char b16C;
    char pad16D[3];
    int i170;
};
struct Rnd9C { int i; float t[260]; };
extern "C" Rnd9C D_0053B6A0;
static inline V& Rnd9CV() { return *(V*)&D_0053B6A0.t[++D_0053B6A0.i & 0xFF]; }

static inline V Sc(const V& a, float k) { return Vec4_Scale(a, k); }
static inline V Sc2(const V& a, float k) { const V* p = &a; return Vec4_Scale(*p, k); }
static inline Emit9C& Em(Desc9C* d, int e) { return *(Emit9C*)((char*)d + e * 0xE0); }
#define EMIT(DST) o->desc->em[DST]

#define TRI(IDX, A, B, C)                                    \
    ctr.A6(Sc2(Vec4_Add(Vec4_Add(A->p, B->p), C->p), 0.33333334f)); \
    { t = &o->tris[IDX];                                \
    t->d[0].A6(Sub(A->p, ctr)); t->uv[0] = A->uv;              \
    t->d[1].A6(Sub(B->p, ctr)); t->uv[1] = B->uv;              \
    t->d[2].A6(Sub(C->p, ctr)); t->uv[2] = C->uv;              \
    t->c.AC(ctr); }

static inline void InitK(V* p, float a, float b, float c, float d) { p->x = a; p->y = b; p->z = c; p->w = d; }
extern "C" void ShatterEmitter_Update(Obj9C* o, float dt, Ctx9C* ctx, Ctx9C* a2, void* a3);
void ShatterEmitter_Update(Obj9C* o, float dt, Ctx9C* ctx, Ctx9C* a2, void* a3)
{
    o->b16C = 1;
    if (!o->b84) {
        o->b16C = 0;
        if (o->i170 >= 0) {
            Vtx9C** v;
            int nx, hx, hy, i, j;
            float k28, k27;
            o->nx = 4;
            o->ny = 4;
            o->nz = 4;
            V center(MulP(Vec4_Add(o->min, o->max), 0.5f));
            V size;
            hy = (o->ny + 1) >> 1;
            size.Set(o->size);
            if (!(size.x < size.y)) {
                nx = o->nx;
                hx = (nx + 1) >> 1;
                k28 = (center.x - o->min.x) / size.x;
            } else {
                nx = o->nz;
                hx = (nx + 1) >> 1;
                k28 = (center.y - o->min.y) / size.y;
            }
            o->nV = (nx + 1) * (o->ny + 1);
            o->nT = nx * o->ny * 2;
            o->tris = (Tri9C*)Alloc(o->nT * sizeof(Tri9C), 0xA64);
            v = (Vtx9C**)Alloc(o->nV * 4, 0xA6B);
            for (i = 0; i < o->nV; i++) {
                v[i] = (Vtx9C*)Alloc(0x20, 0xA6E);
            }
            k27 = (center.z - o->min.z) / size.z;
            for (i = 0; i <= hx; i++) {
                float u0, u1, x0, x1, y0, y1, si;
                unsigned char mid = 0;
                if (i == 0) {
                    x0 = o->min.x;
                    x1 = o->max.x;
                    y0 = o->min.y;
                    y1 = o->max.y;
                    u0 = 0.0f;
                    u1 = 1.0f;
                } else if (i == hx) {
                    x0 = center.x;
                    y0 = center.y;
                    u0 = k28;
                    u1 = k28;
                    x1 = x0;
                    y1 = y0;
                } else {
                    mid = 1;
                    si = Sqrt((float)i / (float)hx);
                }
                for (j = 0; j <= hy; j++) {
                    int r0 = j * (nx + 1);
                    int r1 = (nx + 1) * (o->ny - j);
                    float w1, w0, z1, z0;
                    if (!D_0053BB08) {
                        InitK((V*)D_0053BB10, 0.75f, 0.75f, 0.75f, 0.75f);
                        D_0053BB08 = 1;
                    }
                    V r;
                    r = Rnd9CV();
                    r = Sub2(*(V*)D_0053BB10, Vec4_Scale(r, 0.5f));
                    if (j == 0) {
                        z1 = o->min.z;
                        z0 = o->max.z;
                        w1 = 0.0f;
                        w0 = 1.0f;
                        r.z = 1.0f;
                        r.w = 1.0f;
                    } else if (j == hy) {
                        z1 = center.z;
                        w1 = k27;
                        r.z = 1.0f;
                        w0 = k27;
                        r.w = 1.0f;
                        z0 = z1;
                    } else {
                        float sj = SqrtG((float)j / (float)hy);
                        w1 = k27 * (sj * r.z);
                        w0 = 1.0f - (1.0f - k27) * (sj * r.w);
                        z1 = o->min.z + size.z * w1;
                        z0 = o->min.z + size.z * w0;
                    }
                    if (mid) {
                        u0 = k28 * (si * r.x);
                        u1 = 1.0f - (1.0f - k28) * (si * r.y);
                        x0 = o->min.x + size.x * u0;
                        x1 = o->min.x + size.x * u1;
                        y0 = o->min.y + size.y * u0;
                        y1 = o->min.y + size.y * u1;
                    }
                    v[r0 + i]->p.Set(V(x0, y0, z0, 1.0f));
                    v[r0 + i]->uv = U(u0, w0, 1.0f, 0.0f);
                    v[r1 + nx - i]->p.Set(V(x1, y1, z1, 1.0f));
                    v[r1 + nx - i]->uv = U(u1, w1, 1.0f, 0.0f);
                    if (i < hx) {
                        v[r0 + nx - i]->p.Set(V(x1, y1, z0, 1.0f));
                        v[r0 + nx - i]->uv = U(u1, w0, 1.0f, 0.0f);
                        v[r1 + i]->p.Set(V(x0, y0, z1, 1.0f));
                        v[r1 + i]->uv = U(u0, w1, 1.0f, 0.0f);
                    }
                }
            }
            {
                int row, col;
                V ctr;
                for (row = 0; row < hy; row++) {
                    for (col = 0; col < hx; col++) {
                        Tri9C* t;
                        int i0 = col + row * (nx + 1);
                        int i1 = i0 + hy * (nx + 1);
                        int q = col + row * nx;
                        int t0 = q * 2;
                        int t1 = t0 + hy * nx * 2;
                        TRI(t0, v[i0], v[i0 + nx + 1], v[i0 + nx + 2]);
                        TRI(t0 + 1, v[i0], v[i0 + 1], v[i0 + nx + 2]);
                        TRI(t0 + hx * 2, v[i0 + hx], v[i0 + 1 + hx], v[hx + (i0 + nx + 1)]);
                        TRI(t0 + hx * 2 + 1, v[i0 + 1 + hx], v[hx + (i0 + nx + 2)], v[hx + (i0 + nx + 1)]);
                        TRI(t1, v[i1], v[i1 + 1], v[i1 + nx + 1]);
                        TRI(t1 + 1, v[i1 + 1], v[i1 + 1 + nx], v[i1 + nx + 2]);
                        TRI(t1 + hx * 2, v[i1 + hx], v[hx + (i1 + nx + 2)], v[hx + (i1 + nx + 1)]);
                        TRI(t1 + hx * 2 + 1, v[i1 + hx], v[i1 + 1 + hx], v[hx + (i1 + nx + 2)]);
                    }
                }
            }
            {
                int k;
                for (k = 0; k < o->nV; k++) {
                    Free(v[k], 0xB7E);
                }
            }
            Free(v, 0xB80);
            {
                float k = 0.5f * (1.0f / MulW2(size, 0.5f).Len());
                for (i = 0; i < o->nT; i++) {
                    Tri9C* t = &o->tris[i];
                    float len;
                    V r;
                    r = Rnd9CV();
                    r.x -= 0.5f;
                    r.y -= 0.5f;
                    r.z -= 0.5f;
                    r.w -= 0.5f;
                    r += r;
                    V dir(NormalizedLen(t->c, &len));
                    Fin(&t->n, U(), W(), F3EEF0(o->vB0, dir));
                    len *= k;
                    t->vel = SubP(Vec4_Scale(dir, len), Vec4_Scale(o->vB0, 1.0f - len));
                    t->vel = Mul(t->vel, o->desc->f998 + o->desc->f99C * r.x);
                    t->f0 = o->desc->f9A0 + o->desc->f9A4 * r.z;
                    t->f4 = o->desc->f9A8 + o->desc->f9AC * r.w;
                    t->dead = 0;
                }
            }
        }
        { float d = o->v100.x; float e = a2->v30.x; o->v100.x = d - e; }
        o->v100.y -= a2->v30.y;
        o->v100.z -= a2->v30.z;
        o->f154 -= a2->v30.z;
    }
    if (o->i170 >= 0) {
        int i;
        for (i = 0; i < o->nT; i++) {
            Tri9C* t = &o->tris[i];
            if (!t->dead) {
                unsigned char below;
                V m[4];
                V pos;
                o->b16C = 0;
                t->c += t->vel;
                t->c.w = 1.0f;
                V p;
                p.AE(t->c);
                V n(Normalized(Sphere_FromCenter(t->c, o->v100)));
                below = t->c.z < o->f154;
                if (below || n.Dot(o->v110) < 0.0f) {
                    int e;
                    t->dead = 1;
                    D_0053BB20 = D_005383C8;
                    for (e = 0; e < o->desc->nEmit; e++) {
                        if (EMIT(e).f14 < 0.0f) {
                            pos.Set3(t->c);
                            if (below || Eq(o->v110, D_004BC550)) {
                                Ident(m);
                                if (below) pos.z = o->f154;
                            } else {
                                FrameFrom(m, D_004BC550, o->v110);
                            }
                            if (below) {
                                pos.z += 0.5f;
                            } else {
                                pos += o->v110;
                            }
                            pos.w = 1.0f;
                            {
                                void* r;
                                m[3].AC(pos);
                                r = ParticleDefs_FindByName(D_0053B540, EMIT(e).x0);
                                o->bC = 0;
                                ParticleEmitter_SpawnChildren(ctx, o, r, m, dt);
                                o->bC = 1;
                            }
                            if (!ctx->b68) {
                                ctx->b68 = 1;
                                ctx->v30.AC(pos);
                            }
                        }
                    }
                }
                t->vel *= t->f4;
                t->vel.z += t->f0;
                t->n.d += t->vel.Len() / 4.0f;
            }
        }
    }
    ParticleEmitterBase_Update(o, ctx, a2, a3, dt);
    if (a3) {
        V m;
        if (!(o->desc->f68 <= 0.01f)) {
        V* pm = &m;
        asm { .set reorder } // scheduling barrier: keeps &m first so it fills the bc1t delay slot
        pm->AH(*(V*)a3);
        float k = o->desc->f68;
        m.A6(Mul(*Mtx_DotRowsVec3(&m, a2), k));
        o->v90 += m;
    }
    }
    if (o->desc->b8F4 && !(dt - o->f64 <= o->f60)) {
        o->f64 = dt;
        o->v90.AF(o->v40);
    }
}








