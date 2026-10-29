#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

typedef struct V4_2A20 { float x, y, z, w; } V4_2A20;
typedef struct Ent_2A20 {
    char pad[0x28];
    V4_2A20* pos;
    V4_2A20* c2C;
    V4_2A20* c30;
    V4_2A20* c34;
} Ent_2A20;
typedef struct Rs_2A20 {
    char pad[0xFB0];
    Ent_2A20 ents[1];
} Rs_2A20;
static inline void QS(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void QN(void* d, const void* s) { __int128* dd = (__int128*)d; const __int128* ss = (const __int128*)s; *dd = *ss; }
static inline void QB(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
static inline void QR(const void* s, void* d) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QL(void* d, const void* s) { void* dd = d; const void* ss = s; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(dd), "r"(ss) : "memory"); }
static inline void QM(void* d, const void* s) { __int128 t; const void* ss = s; void* dd = d; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(dd), "r"(ss) : "memory"); }
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    static void W1(void* d, const void* s) { QC(d, s); }
    V& Add1(const V& b) { return Add0(b); }
    V& Add2(const V& b) { return Add1(b); }
    V& Add3(const V& b) { return Add2(b); }
    V(const V& o) { QC(this, &o); }
    V operator-(const V& b) const { V r; __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory"); return r; }
    V& operator+=(const V& b) { return Add1(b); }
    V& Add0(const V& b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&b) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct tRGBA { float r, g, b, a; tRGBA(float r0, float g0, float b0, float a0) { r = r0; g = g0; b = b0; a = a0; } };
struct VList { int f0; int count; V* data; int pad; V off; };

extern "C" {
typedef struct G_2A20 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_2A20;
extern G_2A20 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern long long D_004BC1B0;
extern VList D_004F8000;
extern float D_0048AFB0, D_0048AFB8, D_0048AFC0, D_0048AFC8, D_0048AFD0;
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void cVector_opAssign(V4_2A20* d, V* s);
void tIRGBA_opAssign_tRGBAR(V4_2A20* d, tRGBA* s);
void XLib_DrawStrip(void* s);
void std_vector_deleter_cVector_clear(VList* l);
void func_0025C650(void);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)
#define RS_2A20 ((Rs_2A20*)g_Video)

static inline unsigned char Prim_2A20(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_2A20(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Emit_2A20(V* pos, tRGBA* col)
{
    Ent_2A20* e;
    XLib_NextBatchVert(g_Video);
    e = &RS_2A20->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], col);
    D_005381F8 = 2LL << 32;
}

extern "C" void func_0025C650(void)
{
    tRGBA arcCol(D_0048AFB0, D_0048AFB8, D_0048AFC0, D_0048AFC8);
    int saved;
    int cnt;
    int i;
    float step;
    saved = g_DrawMode;
    cnt = D_004F8000.count;
    g_DrawMode = 0;
    D_005392D8 = D_004BC1B0;
    D_00539238 = Prim_2A20();
    D_0053923C = Mode_2A20();
    D_00539228 = 0;
    D_0053923C &= ~1;
    {
        Ent_2A20* e = &RS_2A20->ents[D_00539210.f10];
        e->pos += D_00539224;
        e->c2C += D_00539224;
        e->c30 += D_00539224;
        e->c34 += D_00539224;
    }
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
    step = (D_0048AFC8 - D_0048AFD0) / cnt;
    for (i = 0; i < cnt; i++) {
        V p; QL(&p, &D_004F8000.data[i]);
        V lo(p - D_004F8000.off);
        p += D_004F8000.off;
        Emit_2A20(&lo, &arcCol);
        Emit_2A20(&p, &arcCol);
        arcCol.a -= step;
    }
    XLib_DrawStrip(g_Video);
    g_DrawMode = saved;
    std_vector_deleter_cVector_clear(&D_004F8000);
}
