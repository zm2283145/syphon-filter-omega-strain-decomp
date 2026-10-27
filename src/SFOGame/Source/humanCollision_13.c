/*
 * SFOGame/Source/humanCollision: 9 files, 001E5220-001E5480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5220 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(PtrVec* v) {
    return v->data;
}

float func_001E5260(AnimScalar* self) {
    return self->unk0C;
}

/* Reset the timer from the definition's duration (+0x10). */
void AnimScalar_RestartTimer(AnimScalar* self) {
    self->timer = self->def->duration;
}
static inline void merge_flush_func_001E5220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5220 */

/* merge_units: begin func_001E5280 */
#pragma push /* merge_units */
typedef struct {
    int f0;
    float slopeA;
    int f8;
    float slopeB;
    float scale;
    float invScale;
} AnimScalar_1E5280;
void AnimScalar_RescaleSlopes(AnimScalar_1E5280* p, float s) {
    float r = s * p->invScale;
    float inv;
    p->slopeA *= r;
    p->slopeB *= r;
    p->scale = s;
    inv = (s != 0.0f) ? 1.0f / s : 0.0f;
    p->invScale = inv;
}
static inline void merge_flush_func_001E5280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5280 */

/* merge_units: begin func_001E52E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* the vadd sits two inline levels below operator+= so its pointer gets the register retail uses */
static inline void Add52_(void* d, const void* o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%0); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(o), "r"(d) : "memory"); }
static inline void Add52(void* d, const void* o) { Add52_(d, o); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); }
    V operator-() const { V t; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    V& operator+=(V o) { Add52(this, &o); return *this; }
    V& Rotate(const V& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" V cQuaternion_GetConjugate(const V& q);
extern "C" V* Quat_InverseTransformPoint(V* p, const V* q, const V* t)
{
    *p += -*t;
    V* r = p;
    V c = cQuaternion_GetConjugate(*q);
    { void* xx = &c; }
    r->Rotate(c);
    return r;
}
static inline void merge_flush_func_001E52E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E52E0 */

/* merge_units: begin func_001E53A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
float Plane_HeightAt(V4* a, V4* b) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void merge_flush_func_001E53A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E53A0 */

/* merge_units: begin func_001E53E0 */
#pragma push /* merge_units */
float cPlane_C(char* self) {
    return *(float*)(self + 8);
}
static inline void merge_flush_func_001E53E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E53E0 */

/* merge_units: begin func_001E53F0 */
#pragma push /* merge_units */
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4_ func_001E53F0(const V4_* v, float z) {
    V4_ t;
    V4_* d = &t;
    VCopyF(d, v);
    {
        V4_* e = &t;
        e->z = z;
        return *e;
    }
}
#pragma pop
static inline void merge_flush_func_001E53F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E53F0 */

/* merge_units: begin func_001E5420 */
#pragma push /* merge_units */
Vec4* cPlane_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
static inline void merge_flush_func_001E5420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5420 */

/* merge_units: begin func_001E5430 */
#pragma push /* merge_units */
#include "vu0_ops.h"

static inline void Set4_(V4* r, float x, float y, float z, float w) { r->x = x; r->y = y; r->z = z; r->w = w; }
V4* cPlane_ctor_cVectorR_cVectorR(V4* r, V4* p, V4* n) {
    float d = VU0_Dot3(n, p);
    { float w = -d; float z = n->z; float y = n->y; float x = n->x; r->x = x; r->y = y; r->z = z; r->w = w; }
    return r;
}
static inline void merge_flush_func_001E5430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5430 */

/* merge_units: begin func_001E5480 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cCollisionProbe_Ray_dtor)
static inline void merge_flush_func_001E5480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5480 */
