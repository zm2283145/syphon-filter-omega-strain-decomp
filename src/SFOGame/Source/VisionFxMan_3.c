/*
 * SFOGame/Source/VisionFxMan: 8 files, 0025E530-0025F220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025E530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
union A25E530 { int i; float f; void* p; };
struct Fx25E530 { int f0; int f4; char p8[0x28]; unsigned char b30, b31; char p32[2]; int f34; float f38, f3C, f40, f44; };
extern "C" Fx25E530* g_VisionFxMan;
#pragma push
#pragma opt_dead_assignments off
extern "C" int Script_setFxMode(A25E530* args)
{
    int mode = args[0].i;
    Fx25E530* f = g_VisionFxMan;
    if (f->f0 != mode) f->f4 = mode;
    if (f->f4 == -1 && mode) {
        f->f4 = mode;
        f->f34 = 0;
        *(int*)&f->f44 = 0;
        *(int*)&f->f40 = 0;
        *(int*)&f->f3C = 0;
        *(int*)&f->f38 = 0;
        f->b30 = 0;
        f->b31 = 0;
        f->f38 = 0.0f;
        f->f3C = 1.0f;
        f->f40 = 0.0f;
        f->f44 = 0.0f;
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_0025E530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E530 */

/* merge_units: begin func_0025E5B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float a; float b; float c; unsigned char d; } B8S_25E5B0;
extern "C" int D_005383C4;
static inline bool b8off(B8S_25E5B0* s) { return !s->d; }
extern "C" void cScreenFader_Render(B8S_25E5B0* s) {
    float v = 0.0f;
    unsigned char ok = 0;
    if (b8off(s) && s->b > 0.0f) ok = 1;
    if (ok) {
        v = 255.0f * (s->a / s->b);
    } else if (s->c == 1.0f) {
        v = 255.0f;
    }
    if (s->d) v = 0.0f;
    D_005383C4 = (unsigned char)(int)v;
}
static inline void merge_flush_func_0025E5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E5B0 */

/* merge_units: begin func_0025E660 */
#pragma push /* merge_units */
typedef struct { float a; float b; float c; unsigned char fl; } S25E660;
static inline int isActive_b6(S25E660* s) { return !s->fl && s->b > 0.0f; }
void cScreenFader_NextFrame(S25E660* s, float dt)
{
    if (isActive_b6(s)) {
        s->a += s->c * dt;
        if (s->a < 0.0f || s->a > s->b) {
            *(int*)&s->a = 0;
            *(int*)&s->b = 0;
        }
    }
}
static inline void merge_flush_func_0025E660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E660 */

/* merge_units: begin func_0025E6E0 */
#pragma push /* merge_units */
typedef struct { float a; float b; float dir; char flag; } F25E6E0_t;
void cScreenFader_StartFade(F25E6E0_t* p, unsigned char mode, float t) {
    if (t > 0.0f) {
        p->flag = 0;
        switch (mode) {
        case 2:
            p->dir = 1.0f;
            p->a = 0.0f;
            break;
        case 1:
            p->dir = -1.0f;
            p->a = t;
            break;
        }
        p->b = t;
    }
}
static inline void merge_flush_func_0025E6E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E6E0 */

/* merge_units: begin func_0025E750 */
#pragma push /* merge_units */
/* cSyncBar_Render: draws one two-vertex untextured strip at the top of the current viewport slot; sibling of cScreenTile_Render (same render-state push/pop, GCC-style quad copy / identity matrix asm). */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off

typedef struct V4_0025E750 { float x, y, z, w; } V4_0025E750;
typedef struct Mtx_0025E750 { __int128 q[4]; } Mtx_0025E750;
typedef struct Ent_0025E750 {
    char pad[0x28];
    V4_0025E750* pos;
    V4_0025E750* c2C;
    V4_0025E750* c30;
    V4_0025E750* c34;
} Ent_0025E750;
typedef struct Slot_0025E750 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_0025E750;
typedef struct Rs_0025E750 {
    char pad[0xA80];
    Mtx_0025E750 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_0025E750 ents[1];
} Rs_0025E750;
typedef struct Arg_0025E750 { int tex; float dx; float dy; float alpha; } Arg_0025E750;

extern "C" {
typedef struct G_0025E750 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_0025E750;
extern G_0025E750 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_0025E750 D_00539170;
extern long long D_004BC1B0;
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void cVector_opAssign(V4_0025E750* d, V4_0025E750* s);
void tIRGBA_opAssign_tRGBAR(V4_0025E750* d, V4_0025E750* s);
float tVifFloatToInt_short_4_Bias(void);
V4_0025E750* cVector_ctor_float_float_float_float(V4_0025E750* o, float x, float y, float z, float w);
void XLib_DrawSprites2(void* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS_0025E750 ((Rs_0025E750*)g_Video)
#define SLOT_0025E750(i) ((Slot_0025E750*)(g_Video + (i) * 0x110))

static inline void UM_0025E750(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_0025E750(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

struct V4c_0025E750 {
    float x, y, z, w;
    V4c_0025E750(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline void Emit_0025E750(const V4c_0025E750& pos, const V4c_0025E750& col)
{
    Ent_0025E750* e;
    XLib_NextBatchVert(g_Video);
    e = &RS_0025E750->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], (V4_0025E750*)&pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], (V4_0025E750*)&col);
    D_005381F8 = 2LL << 32;
}
static inline unsigned char Prim_0025E750(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_0025E750(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline void Setup_0025E750(const V4_0025E750* vp)
{
    g_DrawMode = 0x200;
    D_005392D8 = D_004BC1B0;
    D_00538C60++;
    { Slot_0025E750* s0 = SLOT_0025E750(D_00538C60); s0->f2F6 = 1; }
    {
        Slot_0025E750* s = SLOT_0025E750(D_00538C60);
        s->r[0] = vp->x;
        s->r[1] = vp->y;
        s->r[2] = vp->z;
        s->r[3] = vp->w;
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    {
        Slot_0025E750* s = SLOT_0025E750(D_00538C60);
        s->f2E0 = 0;
        s->f2E8 = 1.0f;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_0025E750(&RS_0025E750->mtx[D_00538C64 + 1], &RS_0025E750->mtx[D_00538C64]);
    D_00538C64++;
    UM_0025E750(&RS_0025E750->mtx[D_00538C64]);
    D_00538C68 = 1;
}

extern "C" void cSyncBar_Render(float* y)
{
    int saved;
    float hw;
    Ent_0025E750* e;
    int vp;
    /* volatile: retail loads D_00538C60 again for the push below */
    hw = 0.5f * SLOT_0025E750(*(volatile int*)&D_00538C60)->r[2];
    saved = g_DrawMode;
    vp = (int)&D_00539170;
    Setup_0025E750((V4_0025E750*)vp);
    D_00539238 = Prim_0025E750();
    D_0053923C = Mode_0025E750();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS_0025E750->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
    Emit_0025E750(V4c_0025E750(-hw, *y, 1e-8f, 1.0f), V4c_0025E750(0.0f, 0.0f, 0.0f, 0.14f));
    Emit_0025E750(V4c_0025E750(hw, 4.0f + *y, 1e-8f, 1.0f), V4c_0025E750(0.0f, 0.0f, 0.0f, 0.14f));
    XLib_DrawSprites2(g_Video);
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    SLOT_0025E750(D_00538C60)->f2F6 = 1;
    g_DrawMode = saved;
}
static inline void merge_flush_func_0025E750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E750 */

/* merge_units: begin func_0025EC20 */
#pragma push /* merge_units */
/* cScreenTile_Render: tiled quad draw. D_00539210..D8 are one struct global, so stores to one field make MW reload g_DrawMode for each ternary as retail does. The quad copy and identity matrix are GCC-style __asm__ volatile (no CSE across them). inline_depth(10) is needed so the nested inlines expand. */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off

typedef struct V4_0025EC20 { float x, y, z, w; } V4_0025EC20;
typedef struct Mtx_0025EC20 { __int128 q[4]; } Mtx_0025EC20;
typedef struct Ent_0025EC20 {
    char pad[0x28];
    V4_0025EC20* pos;
    V4_0025EC20* c2C;
    V4_0025EC20* c30;
    V4_0025EC20* c34;
} Ent_0025EC20;
typedef struct Slot_0025EC20 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_0025EC20;
typedef struct Rs_0025EC20 {
    char pad[0xA80];
    Mtx_0025EC20 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_0025EC20 ents[1];
} Rs_0025EC20;
typedef struct Arg_0025EC20 { int tex; float dx; float dy; float alpha; } Arg_0025EC20;

extern "C" {
typedef struct G_0025EC20 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_0025EC20;
#if 0 /* merge_units */
extern G_0025EC20 D_00539210;
#endif /* merge_units */
#define D_00539210 (*(G_0025EC20*)&D_00539210) /* merge_units */

#if 0 /* merge_units */
extern V4_0025EC20 D_00539170;
#endif /* merge_units */
#define D_00539170 (*(V4_0025EC20*)&D_00539170) /* merge_units */

#if 0 /* merge_units */
void cVector_opAssign(V4_0025EC20* d, V4_0025EC20* s);
#endif /* merge_units */
#define cVector_opAssign(a0, a1) (cVector_opAssign((V4_0025E750 *)(a0), (V4_0025E750 *)(a1))) /* merge_units */

#if 0 /* merge_units */
void tIRGBA_opAssign_tRGBAR(V4_0025EC20* d, V4_0025EC20* s);
#endif /* merge_units */
#define tIRGBA_opAssign_tRGBAR(a0, a1) (tIRGBA_opAssign_tRGBAR((V4_0025E750 *)(a0), (V4_0025E750 *)(a1))) /* merge_units */

#if 0 /* merge_units */
V4_0025EC20* cVector_ctor_float_float_float_float(V4_0025EC20* o, float x, float y, float z, float w);
#endif /* merge_units */
#define cVector_ctor_float_float_float_float(a0, a1, a2, a3, a4) ((V4_0025EC20 *)cVector_ctor_float_float_float_float((V4_0025E750 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

}
#define RS_0025EC20 ((Rs_0025EC20*)g_Video)
#define SLOT_0025EC20(i) ((Slot_0025EC20*)(g_Video + (i) * 0x110))

static inline void UM_0025EC20(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_0025EC20(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

struct V4c_0025EC20 {
    float x, y, z, w;
    V4c_0025EC20(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline void Emit_0025EC20(const V4c_0025EC20& pos, const V4c_0025EC20& col, const V4c_0025EC20& uv)
{
    V4_0025EC20 tmp;
    Ent_0025EC20* e;
    float u;
    XLib_NextBatchVert(g_Video);
    e = &RS_0025EC20->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], (V4_0025EC20*)&pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], (V4_0025EC20*)&col);
    u = uv.x + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline unsigned char Prim_0025EC20(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_0025EC20(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline void Setup_0025EC20(Arg_0025EC20* a, const V4_0025EC20* vp)
{
    g_DrawMode = 5;
    D_005392D8 = D_004BC1B0;
    cTexMan_SetActive(g_TextureMgr, a->tex);
    D_00538C60++;
    { Slot_0025EC20* s0 = SLOT_0025EC20(D_00538C60); s0->f2F6 = 1; }
    {
        Slot_0025EC20* s = SLOT_0025EC20(D_00538C60);
        s->r[0] = vp->x;
        s->r[1] = vp->y;
        s->r[2] = vp->z;
        s->r[3] = vp->w;
        s->f2F5 = 1;
        s->f2F6 = 1;
    }
    {
        Slot_0025EC20* s = SLOT_0025EC20(D_00538C60);
        s->f2E0 = 0;
        s->f2E8 = 1.0f;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_0025EC20(&RS_0025EC20->mtx[D_00538C64 + 1], &RS_0025EC20->mtx[D_00538C64]);
    D_00538C64++;
    UM_0025EC20(&RS_0025EC20->mtx[D_00538C64]);
    D_00538C68 = 1;
}

extern "C" void cScreenTile_Render(Arg_0025EC20* a)
{
    int vp = (int)&D_00539170;
    int saved;
    float hw, hh, y, x;
    Ent_0025EC20* e;
    hw = 0.5f * SLOT_0025EC20(D_00538C60)->r[2];
    hh = 0.5f * SLOT_0025EC20(D_00538C60)->r[3];
    saved = g_DrawMode;
    Setup_0025EC20(a, (V4_0025EC20*)vp);
    y = hh;
    D_00539238 = Prim_0025EC20();
    D_0053923C = Mode_0025EC20();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS_0025EC20->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
    for (; y > -hh; y -= a->dy) {
        for (x = -hw; x < hw; x += a->dx) {
            Emit_0025EC20(V4c_0025EC20(x, y, 1e-8f, 1.0f), V4c_0025EC20(1.0f, 1.0f, 1.0f, a->alpha), V4c_0025EC20(0.0f, 0.0f, 1.0f, 0.0f));
            Emit_0025EC20(V4c_0025EC20(x + a->dx, y - a->dy, 1e-8f, 1.0f), V4c_0025EC20(1.0f, 1.0f, 1.0f, a->alpha), V4c_0025EC20(1.0f, 1.0f, 1.0f, 0.0f));
        }
    }
    XLib_DrawSprites2(g_Video);
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    SLOT_0025EC20(D_00538C60)->f2F6 = 1;
    g_DrawMode = saved;
}
#undef D_00539210 /* merge_units */
#undef D_00539170 /* merge_units */
#undef cVector_opAssign /* merge_units */
#undef tIRGBA_opAssign_tRGBAR /* merge_units */
#undef cVector_ctor_float_float_float_float /* merge_units */
static inline void merge_flush_func_0025EC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025EC20 */

/* merge_units: begin func_0025F220 */
#pragma push /* merge_units */
/* Returns 2048.0f. */
float tVifFloatToInt_short_4_Bias(void)
{
    return 2048.0f;
}
static inline void merge_flush_func_0025F220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025F220 */

/* merge_units: begin func_0025F230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int cVisionFxMan_DrawLightGlows(int*, int, int);

/* Calls cVisionFxMan_DrawLightGlows(self, a1, 1) when the state is 1 or 2. */
void cVisionFxMan_DrawLightSfx(int* self, int a1) {
    int state = *self;

    if (state == 1 || state == 2) {
        cVisionFxMan_DrawLightGlows(self, a1, 1);
    }
}
static inline void merge_flush_func_0025F230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025F230 */
