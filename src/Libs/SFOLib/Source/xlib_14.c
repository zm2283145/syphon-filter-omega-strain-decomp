/*
 * Libs/SFOLib/Source/xlib: 5 files, 0037D9A0-0037E0D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037D9A0 */
#pragma push /* merge_units */
/* 0037D9A0 XLib_UpdateCompMat - xlib.cc */
#pragma cplusplus on
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V4(const V4& s, int) { void* xx = this; V4& refThis = *this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&s) : "memory"); }
    V4(const V4& s) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(this) : "memory"); }
    V4& operator=(const V4& s) { void* xx = this; __int128 reg; V4& refThis = *this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&s) : "memory"); return refThis; }
} __attribute__((aligned(16)));

static inline void GQR(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MulM4c(void* out0, const void* c0, const void* a0)
{ void* out = out0; const void* c = c0; const void* a = a0;
        asm {
            lqc2 vf4, 0x0(a)
            lqc2 vf5, 0x10(a)
            lqc2 vf6, 0x20(a)
            lqc2 vf7, 0x30(a)
            lqc2 vf8, 0x0(c)
            lqc2 vf9, 0x10(c)
            lqc2 vf10, 0x20(c)
            lqc2 vf11, 0x30(c)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            vmulax.xyzw ACC, vf4, vf9x
            vmadday.xyzw ACC, vf5, vf9y
            vmaddaz.xyzw ACC, vf6, vf9z
            vmaddw.xyzw vf13, vf7, vf9w
            vmulax.xyzw ACC, vf4, vf10x
            vmadday.xyzw ACC, vf5, vf10y
            vmaddaz.xyzw ACC, vf6, vf10z
            vmaddw.xyzw vf14, vf7, vf10w
            vmulax.xyzw ACC, vf4, vf11x
            vmadday.xyzw ACC, vf5, vf11y
            vmaddaz.xyzw ACC, vf6, vf11z
            vmaddw.xyzw vf15, vf7, vf11w
            sqc2 vf12, 0x0(out)
            sqc2 vf13, 0x10(out)
            sqc2 vf14, 0x20(out)
            sqc2 vf15, 0x30(out)
        }
}
struct M4 {
    float m[4][4];
    M4() {}
    M4(const M4& s) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&s) : "memory"); }
    M4& operator=(const M4& s) { void* xx = this; M4& refThis = *this; GQR(&refThis, &s); return refThis; }
    M4 operator*(const M4& b) const {
        M4 o; MulM4c(&o, &b, this); return o;
    }
    V4 operator*(const V4& v) const;
};

static inline V4* MVa(void* p0, const void* m0) { void* p = p0; const void* m = m0;
        asm {
            lqc2 vf8, 0x0(p)
            lqc2 vf4, 0x0(m)
            lqc2 vf5, 0x10(m)
            lqc2 vf6, 0x20(m)
            lqc2 vf7, 0x30(m)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(p)
        }
    return (V4*)p;
}
static inline V4 MulMV(const M4& mm, const V4& v) {
        V4 r(v, 0); V4* pr = &r;
        return *MVa(pr, &mm);
}
static inline V4 MulMV1(const M4& mm, const V4& v) { return MulMV(mm, v); }
static inline V4 MulA(const M4& mm, const V4& v) { return MulMV1(mm, v); }
static inline V4 MulB(const M4& mm, const V4& v) { return MulMV(mm, v); }
inline V4 M4::operator*(const V4& v) const { return MulMV1(*this, v); }
static inline float Recip(float x) { return 1.0f / x; }
struct Viewport {
    char pad0[0x10];
    M4 ortho;
    M4 persp;
    char pad90[0x104 - 0x90];
    unsigned char isOrtho;
    unsigned char pad105;
    unsigned char dirty;
    char pad107[0x110 - 0x107];
    bool IsDirty() const { return dirty; }
};

struct Renderer {
    char pad0[0x68];
    float sx[4];
    float sy[4];
    int scaleIdx;
    char pad8C[0x158 - 0x8C];
    float nearZ;
    float farZ;
    char pad160[0x1B0 - 0x160];
    V4 nearPt;
    V4 farPt;
    char pad1D0[0x1F0 - 0x1D0];
    Viewport vp[(0xA70 - 0x1F0) / 0x110];
    int curVp;
    int projIdx;
    unsigned char dirty;
    char padA79[0xA80 - 0xA79];
    M4 proj[16];
    M4 view;
    M4 viewProj2;
    M4 viewProj;
};

extern "C" void cXViewport_Validate(Viewport* vp);

#pragma inline_depth(10)
#pragma opt_common_subs off
#pragma opt_propagation off

extern "C" void XLib_UpdateCompMat(Renderer* r)
{
    Viewport* vp = &r->vp[r->curVp];
    if ((vp->IsDirty() ^ 1) == 0) {
        r->dirty = 1;
    }
    if (r->dirty) {
        cXViewport_Validate(vp);
        const M4& src = vp->isOrtho ? vp->ortho : vp->persp; M4 cam; cam = src;
        float fx = Recip(r->sx[r->scaleIdx]);
        float fy = Recip(r->sy[r->scaleIdx]);
        Viewport* vp2 = &r->vp[r->curVp]; if (!vp2->isOrtho) {
            r->viewProj = cam * r->view * r->proj[r->projIdx];
            cam.m[0][0] *= fx;
            cam.m[1][1] *= fy;
            r->viewProj2 = cam * r->view * r->proj[r->projIdx];
            r->nearPt = MulB(cam, V4(0.0f, 0.0f, r->nearZ, 1.0f));
            r->farPt = MulA(cam, V4(0.0f, 0.0f, r->farZ, 1.0f));
        } else {
            r->viewProj = cam * r->proj[r->projIdx];
            cam.m[0][0] *= fx;
            cam.m[1][1] *= fy;
            r->viewProj2 = cam * r->proj[r->projIdx];
        }
        r->dirty = 0;
    }
}
static inline void merge_flush_func_0037D9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037D9A0 */

/* merge_units: begin func_0037E0D0 */
#pragma push /* merge_units */
typedef unsigned long u64;
typedef long s64;

typedef struct GsCtx37E0D0 {
    char p0[0x1C];
    unsigned int w;       /* 0x1C */
    unsigned int h;       /* 0x20 */
    char p24[0x8];
    unsigned int psm;     /* 0x2C */
    unsigned int zpsm;    /* 0x30 */
    char p34[0x30];
    unsigned char field;  /* 0x64 */
    char p65[0x2B];
    u64 frame;            /* 0x90 */
    u64 frame2;           /* 0x98 */
    u64 zbuf;             /* 0xA0 */
    u64 xyoffset;         /* 0xA8 */
    char pB0[0x20];
    unsigned char dirty;  /* 0xD0 */
    char pD1[0x27];
    unsigned int fbmsk;   /* 0xF8 */
    unsigned int zmsk;    /* 0xFC */
    char p100[0x2C];
    unsigned int fbp[2];  /* 0x12C */
    unsigned int zbp;     /* 0x134 */
    char p138[0x8];
    int buf;              /* 0x140 */
    char p144[0x94];
    int frames;           /* 0x1D8 */
    char p1DC[0xA70 - 0x1DC];
    int slot;             /* 0xA70 */
    char pA74[0x1058 - 0xA74];
    int dev;              /* 0x1058 */
} GsCtx37E0D0;

typedef struct Slot37E0D0 { char p0[0x110]; } Slot37E0D0;


#define GS_FRAME(fbp, fbw, psm, fbmsk) ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

static inline void GsCtx_SetBufferRegs(GsCtx37E0D0* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64*)0x12001000 >> 13) & 1) << 3;
    }
    c->frame = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->dirty = 1;
}
void XLib_RestoreFrameEnv(GsCtx37E0D0* c)
{
    GsCtx_SetBufferRegs(c, c->w, c->h, c->psm, c->fbp[c->buf], c->fbmsk, c->zpsm, c->zbp, c->zmsk, c->field);
    ((unsigned char*)c)[c->slot * 0x110 + 0x2F6] = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037E0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037E0D0 */

/* merge_units: begin func_0037E210 */
#pragma push /* merge_units */
typedef unsigned long long u64_f4;
typedef struct { char pad[0x90]; u64_f4 frame; u64_f4 frameNoMask; u64_f4 zbuf; u64_f4 xyoffset; char padB0[0x20]; unsigned char dirty; } GsTarget_f4;
void XLib_SetFrameEnv(GsTarget_f4* t, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp,
                   unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx = (2048 - (w >> 1)) << 4;
    unsigned int ofy = (2048 - (h >> 1)) << 4;
    u64_f4 lo;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64_f4*)0x12001000 >> 13) & 1) << 3;
    }
    lo = (u64_f4)fbp | ((u64_f4)(w >> 6) << 16) | ((u64_f4)psm << 24);
    t->frame = ((u64_f4)fbmsk << 32) | lo;
    t->frameNoMask = lo | ((u64_f4)0xFFFFFF << 32);
    t->zbuf = (u64_f4)zbp | ((u64_f4)zpsm << 24) | ((u64_f4)zmsk << 32);
    t->xyoffset = (u64_f4)ofx | ((u64_f4)ofy << 32);
    t->dirty = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037E210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037E210 */

/* merge_units: begin func_0037E310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * xlib.cc
 */

#include "xlib_types.h"

/* Set flag unkA78. */
void XLib_Restore(XlibObj* self) {
    self->unkA78 = 1;
}
static inline void merge_flush_func_0037E310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037E310 */

/* merge_units: begin func_0037E320 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BC200[];
extern char D_00537F80[];
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
void cDmaMan_Reset(void* p);
void XLib_DeferDeleteDmaData(void* p, int a);
void cTexMan_RemoveTexture(void* p, int id, int a);
void cTexMan_dtor(void* p, int flag);
}
struct VO_0037E320 { int pad[4]; virtual void Destroy(int flag); };
struct E1_0037E320 { int id; int pad[3]; unsigned char flag; char pad11[3]; };
struct E2_0037E320 { void* a; int b; void* c; void* d; void* e; char pad[0x24]; };
struct S_0037E320 {
    int flags; char pad4[0xFB0 - 4]; E2_0037E320 e2[2]; char pad1020[0x103C - 0x1020];
    void* p103C; char pad1040[0x1058 - 0x1040]; void* p1058; VO_0037E320* p105C; char pad1060[8];
    E1_0037E320 e1[6];
};
static inline void Free_0037E320(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BC200, line); }
static inline void DelA_0037E320(void* p, int line) { AllocGuard g; cTexMan_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BC200, line); }
static inline void DelV_0037E320(VO_0037E320* p, int line) { AllocGuard g; p->Destroy(-1); cMemMan_Deallocate(0, p, D_004BC200, line); }
extern "C" void Renderer_Teardown(S_0037E320* self)
{
    int i;
    if (self->flags == -1) return;
    cDmaMan_Reset(D_00537F80);
    if (!(self->flags & 8)) {
        for (i = 0; i < 6; i++) {
            E1_0037E320* e = &self->e1[i];
            cTexMan_RemoveTexture(self->p1058, e->id, 0);
            if (e->flag) cTexMan_RemoveTexture(self->p1058, e->id + 1, 0);
        }
    }
    { int j; for (j = 0; j < 2; j++) {
        E2_0037E320* e = &self->e2[j];
        Free_0037E320(e->a, 0x23E);
        Free_0037E320(e->c, 0x242);
        Free_0037E320(e->d, 0x243);
        Free_0037E320(e->e, 0x244);
        e->a = 0;
        e->b = 0;
        e->c = 0;
        e->d = 0;
        e->e = 0;
    }}
    Free_0037E320(self->p103C, 0x24C);
    self->p103C = 0;
    DelA_0037E320(self->p1058, 0x24F);
    self->p1058 = 0;
    DelV_0037E320(self->p105C, 0x251);
    self->p105C = 0;
    XLib_DeferDeleteDmaData(self, 1);
    self->flags = -1;
}
static inline void merge_flush_func_0037E320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037E320 */
