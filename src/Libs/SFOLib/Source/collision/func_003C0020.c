/* func_003C0020: cCollisionFace unit-normal update (collision.cc; no prototype counterpart).
 * unitNormal = normalize(((v1 - v0) ^ (v2 - v0)) * sign(face->x)), where face is the model face the
 * face locator points at and sign is func_003C0180 (+1/-1). Matched by lane X3.
 * The VU0 macro-mode blocks (lqc2/sqc2/vsub/vopmula/vrsqrt, mfc1+qmtc2) and the 128-bit lq/sq vector
 * copies are inline asm because C cannot express them. The GCC-style volatile asm also reproduces
 * retail's per-site address recomputation (MW drops its address CSE around such statements). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"

typedef __int128 u_long128;
struct cCollisionModel;
struct cCollisionModel_FaceLocator { char pad[0x10]; };
struct cCollisionModel_Face { float x; };
struct cVector;
extern "C" {
cCollisionModel* cCollisionModel_FaceLocator_ParentModel(const cCollisionModel_FaceLocator* l);
int cCollisionModel_FaceLocator_FaceIndex(const cCollisionModel_FaceLocator* l);
cCollisionModel_Face* cCollisionModel_GetFace(cCollisionModel* m, int i);
float func_003C0180(float x);
}

/* VU0 helpers one inline level below the operators (by-value result: `V r; Helper(&r, ...); return r;`).
 * Parameter order follows retail's argument set-up order (inline arguments are evaluated right to left). */
static inline void SubV(const cVector* pb, cVector* o, const cVector* a) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(o), "r"(a), "r"(pb) : "memory"); }
static inline void CrossV(cVector* o, const cVector* a, const cVector* pb) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(o), "r"(a), "r"(pb) : "memory"); }
static inline void MulV(const cVector* a, cVector* o, float s) { u_long128 t = 0; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(a), "r"(o), "f"(s) : "memory"); }

struct cVector {
    float x, y, z, w;
    cVector() {}
    /* quadword copy; the dead xx reproduces retail's unused destination addiu */
    inline cVector(const cVector& source) { void* xx = this; u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&source) : "memory"); }
    inline cVector& operator=(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    inline cVector operator-(const cVector& b) const { cVector r; SubV(&b, &r, this); return r; }
    inline cVector operator^(const cVector& b) const { cVector r; CrossV(&r, this, &b); return r; }
    inline cVector operator*(float s) const { cVector r; MulV(this, &r, s); return r; }
    /* in-place normalize (xyz); the unused pointer local `a` reproduces retail's second `addiu v1,sp,0x80`
     * (without it MW reuses the copy's destination register) */
    inline cVector& Normalize() { cVector* a = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct cCollisionFace {
    cVector vertices[3];
    cVector unitNormal;
    char faceProperties[0x10];
    unsigned char isCamPassThru, isReceiveShadow, isReceiveReflection;
    char pad53[0xD];
    cCollisionModel_FaceLocator faceLocator;
};

extern "C" void func_003C0020(cCollisionFace* self)
{
    cVector e1 = self->vertices[1] - self->vertices[0];
    cVector e2 = self->vertices[2] - self->vertices[0];
    float s = func_003C0180(cCollisionModel_GetFace(cCollisionModel_FaceLocator_ParentModel(&self->faceLocator), cCollisionModel_FaceLocator_FaceIndex(&self->faceLocator))->x);
    cVector n = ((e1 ^ e2) * s).Normalize();
    self->unitNormal = n;
}
