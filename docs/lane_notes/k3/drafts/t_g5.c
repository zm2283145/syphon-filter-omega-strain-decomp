#include "types.h"

#pragma cplusplus on
#pragma inline_depth(8)
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { void* xx = this; __int128 q; const cVector* ps = &o; cVector* pd = this; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector& operator=(const cVector& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
} __attribute__((aligned(16)));
struct cMatrix {
    float m[4][4];
    cMatrix() {}
    cMatrix(const cMatrix& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 qa, qb; cMatrix* d = this; const cMatrix* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    void Set4(int i, float a, float b, float c, float d) { m[i][0] = a; m[i][1] = b; m[i][2] = c; m[i][3] = d; }
    void SetRow(int i, const cVector& v) { const cVector* p = &v; Set4(i, p->x, p->y, p->z, p->w); }
    cVector& Row(int i) { return *(cVector*)m[i]; }
    void SetZAxis(const cVector& v) { float y = v.y, z = v.z, w = v.w, x = v.x; m[2][0] = x; m[2][1] = y; m[2][2] = z; m[2][3] = w; }
    void SZ1(const cVector& v) { SetZAxis(v); }
} __attribute__((aligned(16)));
struct cMan;
extern "C" void cMan_GetGunBarrelMatrix_WithoutFlippingAxes(cMan* m, cMatrix* out, int hand);

extern "C" cMatrix cMan_GetGunBarrelMatrix(cMan* self, int hand)
{
    cMatrix gunMat_WorldSpace;
    cMan_GetGunBarrelMatrix_WithoutFlippingAxes(self, &gunMat_WorldSpace, hand);
    cVector x = gunMat_WorldSpace.Row(0);
    cVector y = gunMat_WorldSpace.Row(1);
    cVector z = gunMat_WorldSpace.Row(2);
    { float w0 = z.w, z0 = z.z, y0 = z.y, x0 = z.x; gunMat_WorldSpace.m[0][3] = w0; gunMat_WorldSpace.m[0][2] = z0; gunMat_WorldSpace.m[0][1] = y0; gunMat_WorldSpace.m[0][0] = x0; }
    gunMat_WorldSpace.SetRow(1, x);
    gunMat_WorldSpace.SZ1(y);
    return gunMat_WorldSpace;
}