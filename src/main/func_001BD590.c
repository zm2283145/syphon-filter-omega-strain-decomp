// cEulerAngle_T<1,0,2>::cEulerAngle_T(const cMatrix&). Rotation matrices are built by inline axis/angle
// constructors (enum tag selects the axis) so no by-value return temporaries are created.
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

extern unsigned char D_0049E9A0[16];
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void G4(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V(const V& o) { const void* s = &o; void* d = this; G1(d, s); } } __attribute__((aligned(16)));
struct M;
extern "C" {
float Libc_Atan2f(float y, float x);
float SIN(float);
float COS(float);
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
}
static inline void MulRot(M* out, const M* m, const M* rot)
{
    asm volatile {
        lqc2 vf8, 0x0(rot)
        lqc2 vf9, 0x10(rot)
        lqc2 vf10, 0x20(rot)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddz.xyzw vf12, vf6, vf8z
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddz.xyzw vf13, vf6, vf9z
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddz.xyzw vf14, vf6, vf10z
        vmove.xyzw vf15, vf7
        sqc2 vf12, 0x0(out)
        sqc2 vf13, 0x10(out)
        sqc2 vf14, 0x20(out)
        sqc2 vf15, 0x30(out)
    }
}
struct M {
    float m[4][4];
    enum XT { X_AXIS }; enum ZT { Z_AXIS };
    M(XT, float a) { float s = SIN(a); float c = COS(a); cMatrix_Set_ColumnMajorForm(this, 1.0f, 0.0f, 0.0f, 0.0f, c, -s, 0.0f, s, c); }
    M(ZT, float a) { float s = SIN(a); float c = COS(a); cMatrix_Set_ColumnMajorForm(this, c, -s, 0.0f, s, c, 0.0f, 0.0f, 0.0f, 1.0f); }
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M& operator*=(const M& r) { MulRot(this, this, &r); return *this; }
    M operator*(const M& o) const { return M(*this) *= o; }
} __attribute__((aligned(16)));
struct E { float x, y, z; unsigned int pad; };

static inline float Sq(float v) { return v * v; }
static inline float Sqrt(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }

extern "C" E* cEulerAngle_T_1_2_ctor_cMatrixR(E* self, const M& rotMatrix)
{
    float angle1;
    float angle2;
    V axis0(*(const V*)rotMatrix.m[1]);
    angle2 = Libc_Atan2f(-axis0.x, axis0.y);
    if (D_0049E9A0[0]) angle2 = -angle2;
    angle1 = Libc_Atan2f(axis0.z, Sqrt(Sq(axis0.y) + Sq(axis0.x)));
    if (D_0049E9A0[0]) angle1 = -angle1;
    {
        M reverse21Matrix = M(M::X_AXIS, -angle1) * M(M::Z_AXIS, -angle2);
        M reversedMatrix = reverse21Matrix * rotMatrix;
        V axis1(*(const V*)reversedMatrix.m[0]);
        float a = Libc_Atan2f(-axis1.z, axis1.x);
        if (D_0049E9A0[0]) a = -a;
        self->y = a;
    }
    self->x = angle1;
    self->z = angle2;
    return self;
}
