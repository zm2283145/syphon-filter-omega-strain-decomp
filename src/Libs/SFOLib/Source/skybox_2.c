/*
 * Libs/SFOLib/Source/skybox: 4 files, 003BC270-003BC520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BC270 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ field setter.
 */

#include "types.h"
#include "skybox_types.h"

void cSKYBOX_GOBJ_Init(cSkyboxGobj* self, int value) {
    self->unk8C = value;
}
static inline void merge_flush_func_003BC270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC270 */

/* merge_units: begin func_003BC280 */
#pragma push /* merge_units */
/* cSKYBOX_GOBJ_Render (proto cSKYBOX_GOBJ::Render): draws the sky layers back to front with
 * z writes off, z test "always", the sky draw context, and the current view with its
 * translation cleared; then restores the context, z state and view. */
#pragma cplusplus on
#pragma inline_depth(8)
typedef unsigned long u_long;
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& r(int i) { return *(V*)m[i]; }
} __attribute__((aligned(16)));
struct cSLayer;
struct cSKYBOX_GOBJ {
    char pad0[0x68];
    int numLayers;
    cSLayer* layers[8];
};
extern "C" {
extern char g_Video[];
extern int g_DrawMode;
extern u_long D_00538290;          /* XLib screen.zbuf */
extern unsigned char D_005382C0;   /* XLib screen.frameEnvChanged */
extern unsigned int D_005382E4;    /* XLib pixenv.ztst */
extern unsigned int D_005382EC;    /* XLib pixenv.zmsk */
extern int D_00538C64;             /* XLib viewNum */
extern unsigned char D_00538C68;   /* XLib compMatDirty */
void cSLayer_Render(cSLayer* l);
void cSKYBOX_GOBJ_Render(cSKYBOX_GOBJ* self);
}
#define STK(i) (*(M*)(g_Video + 0xA80 + (i) * 0x40))

/* 128-bit lq/sq copies: C has no quadword move. The dead `p` copy is deliberate: retail keeps
 * the extra destination address computation. */
static inline void CpV(V* dst, const V* src) { V* p = dst; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(dst), "r"(src) : "memory"); }
/* ZBUF.ZMSK (bit 32) follows pixenv.zmsk */
static inline void UpdateZBuf() { u_long m = (u_long)D_005382EC << 32; D_00538290 = (D_00538290 & ~((u_long)1 << 32)) | m; }
static inline void PushView(M& m)
{
    STK(D_00538C64 + 1) = STK(D_00538C64);
    D_00538C64++;
    STK(D_00538C64) = m;
    D_00538C68 = 1;
}

void cSKYBOX_GOBJ_Render(cSKYBOX_GOBJ* self)
{
    unsigned int xlibCtxt = g_DrawMode;
    unsigned int skyCtxt;
    M vmat;
    int i;
    skyCtxt = (xlibCtxt & ~0x1F0) | 0x10000000;
    D_005382EC = 1;
    D_005382C0 = 1;
    D_005382E4 = 1;
    g_DrawMode = skyCtxt;
    UpdateZBuf();
    vmat = STK(D_00538C64);
    { V t(0.0f, 0.0f, 0.0f, 1.0f); CpV((V*)vmat.m[3], &t); }
    PushView(vmat);
    for (i = self->numLayers - 1; i >= 0; i--)
        cSLayer_Render(self->layers[i]);
    D_00538C64--;
    g_DrawMode = xlibCtxt;
    D_00538C68 = 1;
    D_005382C0 = 1;
    D_005382EC = 0;
    UpdateZBuf();
    D_005382E4 = 2;
}
static inline void merge_flush_func_003BC280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC280 */

/* merge_units: begin func_003BC520 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0x68]; int count; void* items[1]; } G4_Act;
extern void cSLayer_Update(void* a);
extern void cGOBJ_NextFrame(G4_Act* a, float dt);
void cSKYBOX_GOBJ_NextFrame(G4_Act* a, float dt)
{
    int i;
    for (i = 0; i < a->count; i++) {
        cSLayer_Update(a->items[i]);
    }
    cGOBJ_NextFrame(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC520 */

/* merge_units: begin func_003BC5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004BD038[];
extern char D_004DFC70[];
void cGOBJ_dtor(void* self, int flag);
void cHogFile_dtor(void* p, int flag);
void cVU1Model_dtor(void* p, int flag);
void cVU1Model_Unload(void* p);
void operator_delete(void* p);
}
struct SkyM {
    char pad0[0x16C]; void* p16C; unsigned char b170; char pad171[3]; char m174[4];
};
struct SkyG {
    void* vt; char pad4[0x64]; int n68; SkyM* a6C[1];
};
static inline void DelSky(SkyM* p)
{
    AllocGuard g;
    if (p) {
        cVU1Model_Unload(p->m174);
        if (p->b170) {
            void* q = p->p16C;
            AllocGuard g2;
            cMemMan_Deallocate(0, q, D_004BD038, 0x2B);
        }
        cVU1Model_dtor(p->m174, -1);
        cHogFile_dtor(p, -1);
    }
    cMemMan_Deallocate(0, p, D_004BD038, 0x97);
}
extern "C" SkyG* cSKYBOX_GOBJ_dtor(SkyG* self, short flag)
{
    int i;
    if (self) {
        self->vt = D_004DFC70;
        for (i = 0; i < self->n68; i++) {
            if (self->a6C[i])
                DelSky(self->a6C[i]);
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC5A0 */
