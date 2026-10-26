/* VisionFx_DrawScanBand: draws one two-vertex untextured strip at the top of the current viewport slot; sibling of VisionFx_DrawNoiseTiles (same render-state push/pop, GCC-style quad copy / identity matrix asm). */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

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
void Renderer_BindTexture(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void Vec4_Copy(V4_0025E750* d, V4_0025E750* s);
void GuiBatch_AddVertexColor(V4_0025E750* d, V4_0025E750* s);
float GuiBatch_AddVertexUV(void);
V4_0025E750* Vec4_Set(V4_0025E750* o, float x, float y, float z, float w);
void Renderer_FlushPrimitives(void* s);
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
    Vec4_Copy(&e->pos[D_00539224 - 1], (V4_0025E750*)&pos);
    GuiBatch_AddVertexColor(&e->c30[D_00539224 - 1], (V4_0025E750*)&col);
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

extern "C" void VisionFx_DrawScanBand(float* y)
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
    Renderer_FlushPrimitives(g_Video);
    D_00538C68 = 1;
    D_00538C64--;
    D_00538C60--;
    SLOT_0025E750(D_00538C60)->f2F6 = 1;
    g_DrawMode = saved;
}
