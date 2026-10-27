/*
 * SFOGame/Source/humanCollision: 7 files, 001E5710-001E5990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* Placement inverse: out = inverse(in). rot is a quaternion, pos a vector. */

struct V { float x, y, z, w; } __attribute__((aligned(16)));

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct Plc {
    V rot, pos;
    Plc() {}
    /* The unused xx keeps retail's dead address addiu between the two copies. */
    Plc(const Plc& o) { V* d = &rot; Q16(d, &o.rot); void* xx = this; Q16(&pos, &o.pos); }
    Plc& operator=(const Plc& o) { Q16(&rot, &o.rot); Q16(&pos, &o.pos); return *this; }
};

static inline float Dot4(V* a, V* b) {
    int rv0;
    float ret = 0.0f;
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
static inline void Neg3(V* v) { asm { lqc2 vf1, 0x0(v); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(v) } }
/* GCC-style form: keeps retail's re-materialised &pos for the rotate below. */
static inline void NegG(V* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline void Scale(V* v, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(v)
        .set reorder
    }
}
static inline void QRot(V* v, V* q) {
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

extern "C" void cQuatVec_Copy_Invert(Plc* o, Plc* in);
void cQuatVec_Copy_Invert(Plc* o, Plc* in)
{
    Plc t = *in;
    Plc* a = &t;
    float d = Dot4(&a->rot, &a->rot);
    if (d != 0.0f) {
        Neg3(&a->rot);
        __int128 tt = 0; /* dead paddub */
        Scale(&a->rot, 1.0f / d);
    }
    NegG(&a->pos);
    QRot(&a->pos, &a->rot);
    *o = *a;
}
static inline void merge_flush_func_001E5710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5710 */

/* merge_units: begin func_001E5830 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Vec4* cVector_SetZ(Vec4* v, float z) {
    v->z = z;
    return v;
}
static inline void merge_flush_func_001E5830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5830 */

/* merge_units: begin func_001E5840 */
#pragma push /* merge_units */
typedef struct { __int128 q; } V_5840;
typedef struct { char pad[0x10]; V_5840 a; V_5840 b; } S_5840;
#pragma push
#pragma peephole off

#pragma opt_common_subs off
V_5840 cPointMass_GetDisplacement(S_5840* s)
{
    V_5840 r;
    V_5840* pr = &r;
V_5840* pa = &s->a;
V_5840* pb = &s->b;
    asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    return r;
}
#pragma pop
static inline void merge_flush_func_001E5840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5840 */

/* merge_units: begin func_001E5880 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_5880;
struct Mdl_5880 { VPAD16(a) VPAD4(b) virtual void Update(); int pad4[3]; V_5880 m[4]; unsigned char dirty; };
struct Ctx_5880 { char pad[0x28]; Mdl_5880* model; char pad2c[0x24]; V_5880 pos; };
/* anchor point: refresh the model if dirty, transform pos by its matrix (VU0) */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" V_5880 cSkeleton_GetCenterOfMass(Ctx_5880* self)
{
    Mdl_5880* m = self->model;
    if (m->dirty) m->Update();
    V_5880 p;
    V_5880* mm;
    V_5880* pp;
    VCopyF(&p, &self->pos);
    mm = m->m;
    pp = &p;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf7, 0x30(mm)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}
#pragma pop
static inline void merge_flush_func_001E5880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5880 */

/* merge_units: begin func_001E5920 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Scale(V4* a, V4* b, float s) {
    int rv1;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 rv1, s
        qmtc2.ni rv1, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(a)
        .set reorder
    }
}
static inline void merge_flush_func_001E5920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5920 */

/* merge_units: begin func_001E5940 */
#pragma push /* merge_units */
/* clamp helper: s - 2*max(0.5*(s-b-k), c*d) - b, k picked by flag */
extern float D_004A0340;
extern float D_004A0338;
static inline float fmax_(float a, float b) { float r; asm { .set noreorder; max.s r, a, b; .set reorder } return r; }
#pragma push
#pragma opt_propagation off
float ActorPhys_ResponseHeightDelta(int flag, float a, float b, float c, float d)
{
    float s;
    float t;
    float k;
    float u;
    float h;
    s = a + c;
    t = s - b;
    if (flag) k = D_004A0340; else k = D_004A0338;
    h = fmax_(0.5f * (t - k), c * d);
    u = s - h;
    return u - h - b;
}
#pragma pop
static inline void merge_flush_func_001E5940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5940 */

/* merge_units: begin func_001E5990 */
#pragma push /* merge_units */
static inline float fmax__001E5990(float a, float b) { float r; asm { max.s r, a, b } return r; }
void ActorBody_CalcQueryHeight(float* outTop, float* outRatio, int flag, float base, float floor, float height, float scale)
{
    float top = base + height;
    float d = top - floor;
    float c;
    float m;
    float r;
    c = flag ? D_004A0340 : D_004A0338;
    m = fmax__001E5990(0.5f * (d - c), height * scale);
    *outTop = top - m;
    if (m != height) r = m / height; else r = 1.0f;
    *outRatio = r;
}
static inline void merge_flush_func_001E5990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5990 */
