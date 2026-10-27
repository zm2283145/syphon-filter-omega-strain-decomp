#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* GetCameraPitchAlongSlope: pitch the camera by the slope of the floor under the player along its facing */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V4& operator=(const V4& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    void Set(const V4& o) { const V4* po = &o; void* xx = this; const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V4(const V4& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
} __attribute__((aligned(16)));
extern "C" {
V4* cVector_ctor_cVectorR(V4* d, const V4* s);
V4* cVector_VectorProjectOnPlane(V4* a, const V4* b);
float Libc_Atan2f(float y, float x);
}
// VU0 quaternion rotation of v by q in place (COP2), not expressible in C
static inline void QRot(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
// VU0 macro-mode vector length (COP2), not expressible in C
static inline float Len(const V4* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline V4 Rotate(V4 v, V4* q) { QRot(&v, q); return v; }
static inline V4 Flat(V4 v) { v.w = 0.0f; return v; }
static inline float LenXY(V4 v) { v.z = 0.0f; return Len(&v); }
static inline V4* Reject(const V4& v, const V4& nn) { V4 t; return cVector_VectorProjectOnPlane(cVector_ctor_cVectorR(&t, &v), &nn); }
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual bool GetFloorNormal(V4* n); /* 0xF8 */
};
extern "C" unsigned char GetCameraPitchAlongSlope(float* out, V4* q, Obj* o, float base);
unsigned char GetCameraPitchAlongSlope(float* out, V4* q, Obj* o, float base)
{
    bool ok;
    unsigned char res;
    V4 n;
    if (o->GetFloorNormal(&n)) {
        V4 fwd(0.0f, 1.0f, 0.0f, 0.0f);
        V4 dir;
        V4 r;
        V4 flat;
        V4 rp = fwd;
        /* dir copy: lq as volatile asm (quadword load, as retail), sq from C */
        { V4* pr = &rp; QRot(pr, q); V4* pd = &dir; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(pr)); *(__int128*)pd = t; }
        V4 lp;
        V4 fp(n);
        { V4* pf = (V4*)(int)&fp; pf->w = 0.0f; flat = *pf; }
        V4 t;
        cVector_ctor_cVectorR(&r, cVector_VectorProjectOnPlane(cVector_ctor_cVectorR(&t, &dir), &flat));
        lp.Set(r);
        lp.z = 0.0f;
        *out = Libc_Atan2f(r.z, Len(&lp));
        if (!(*out <= 0.0f)) *out = *out * 0.5f;
        else *out = *out * 0.8f;
        *out = *out + base;
        ok = 1;
    } else {
    *out = base;
    ok = 0;
    }
    res = ok;
    return res;
}
