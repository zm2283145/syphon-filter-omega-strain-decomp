#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& s) { V4* d = this; const V4* p = &s; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(p) : "r"(d) : "memory"); }
} __attribute__((aligned(16)));
typedef struct Ent {
    char pad[0x28];
    V4* pos;
    V4* c2C;
    V4* c30;
    V4* c34;
} Ent;
typedef struct Rs {
    char pad[0xFB0];
    Ent ents[1];
} Rs;
typedef struct Splash {
    float t;
    char pad4[0xC];
    V4 pos;
    float r20;
    float r24;
    int tex;
} Splash;

extern "C" {
typedef struct G {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern long long D_004BC1B0;
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void cVector_opAssign(V4* d, const V4* s);
void tIRGBA_opAssign_tRGBAR(V4* d, const V4* s);
float tVifFloatToInt_short_4_Bias(void);
V4* cVector_ctor_float_float_float_float(V4* o, float x, float y, float z, float w);
void XLib_DrawStrip(void* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS ((Rs*)g_Video)

struct V4c {
    float x, y, z, w;
    V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));

static inline void CP(V4* d, const V4* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline void AddTo(V4* out, const V4c& a0, const V4& b0)
{
    V4 r;
    const V4c* a = &a0;
    V4* pr = &r;
    const V4* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    CP(out, &r);
}
static inline void AddTo0(V4* out, const V4c& a0, const V4& b0)
{
    V4 r;
    const V4c* a = &a0;
    V4* pr = &r;
    const V4* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    const V4* s = &r;
    __asm__ volatile("lq %0, 0x0(%0)" : "+r"(s));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(s), "r"(out) : "memory");
}
static inline void AddTo1(V4* out, const V4c& a0, const V4& b0)
{
    V4 r;
    const V4c* a = &a0;
    V4* pr = &r;
    const V4* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    const V4* s = &r;
    __asm__ volatile("lq %0, 0x0(%0)" : "+r"(s));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(s), "r"(out) : "memory");
}
static inline void AddTo2(V4* out, const V4c& a0, const V4& b0)
{
    V4 r;
    const V4c* a = &a0;
    V4* pr = &r;
    const V4* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    CP(out, &r);
}
static inline void AddTo3(V4* out, const V4c& a0, const V4& b0)
{
    V4 r;
    const V4c* a = &a0;
    const V4* b = &b0;
    V4* pr = &r;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    V4* o = out;
    const V4* s = &r;
    __asm__ volatile("lq %0, 0x0(%0)" : "+r"(s));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(s), "r"(o) : "memory");
}
static inline void Emit(const V4& pos, const V4c& col, const V4c& uv)
{
    V4 tmp;
    Ent* e;
    float u;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], (const V4*)&col);
    u = uv.x + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline void AddX(V4* out, const V4c& a0, const V4& b0, const V4c*& a, const V4*& b, V4*& pr, const V4*& sp, V4*& o)
{
    V4 r;
    a = &a0;
    pr = &r;
    b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%0)\n lqc2 $vf2, 0x0(%1)\n vadd.xyzw $vf1, $vf1, $vf2\n sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(pr) : "memory");
    o = out;
    sp = &r;
    __asm__ volatile("lq %0, 0x0(%0)" : "+r"(sp));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(sp), "r"(o) : "memory");
}
extern "C" void cSplash_Render(Splash* s)
{
    float a, r;
    Ent* e;
    { float z = 0.0f; if (z == *(volatile float*)&s->t) return; }
    { float k = 0.14f; a = k * s->t; }
    if (a <= 0.0078125f) return;
    cTexMan_SetActive(g_TextureMgr, s->tex);
    D_005392D8 = D_004BC1B0;
    { float k = (5.0f - s->t) / 5.0f; r = s->r20 + k * s->r24; }
    V4 c0, c1, c2, c3;
    const V4c* a0; V4* p0; const V4* b0; const V4c* a1; V4* o0; const V4* s0; V4* p1; const V4* b1; const V4c* a2; V4* o1; const V4* s1; V4* p2; const V4* b2; const V4c* a3; V4* o2; const V4* s2; const V4* b3; V4* p3; V4* o3; const V4* s3;
    AddX(&c0, V4c(-r, -r, 0.0f, 1.0f), s->pos, a0, b0, p0, s0, o0);
    AddX(&c1, V4c(-r, r, 0.0f, 1.0f), s->pos, a1, b1, p1, s1, o1);
    AddX(&c2, V4c(r, -r, 0.0f, 1.0f), s->pos, a2, b2, p2, s2, o2);
    AddX(&c3, V4c(r, r, 0.0f, 1.0f), s->pos, a3, b3, p3, s3, o3);
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
    Emit(c0, V4c(1.0f, 1.0f, 1.0f, a), V4c(0.0f, 1.0f, 1.0f, 0.0f));
    Emit(c1, V4c(1.0f, 1.0f, 1.0f, a), V4c(0.0f, 0.0f, 1.0f, 0.0f));
    Emit(c2, V4c(1.0f, 1.0f, 1.0f, a), V4c(1.0f, 1.0f, 1.0f, 0.0f));
    Emit(c3, V4c(1.0f, 1.0f, 1.0f, a), V4c(1.0f, 0.0f, 1.0f, 0.0f));
    XLib_DrawStrip(g_Video);
}






