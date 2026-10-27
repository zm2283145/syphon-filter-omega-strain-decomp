#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cHuman::HandleBlast: work out where a blast came from relative to the body; a blast from
   behind keeps the given death type, one from the front bumps it to the next type and turns the
   target heading towards the blast. */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix { cVector r[4]; cMatrix() {} };
struct cEulerAngle_T { float x, y, z; cEulerAngle_T() { x = 0.0f; y = 0.0f; z = 0.0f; } };
struct cTargetZRotationStackSlot { int id; float angle; };
struct cHuman {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    VPAD8(e) VPAD4(f) virtual cMatrix GetMatrix() const;
    char pad4[0x3030 - 4];
    char motionParams[0x58];        /* 0x3030 */
    char zRotationStack[0x14];      /* 0x3088 */
};
extern "C" {
int GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(const cMatrix& m, const cVector& p, cEulerAngle_T* out);
float Libc_Atan2f(float y, float x);
double SoftFloat_FloatToDouble(float f);
cTargetZRotationStackSlot* cArray_cTargetZRotationStackSlot_opIndex(void* a, int i);
void cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(void* p, float d);
unsigned char cHuman_HandleBlast(cHuman* self, const cVector* blastOrigin, unsigned char deathTypeFromBehind);
}
/* abs.s: no C equivalent */
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Atan2(float a, float b) { return Libc_Atan2f(a, b); }
static inline float ZAngle(const cMatrix& m)
{
    cVector x = m.r[0];
    cVector y = m.r[1];
    float yz = y.z;
    if (x.z < yz)
        return Atan2(x.y, x.x);
    return Libc_Atan2f(-y.x, y.y);
}

unsigned char cHuman_HandleBlast(cHuman* self, const cVector* blastOrigin, unsigned char deathTypeFromBehind)
{
    cEulerAngle_T result;
    if (blastOrigin) {
        cMatrix mat = self->GetMatrix();
        mat.r[3] = self->GetTargetPosition(-1);
        GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(mat, *blastOrigin, &result);
    }
    /* fabsf(z) > 1.57 in double; the float-to-double helper is named explicitly (MW calls it fptodp) */
    if (SoftFloat_FloatToDouble(AbsZ(result.z)) > 1.57) {
        if (result.z > 0.0f)
            result.z -= 3.14f;
        else
            result.z += 3.14f;
    } else {
        deathTypeFromBehind = deathTypeFromBehind + 1;
    }
    if (AbsZ(result.z) > 0.3f) {
        float baseZAngle = ZAngle(self->GetMatrix()); baseZAngle += result.z;
        cArray_cTargetZRotationStackSlot_opIndex(self->zRotationStack, *(int*)(self->zRotationStack + 16))->angle = baseZAngle;
        cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(self->motionParams, 0.5f);
    }
    return deathTypeFromBehind;
}
