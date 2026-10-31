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




