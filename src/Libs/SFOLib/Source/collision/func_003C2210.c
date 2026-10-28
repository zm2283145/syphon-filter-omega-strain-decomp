/* cRayMatrix::cRayMatrix(const cVector& losStartPoint, const cVector& losVector, float losRadius) (003C2210).
 * Inline-local stack order follows inline nesting depth: MakeAxes/Invert are reached through 3-deep inline wrappers.
 * The void* xx = this locals keep retail's dead addius; function-local statics are written as explicit guards. */
#pragma cplusplus on
#pragma inline_depth(4)
#pragma always_inline on
#include "types.h"

struct cMatrix;
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d);
    cVector(float a, float b, float c) : x(a), y(b), z(c), w(0.0f) {}
    cVector(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); }
    cVector& Asg0(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& operator=(const cVector& o)
    {
        void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory");
        return *this;
    }
    cVector operator+(const cVector& o) const
    {
        cVector r;
        __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    cVector operator*(float s) const
    {
        cVector r;
        __int128 t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=r"(t) : "r"(&r), "r"(this), "f"(s) : "memory");
        return r;
    }
    float Length() const
    {
        float len;
        __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2 %0, vf4" : "=r"(len) : "r"(this) : "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct cLineSegment {
    cVector p[2];
};

struct cMatrix {
    cVector row[4];
};

struct cRayMatrix {
    cMatrix m;
    cLineSegment lineSegment;
};

extern "C" {
extern signed char D_00542CE8;
extern signed char D_00542CF0;
extern signed char D_00542CF8;
extern cVector D_004BD070;
extern cVector D_004BD080;
extern cVector D_004BD090;
cVector* cVector_ctor_float_float_float_float(cVector*, float, float, float, float);
cVector* cVector_ctor_cVectorR(cVector*, const cVector*);
void cVector_Cross(cVector* ret, const cVector* a, const cVector* b);
unsigned char cVector_IsZeroXYZ(const cVector*);
void cVector_GetNormalized_void(cVector* ret, const cVector*);
cVector* cVector_Normalize_void(cVector*);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix*, const cVector*, const cVector*, const cVector*, const cVector*);
void cMatrix_MakeLookAtMatrix_cVectorR(cMatrix*, const cVector*);
void cMatrix_SetUnit(cMatrix*);
void cMatrix_InvertRot(cMatrix*);
unsigned char cMatrix_IsZeroTranslation(const cMatrix*);
const cVector* func_00133EC0(const cMatrix*);
void cVector_NegateXYZ(cVector*);
void cVector_Rotate_cMatrixR(cVector*, const cMatrix*);
void cMatrix_SetTranslation(cMatrix*, const cVector*);
void cMatrix_SetAxes(cMatrix*, const cVector*, const cVector*, const cVector*);
}

#define worldX D_004BD070
#define worldY D_004BD080
#define worldZ D_004BD090
static inline float Abs(float f) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "=f"(r) : "f"(f)); return r; }
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline void Construct(cLineSegment& ls, const cVector& a, const cVector& b) { cVector* p = ls.p; do { ++p; } while (p != ls.p + 2); ls.p[0].Asg0(a); ls.p[1].Asg0(b); }
static inline void MakeAxes(cMatrix* m, const cVector& dir, const cVector& up)
{
    cVector side;
    cVector_Cross(&side, &dir, &up);
    if (!cVector_IsZeroXYZ(&side)) {
        cVector fwd; cVector x; cVector y; cVector t;
        cVector_GetNormalized_void(&fwd, &dir);
        cVector_ctor_cVectorR(&x, cVector_Normalize_void(&side));
        cVector_Cross(&y, &x, &fwd);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &x, &fwd, &y, cVector_ctor_float_float_float_float(&t, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, &dir);
    } else {
        cMatrix_SetUnit(m);
    }
}
static inline void Invert(cMatrix* m)
{
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        cVector t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
static inline void MakeAxes2(cMatrix* m, const cVector& dir, const cVector& up) { MakeAxes(m, dir, up); }
static inline void Invert2(cMatrix* m) { Invert(m); }
static inline void MakeAxes3(cMatrix* m, const cVector& dir, const cVector& up) { MakeAxes2(m, dir, up); }
static inline void Invert3(cMatrix* m) { Invert2(m); }
static inline void SetT0(cMatrix* m, const cVector& t) { m->row[3].Asg0(t); }
static inline cVector AsPoint(cVector v) { cVector* p = &v; p->w = 1.0f; return *p; }

extern "C" cRayMatrix* cRayMatrix_ctor_cVectorR_cVectorR_float(cRayMatrix* self, const cVector& losStartPoint, const cVector& losVector, float losRadius)
{
    Construct(self->lineSegment, losStartPoint, losStartPoint + losVector);
    {
        const cVector* crossVector;
        float absLosX, absLosY, absLosZ, minComponent;
        if (!D_00542CE8) { worldX.x = 1.0f; worldX.y = 0.0f; worldX.z = 0.0f; worldX.w = 0.0f; D_00542CE8 = 1; }
        if (!D_00542CF0) { worldY.x = 0.0f; worldY.y = 1.0f; worldY.z = 0.0f; worldY.w = 0.0f; D_00542CF0 = 1; }
        if (!D_00542CF8) { worldZ.x = 0.0f; worldZ.y = 0.0f; worldZ.z = 1.0f; worldZ.w = 0.0f; D_00542CF8 = 1; }
        absLosX = Abs(losVector.x);
        absLosY = Abs(losVector.y);
        absLosZ = Abs(losVector.z);
        minComponent = Min(Min(absLosX, absLosY), absLosZ);
        if (minComponent == absLosZ) {
            crossVector = &worldZ;
        } else if (minComponent == absLosY) {
            crossVector = &worldY;
        } else {
            crossVector = &worldX;
        }
        MakeAxes3(&self->m, losVector, *crossVector);
    }
    {
        cVector halfLosVector = losVector * 0.5f;
        cVector trans = AsPoint(losStartPoint + halfLosVector);
        SetT0(&self->m, trans);
        Invert3(&self->m);
        {
            float invXZScale = 1.0f / losRadius;
            float yScale = 0.0f;
            float invYScale;
            cVector xAxis, yAxis, zAxis, trans;
            yScale = halfLosVector.Length();
            invYScale = 1.0f / yScale;
            xAxis = self->m.row[0];
            yAxis = self->m.row[1];
            zAxis = self->m.row[2];
            trans = self->m.row[3];
            xAxis.x *= invXZScale;
            yAxis.x *= invXZScale;
            zAxis.x *= invXZScale;
            trans.x *= invXZScale;
            xAxis.y *= invYScale;
            yAxis.y *= invYScale;
            zAxis.y *= invYScale;
            trans.y *= invYScale;
            xAxis.z *= invXZScale;
            yAxis.z *= invXZScale;
            zAxis.z *= invXZScale;
            trans.z *= invXZScale;
            cMatrix_SetAxes(&self->m, &xAxis, &yAxis, &zAxis);
            cMatrix_SetTranslation(&self->m, &trans);
        }
    }
    return self;
}


