/* cSKYBOX_GOBJ_Render (proto cSKYBOX_GOBJ::Render): draws the sky layers back to front with
 * z writes off, z test "always", the sky draw context, and the current view with its
 * translation cleared; then restores the context, z state and view. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
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
