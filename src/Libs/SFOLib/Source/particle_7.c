/*
 * Libs/SFOLib/Source/particle: 6 files, 003982E0-00398590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003982E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector push_back helpers.
 */

#include "types.h"
#include "particle_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int std_vector_cEffectRequestPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* push_back on a pointer vector. */
int cArray_intPtr_PushBackActual(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_003982E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003982E0 */

/* merge_units: begin func_00398320 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_allocate.h"

/* Allocate under the allocator guard. */
DEFINE_GUARDED_ALLOCATE(opNewArray)
static inline void merge_flush_func_00398320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00398320 */

/* merge_units: begin func_003983E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * ParticleRelFlag constructor.
 */


extern Rel* std_vector_imp_intPtr_1_ctor(Rel* r);

ParticleRelFlag* cArray_intPtr_ctor(ParticleRelFlag* self) {
    std_vector_imp_intPtr_1_ctor(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003983E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003983E0 */

/* merge_units: begin func_00398410 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Rel initializers and pointer vector push_back.
 */




/* Zeroes the three words. */
Rel* std_vector_imp_intPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* push_back on a pointer vector. */
int std_vector_intPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Zeroes the three words. */
Rel* std_vector_cEffectRequestPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398410 */

/* merge_units: begin func_00398470 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* Quad copies as GCC-style volatile lq/sq asm (house idiom); the unused `xx` locals keep retail's dead address addius.
   M(const M&, int) is the same matrix copy without the dead addiu (retail has it on the parameter copy only). */
/* cParticleSpray_UpdateGravityVector: reset the emitter's gravity to the zero vector rotated into local space and refresh its rate */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* xx = this; const V* s = &o; __int128 q; V* d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M(const M& o, int) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& Transpose3() {
        M& s = *this;
        float t;
        t = s.m[0][1]; s.m[0][1] = s.m[1][0]; s.m[1][0] = t;
        t = s.m[0][2]; s.m[0][2] = s.m[2][0]; s.m[2][0] = t;
        t = s.m[1][2]; s.m[1][2] = s.m[2][1]; s.m[2][1] = t;
        return s;
    }
} __attribute__((aligned(16)));
static inline M Transposed(const M& a) { M r(a, 0); M& p = r.Transpose3(); return p; }
static inline V& Rot(V& v, M m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(&v), "r"(&m), "r"(&v) : "memory"); return v; }
struct Def { char pad[0x64]; unsigned char rate; };
struct Emitter { char pad0[0xD0]; V grav; char padE0[0x120 - 0xE0]; Def* def; };
extern "C" V D_004BC550;
extern "C" void cParticleSpray_UpdateGravityVector(Emitter* e, const M* m)
{
    e->grav = D_004BC550;
    e->grav = Rot(e->grav, Transposed(*m));
    e->grav.w = e->def->rate;
}
static inline void merge_flush_func_00398470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00398470 */

/* merge_units: begin func_00398590 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_rotateloops off

typedef unsigned long long u64_t;

struct V4_0050 {
    float x, y, z, w;
    V4_0050() {}
    V4_0050(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4_0050& operator=(const V4_0050& o)
    {
        { void* xx = this; } /* dead on purpose: retail computes the destination first */
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/* quadword copy through a register (lq/sq) */
static inline void QC_0050(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Q_0050 { __int128 q; };


extern "C" {
extern char D_00537F80[];
extern char g_Video[];
extern char D_00538080[];
extern char D_0053B6A0[];
extern unsigned char D_0053B540;
extern unsigned int* D_005381C8;
unsigned int* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void* q, int a, int b, int c, int d);
void cDmaMan_EndChain_int_ulongP(void* q, int a, void* end);
int XLib_GetTexMan(void* r);
void* cTexMan_GetHalTexture(int reg, int tex);
u64_t* cTexture_GetTEX1_1(void* t);
u64_t* cTexture_GetTEX0_1(void* t);
void MEMCPY16(void* d, void* s, int n);
Q_0050* cRandomVector_Vector(void* tbl, int i);
unsigned int cVU1Man_GetMSCAL(void* q, int n);
float Libc_Powf(float x, float y);
}

static inline unsigned int Unpack_0050(unsigned int a, unsigned int n) { return (0x6C000000 | ((n) << 16) | (a)); }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

/* the original copies quadwords into the packet with this inline-asm loop */
static inline void QCopy_0050(const void* s, void* d, int n)
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
/* per-site copy of QCopy_0050: parameter order picks retail registers */
static inline void QCopy1_0050(void* d, int n, const void* s)
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

static inline void V3Copy_0050(V4_0050* d, const V4_0050* s)
{
    float w = d->w;
    QC_0050(d, s);
    d->w = w;
}

static inline void Vif_Put(unsigned int v)
{
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = v;
}

/* same as Vif_Put with the value copied first (register choice at the first site) */
static inline void Vif_PutV(unsigned int v)
{
    unsigned int x = v;
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = x;
}

static inline void Vif_PadTo(unsigned int m)
{
    while (((unsigned int)D_005381C8 & 0xF) != m) {
        Vif_Put(0);
    }
}

extern "C" void cParticleSpray_Render(char* e, float t, float a, float b, float c)
{
    float u;
    float v;
    float z;
    float w;
    float el;
    int i;
    if (F_(e, 0x6C, int) <= 0) return;
    z = 0.0f;
    w = z;
    el = t + F_(F_(e, 0x120, char*), 0x9B0, float) - F_(e, 0x64, float);
    if (F_(F_(e, 0x120, char*), 0x3C, int) > 0) {
        u = 60.0f * el;
        v = 60.0f * F_(F_(e, 0x120, char*), 0x40, float);
    } else {
        v = z;
        u = 60.0f * el;
    }
    if (F_(F_(e, 0x120, char*), 0x8F0, int)) {
        V3Copy_0050((V4_0050*)(F_(e, 0x120, char*) + 0x980), (V4_0050*)(e + 0x50));
    }
    if (!D_0053B540 || !F_(F_(e, 0x120, char*), 0x58, int)) {
        F_(F_(e, 0x120, char*), 0x98C, float) = F_(F_(e, 0x120, char*), 0x50, float) * c;
    } else {
        F_(F_(e, 0x120, char*), 0x98C, float) = F_(F_(e, 0x120, char*), 0x54, float) * c;
    }
    F_(e, 0xAC, float) = a;
    F_(e, 0xBC, float) = b;
    for (i = 0; i < F_(F_(e, 0x120, char*), 0x3C, int) + 1; i++) {
        char* s3;
        char* s7;
        int left;
        int lim;
        u64_t* p;
        float pw = Libc_Powf(u, F_(F_(e, 0x120, char*), 0x9A8, float));
        float pk = pw * F_(F_(e, 0x120, char*), 0x9AC, float);
        *(V4_0050*)(e + 0xC0) = V4_0050(el, u, z, w);
        F_(F_(e, 0x120, char*), 0x920, float) = pw;
        F_(F_(e, 0x120, char*), 0x930, float) = pk;
        D_005381C8 = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 0);
        Vif_PutV(0x11000000);
        Vif_Put(0);
        Vif_PadTo(0xC);
        Vif_Put(Unpack_0050(0xF, 5));
        QCopy1_0050(D_005381C8, 5, e + 0x90);
        D_005381C8 += 0x14;
        {
            char* src = F_(e, 0x120, char*) + 0x900;
            Vif_PadTo(0xC);
            Vif_Put(Unpack_0050(0x14, 9));
            QCopy_0050(src, D_005381C8, 9);
        }
        D_005381C8 += 0x24;
        Vif_PadTo(0);
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, D_005381C8);
        s3 = F_(e, 0x120, char*);
        s7 = F_(e, 0x70, char*);
        left = F_(e, 0x6C, int);
        u -= v;
        z += F_(s3, 0x44, float);
        w += F_(s3, 0x48, float);
        F_(s3, 0xB0, u64_t) = *cTexture_GetTEX1_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        F_(s3, 0xC0, u64_t) = *cTexture_GetTEX0_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        lim = 0x21;
        if (F_(s3, 0x64, unsigned char)) {
            F_(s3, 0xB8, u64_t) = 0x15;
            lim = 0xE;
            F_(s3, 0xC8, u64_t) = 7;
            F_(s3, 0xD0, u64_t) = 1 | ((u64_t)0x612F4000 << 32);
            F_(s3, 0xD8, u64_t) = 1 | ((u64_t)0x602F4000 << 32);
        }
        p = (u64_t*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 1);
        *p = 0;
        p++;
        while (left > 0) {
            int n = left < lim ? left : lim;
            F_(s3, 0x130, u64_t) = (long long)n | (0x8000 | ((u64_t)0x602F4000 << 32));
            *p = 0;
            p++;
            *p = (u64_t)0x6C0D8000 << 32;
            p++;
            MEMCPY16(p, s3 + 0x80, 0xC);
            p += 0x18;
            *(Q_0050*)p = *cRandomVector_Vector(D_0053B6A0, (int)(s7 + left));
            p += 2;
            *p = cVU1Man_GetMSCAL(D_00538080, 0x16);
            p++;
            *p = 0;
            p++;
            left -= n;
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p);
        if (u < 0.0f) u = u; /* no-op on purpose: retail keeps this compare (its body was compiled out) */
    }
}
static inline void merge_flush_func_00398590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00398590 */
