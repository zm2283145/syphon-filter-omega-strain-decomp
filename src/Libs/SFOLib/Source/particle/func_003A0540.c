/* cParticleSpline::NextFrame (particle.cc). Rebuilt on k5's nf_q.c; matched by lane P1L.
 * The VU0 macro-mode blocks (lqc2/sqc2/vopmula/vrsqrt/cfc2 ...) and the 128-bit lq/sq vector
 * copies are inline asm because C cannot express them. Calls that the original inline chain left
 * out of line (inline_depth overflow) are written as direct calls to the out-of-line functions. */
#pragma cplusplus on
#include "types.h"

#pragma inline_depth(6)
typedef __int128 u_long128;
struct cMatrix;
enum E6 { E6v };
enum E8 { E8v };
struct cVector;
struct VS { float f[4]; } __attribute__((aligned(16)));
struct MS { float f[16]; } __attribute__((aligned(16)));
struct cParticle;
struct cParticleBase;
struct cParticleSpline;
extern "C" {
cVector* cVector_ctor_cVectorR(cVector* self, const cVector* o);
cVector* cVector_ctor_float_float_float_float(cVector* self, float x, float y, float z, float w);
cVector* cVector_Rotate_cMatrixR(cVector* self, const cMatrix* m);
cVector cVector_Cross(const cVector* self, const cVector* b);
int cVector_IsZeroXYZ(const cVector* self);
cVector cVector_GetNormalized_void(const cVector* self);
cVector* cVector_Normalize_void(cVector* self);
void cMatrix_GetInverseRot(cMatrix* ret, const cMatrix* self);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix* self, const cVector* a, const cVector* b, const cVector* c, const cVector* d);
void cMatrix_MakeLookAtMatrix_cVectorR(cMatrix* self, const cVector* d);
void cMatrix_SetUnit(cMatrix* self);
void cParticleBase_NextFrame(cParticleBase* self, cParticle* system, const cMatrix* matrix, float elapsedTime, const cVector* localWind);
void cParticleSpline_SplineComputeForceNormal(cParticleSpline* self, cVector* force, const cVector* pos, const cVector* springPos, float a, float b);
void cParticleSpline_ComputeBezierFactors(const cParticleSpline* self, const cVector* controlPoints, cVector* mcp);
void cParticleSpline_NextFrame(cParticleSpline* self, cParticle* system, const cMatrix& matrix, float elapsedTime, const cVector* localWind);
}
struct cVector {
    float x, y, z, w;
    cVector() {}
    inline cVector(const cVector& source) { cVector& refThis = *this; u_long128 reg; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    inline cVector(const cVector& source, int) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    inline cVector(const cVector& source, E6) { u_long128 reg; cVector& refThis = *this; const cVector* ps = &source; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(ps) : "memory"); }
    inline cVector(const cVector& source, E8) { u_long128 reg; const cVector* ps = &source; cVector& refThis = *this; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(ps) : "memory"); }
    inline cVector(const cVector& source, unsigned char) { u_long128 reg; cVector& refThis = *this; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    inline cVector Cr3(const cVector& b) const;
    inline cVector& AsX(const cVector& source) { cVector& refThis = *this; u_long128 reg; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    inline void SetX(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    inline cVector& operator=(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    inline cVector& Assign(const cVector& source) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    inline cVector operator+(const cVector& b) const {
        cVector r; cVector* o = &r; const cVector* a = this; const cVector* pb = &b;
        asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) }
        cVector& rr = r; return rr;
    }
    friend inline cVector operator*(const cVector& v, float s) {
        cVector r;
        u_long128 t = 0; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(&v), "r"(&r), "f"(s) : "memory");
        cVector& rr = r; return rr;
    }
    inline cVector& operator+=(const cVector& b) {
        cVector* d = this; const cVector* a = this; const cVector* pb = &b;
        asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) }
        return *this;
    }
    inline cVector& operator*=(float s) {
        cVector* d = this; const cVector* a = this; u_long128 t = 0; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2 %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(d), "r"(a), "f"(s) : "memory");
        return *this;
    }
    inline cVector& NormalizeI() {
        cVector* a = this;
        asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(a) }
        return *this;
    }
    inline cVector GetNormalizedI() const { VS t; return cVector(*cVector_Normalize_void(cVector_ctor_cVectorR((cVector*)&t, this)), (unsigned char)0); }
    friend inline cVector NF3(const cVector& v) { return v.GetNormalizedI(); }
    inline cVector operator^(const cVector& b) const {
        cVector r; cVector* o = &r; const cVector* a = this; const cVector* pb = &b;
        asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(o) }
        return cVector(r, 0);
    }
    inline unsigned char IsZero() const {
        int z = 0; int t; int f; int res; const cVector* a = this;
        asm {
            lqc2 vf1, 0x0(a)
            vaddx.xyz vf1, vf1, vf0x
            and res, zero, zero
            ori t, zero, 0xe
            vnop
            vnop
            vnop
            vnop
            cfc2 f, vi17
            bne t, f, skip
            ori res, zero, 1
        skip:
        }
        return res;
    }
    inline cVector& ApplyRot(const cMatrix& m);
    inline cVector& ApplyRotS(const cMatrix& m) { cVector* a = this; const cMatrix* pm = &m; asm { lqc2 vf8, 0x0(a); lqc2 vf4, 0x0(pm); lqc2 vf5, 0x10(pm); lqc2 vf6, 0x20(pm); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(a) } return *a; }
    inline cVector& InvRot(const cMatrix& m);
} __attribute__((aligned(16)));

struct cMatrix {
    float m[4][4];
} __attribute__((aligned(16)));

inline cVector& cVector::ApplyRot(const cMatrix& m) {
    cVector* b = this; const cMatrix* pm = &m; cVector* a = this;
    asm { lqc2 vf8, 0x0(a); lqc2 vf4, 0x0(pm); lqc2 vf5, 0x10(pm); lqc2 vf6, 0x20(pm); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(b) }
    return *this;
}
static inline cVector& IR1(cVector& v, const cMatrix& m) { MS t; cMatrix_GetInverseRot((cMatrix*)&t, &m); return *cVector_Rotate_cMatrixR(&v, (cMatrix*)&t); }
static inline cVector& IR2(cVector& v, const cMatrix& m) { return IR1(v, m); }
inline cVector& cVector::InvRot(const cMatrix& m) { return IR2(*this, m); }
inline cVector operator*(const cMatrix& m, const cVector& v) { return cVector(cVector(v, E8v).ApplyRotS(m), (unsigned char)0); }

struct cSplineDefinition {
    char pad0[0x68];
    float windScale;
    float k;
    float friction;
    char pad74[0xA40 - 0x74];
    cVector points[3];
};
struct cParticleBase {
public:
    char pad0[0x10];
    cMatrix matrix;
    char pad50[0x74 - 0x50];
    void* parent;
    char pad78[0x90 - 0x78];
    inline void NextFrame(cParticle* system, const cMatrix& matrix, float elapsedTime, const cVector* localWind) { cParticleBase_NextFrame(this, system, &matrix, elapsedTime, localWind); }
};
struct cParticleSpline : public cParticleBase {
public:
    cVector vuParamBlock[7];
    cSplineDefinition* definition;
    cVector springPos[3];
    cVector springVel[3];
    float springDistance[3];
    void NextFrame(cParticle* system, const cMatrix& matrix, float elapsedTime, const cVector* localWind);
    inline void SplineComputeForceNormal(cVector& force, const cVector& pos, const cVector& springPos, float a, float b) { cParticleSpline_SplineComputeForceNormal(this, &force, &pos, &springPos, a, b); }
    inline void ComputeBezierFactors(const cVector* controlPoints, cVector* mcp) const { cParticleSpline_ComputeBezierFactors(this, controlPoints, mcp); }
};
extern "C" cVector D_004BC550;

static inline void BF2(cMatrix& tm, const cVector& d)
{
    cVector side = cVector_Cross(&d, &D_004BC550);
    if (!cVector_IsZeroXYZ(&side)) {
        cVector up = cVector_GetNormalized_void(&d); VS rs; cVector_ctor_cVectorR((cVector*)&rs, cVector_Normalize_void(&side));
        cVector c = cVector_Cross((cVector*)&rs, &up); VS one;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&tm, (cVector*)&rs, &up, &c, cVector_ctor_float_float_float_float((cVector*)&one, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&d)) {
        cMatrix_MakeLookAtMatrix_cVectorR(&tm, &d);
    } else {
        cMatrix_SetUnit(&tm);
    }
}
static inline void BF3(cMatrix& tm, const cVector& d) { BF2(tm, d); }
static inline void BF4(cMatrix& tm, const cVector& d) { BF3(tm, d); }
static inline void BF5(cMatrix& tm, const cVector& d) { BF4(tm, d); }
static inline void BF6(cMatrix& tm, const cVector& d) { BF5(tm, d); }
static inline void BuildFrame(cMatrix& tm, const cVector& d) { BF6(tm, d); }
static inline cVector NA(const cVector& a, const cVector& b, const cVector& t) { cVector r; cVector* o = &r; const cVector* pa = &a; const cVector* pb = &b; asm { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } const_cast<cVector&>(t).SetX(r); const cVector& tt = t; return cVector(cVector(tt, E8v).NormalizeI(), (unsigned char)0); }
static inline cVector SubT(const cVector& v, const cVector& b, const cVector& t) { const void* xx = &t; const cVector& tt = t; cVector& w = const_cast<cVector&>(t); w = v; cVector r; cVector* o = &r; const cVector* pb = &b; const cVector* a = &tt; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } cVector& rr = r; return rr; }
static inline cVector SubT2(const cVector& v, const cVector& b, const cVector& t) { const void* xx = &t; const cVector& tt = t; cVector& w = const_cast<cVector&>(t); w = v; cVector r; cVector* o = &r; const cVector* pb = &b; const cVector* a = &tt; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } return cVector(r, (unsigned char)0); }

static inline void CrIn(cVector& r, const cVector& s, const cVector& b) { cVector* o = &r; const cVector* a = &s; const cVector* pb = &b; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(o) } }
inline cVector cVector::Cr3(const cVector& b) const { cVector r; CrIn(r, *this, b); cVector& rr = r; return rr; }
static inline cVector MulT(const cMatrix& m, const cVector& v) { const cVector& vv = v; return cVector(cVector(vv, E6v).ApplyRotS(m), (unsigned char)0); }
static inline cVector SubS(const cVector& v, const cVector& b) { cVector r; cVector* o = &r; const cVector* a = &v; const cVector* pb = &b; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } return cVector(r, (unsigned char)0); }
extern "C" void cParticleSpline_NextFrame(cParticleSpline* self, cParticle* system, const cMatrix& matrix, float elapsedTime, const cVector* localWind)
{
    float splineDistance;
    float k;
    float friction;
    cMatrix tm;
    cVector force;
    cVector wind;
    cVector windPos;
    cVector splineForce;
    int i;

    self->cParticleBase::NextFrame(system, matrix, elapsedTime, localWind);
    if (localWind == 0) return;
    if (self->definition->windScale <= 0.01f) return;
    splineDistance = (self->springDistance[0] + self->springDistance[1] + self->springDistance[2]) / 3.0f;
    k = self->definition->k * splineDistance;
    friction = self->definition->friction;
    wind = *localWind;
    wind = wind.InvRot(matrix) * self->definition->windScale * splineDistance;

    splineForce = self->definition->points[0];
    if (self->parent != 0) {
        splineForce.ApplyRot(self->matrix);
    }
    windPos = NA(splineForce, wind, cVector()) * self->springDistance[0];
    self->SplineComputeForceNormal(force, windPos, self->springPos[0], 0.0f, k);
    self->springVel[0] += force;
    cVector splineDelta = SubT(self->definition->points[1], self->definition->points[0], cVector());
    if ((splineDelta ^ D_004BC550).IsZero()) {
        splineForce.Assign(D_004BC550);
    } else {
        BuildFrame(tm, splineDelta);
        splineForce = tm * self->springPos[0];
    }

    windPos = self->springPos[0] + NF3(splineForce + wind) * self->springDistance[1];
    self->SplineComputeForceNormal(force, windPos, self->springPos[1], 0.0f, k);
    self->springVel[1] += force;
    splineDelta.AsX(SubT2(self->definition->points[2], self->definition->points[1], cVector()));
    if (splineDelta.Cr3(D_004BC550).IsZero()) {
        splineForce.Assign(D_004BC550);
    } else {
        BuildFrame(tm, splineDelta);
        splineForce = MulT(tm, SubS(self->springPos[1], self->springPos[0]));
    }

    windPos = self->springPos[1] + NF3(splineForce + wind) * self->springDistance[2];
    self->SplineComputeForceNormal(force, windPos, self->springPos[2], 0.0f, k);
    self->springVel[2] += force;

    for (i = 0; i < 3; i++) {
        self->springPos[i] += self->springVel[i];
        self->springVel[i] *= friction;
    }
    self->ComputeBezierFactors(self->springPos, self->vuParamBlock + 4);
}
