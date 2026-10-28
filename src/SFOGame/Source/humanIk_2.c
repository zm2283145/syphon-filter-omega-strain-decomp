/*
 * SFOGame/Source/humanIk: 4 files, 001D3A60-001D3AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D3A60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 func_001D3A60(V4* b) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_001D3A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3A60 */

/* merge_units: begin func_001D3A90 */
#pragma push /* merge_units */
/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; Vec4 c; } Vec4x3;

/* Copies three consecutive vectors out to three destinations. */
void func_001D3A90(Vec4x3* src, Vec4* a, Vec4* b, Vec4* c)
{
    *a = src->a;
    *b = src->b;
    *c = src->c;
}
static inline void merge_flush_func_001D3A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3A90 */

/* merge_units: begin func_001D3AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_001D3AC0(char* self) {
    return self + 32;
}
static inline void merge_flush_func_001D3AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3AC0 */

/* merge_units: begin func_001D3AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vu0_ops.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma peephole on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float vx, float vy, float vz, float vw) { cVector* refThis = this; x = vx; y = vy; z = vz; w = vw; }
    cVector(const cVector& source) { cVector* refThis = this; u_long128 reg; const cVector* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cVector& Normalize()
    {
        cVector* refThis = this;
        asm volatile {
            lqc2 vf1, 0x0(refThis)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(refThis)
        }
        return *this;
    }
    cVector GetNormalized() const { return cVector(*this).Normalize(); }
    cVector Cross(const cVector& vector) const
    {
        cVector result;
        cVector* r = &result;
        const cVector* a = this;
        const cVector* b = &vector;
        asm volatile {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(b)
            vopmula.xyz ACC, vf1, vf2
            vopmsub.xyz vf3, vf2, vf1
            vsubw.w vf3, vf0, vf0w
            sqc2 vf3, 0x0(r)
        }
        return result;
    }
    unsigned char IsZero() const
    {
        int k, f;
        int r = 0;
        const cVector* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
    unsigned char IsZero2() const
    {
        int k, f;
        int r;
        const cVector* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
} __attribute__((aligned(16)));

class cMatrix {
public:
    float m[4][4];
    cMatrix& Set(const cVector& a, const cVector& b, const cVector& c, const cVector& t);
};

extern "C" {
float Math_Fabs(float);
void cMatrix_SetAxes(cMatrix*, const cVector*, const cVector*, const cVector*);
void cMatrix_SetTranslation(cMatrix*, const cVector*);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix*, const cVector*, const cVector*, const cVector*, const cVector*);
cVector* cVector_ctor_cVectorR(cVector*, const cVector*);
void cVector_Cross(cVector*, const cVector*, const cVector*);
float cVector_Z_void(const cVector*);
cVector* cVector_Normalize_void(cVector*);
void cVector_GetNormalized_void(cVector*, const cVector*);
cVector* cVector_ctor_float_float_float_float(cVector*, float, float, float, float);
extern cVector D_00497F20;
extern cVector D_00497F30;
extern char D_004E1DA0;
extern char D_004E1DA8;
}

inline cMatrix& cMatrix::Set(const cVector& a, const cVector& b, const cVector& c, const cVector& t) { cMatrix_SetAxes(this, &a, &b, &c); cMatrix_SetTranslation(this, &t); return *this; }

static inline cMatrix& FromDir(cMatrix* m, const cVector& lookAtDir)
{
    cVector forwardDir;
    cVector rightDir;
    cVector upDir;
    cVector tmp;
    cVector tr;
    const cVector* refDir;
    if (!D_004E1DA0) {
        float z0 = 0.0f;
        cVector_ctor_float_float_float_float(&D_00497F20, 1.0f, z0, z0, z0);
        D_004E1DA0 = 1;
    }
    if (!D_004E1DA8) {
        float z1 = 0.0f;
        cVector_ctor_float_float_float_float(&D_00497F30, z1, z1, 1.0f, z1);
        D_004E1DA8 = 1;
    }
    if (Math_Fabs(cVector_Z_void(&lookAtDir)) < 0.707f) {
        refDir = &D_00497F30;
    } else {
        asm volatile { .set reorder }
        refDir = &D_00497F20;
    }
    cVector_GetNormalized_void(&forwardDir, &lookAtDir);
    cVector_Cross(&tmp, &lookAtDir, refDir);
    cVector_ctor_cVectorR(&rightDir, cVector_Normalize_void(&tmp));
    cVector_Cross(&upDir, &rightDir, &forwardDir);
    float z2 = 0.0f;
    cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &rightDir, &forwardDir, &upDir, cVector_ctor_float_float_float_float(&tr, z2, z2, z2, 1.0f));
    return *m;
}

extern "C" cMatrix& cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(cMatrix* self, const cVector& lookAtDir, const cVector& iUpDir)
{
    cVector lookAtDir_Cross_UpDir = lookAtDir.Cross(iUpDir);
    if (!lookAtDir_Cross_UpDir.IsZero()) {
        cVector forwardDir = lookAtDir.GetNormalized();
        cVector rightDir = lookAtDir_Cross_UpDir.Normalize();
        cVector upDir = rightDir.Cross(forwardDir);
        self->Set(rightDir, forwardDir, upDir, cVector(0.0f, 0.0f, 0.0f, 1.0f));
        return *self;
    }
    if (!lookAtDir.IsZero2()) {
        return FromDir(self, lookAtDir);
    }
    VU0_UnitMatrix(self);
    return *self;
}
static inline void merge_flush_func_001D3AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3AD0 */
