#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); void* xz = this; }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");  return *this; }
} __attribute__((aligned(16)));
struct cMatrix {
    float m[4][4];
    void Init(const cVector& a, const cVector& b, const cVector& c, const cVector& d);
    cVector operator*(const cVector& v) const {
        cVector r; cVector& rr = r; void* xx = &r; void* yy = &r; __int128 t;
        __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(&v) : "memory");
        const cMatrix* pm; __asm__ volatile("" : "=r"(pm) : "0"(this));
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(xx) : "memory");
        __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(&rr), "r"(pm) : "memory");
        return rr;
    }} __attribute__((aligned(16)));
static inline cVector Mm1(const cMatrix& a, const cVector& v) { return a * v; }
static inline cVector Mm2(const cMatrix& a, const cVector& v) { return Mm1(a, v); }
extern "C" {
extern signed char D_0053BB00;
extern cMatrix D_004BC560;
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix* m, const cVector& a, const cVector& b, const cVector& c, const cVector& d);
}
inline void cMatrix::Init(const cVector& a, const cVector& b, const cVector& c, const cVector& d) { const cVector& aa = a; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, aa, b, c, d); }
struct cParticleSpline;
extern "C" void cParticleSpline_ComputeBezierFactors(const cParticleSpline* self, const cVector* controlPoints, cVector* mcp)
{
    cVector cp;
    cVector res;
    if (!D_0053BB00) {
        D_004BC560.Init(cVector(3.0f, -6.0f, 3.0f, 0.0f), cVector(-3.0f, 3.0f, 0.0f, 0.0f), cVector(1.0f, 0.0f, 0.0f, 0.0f), cVector(0.0f, 0.0f, 0.0f, 0.0f));
        D_0053BB00 = 1;
    }
    cp = cVector(controlPoints[0].x, controlPoints[1].x, controlPoints[2].x, 0.0f);
    res = D_004BC560 * cp;
    mcp[0] = cVector(res.x, res.y, res.z, 0.0f);
    cp = cVector(controlPoints[0].y, controlPoints[1].y, controlPoints[2].y, 0.0f);
    res = Mm1(D_004BC560, cp);
    mcp[1] = cVector(res.x, res.y, res.z, 0.0f);
    cp = cVector(controlPoints[0].z, controlPoints[1].z, controlPoints[2].z, 0.0f);
    res = Mm2(D_004BC560, cp);
    mcp[2] = cVector(res.x, res.y, res.z, 0.0f);
}