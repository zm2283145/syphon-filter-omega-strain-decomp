/*
 * SFOGame/Source/humanCollision: 30 files, 001E5070-001E5A10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5070 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x10]; Q a; Q b; Q c; } S1E5070;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearVelocity(S1E5070* s)
{
    __int128* zp;
    s->b = s->a;
    zp = (__int128*)&s->c;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E5070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5070 */

/* merge_units: begin func_001E5090 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; __int128 q; } Q5090;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearAcceleration(Q5090* s) {
    __int128* zp = &s->q;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E5090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5090 */

/* merge_units: begin func_001E50A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; __int128 q; } Q50A0;
#pragma peephole off
#pragma opt_propagation off
void cPointMass_ClearForce(Q50A0* s) {
    __int128* zp = &s->q;
    *zp = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_001E50A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50A0 */

/* merge_units: begin func_001E50B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 cQuaternion_opSub(V4* b) {
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
static inline void merge_flush_func_001E50B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50B0 */

/* merge_units: begin func_001E50E0 */
#pragma push /* merge_units */
float func_001E50E0(V4* a, V4* b) {
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
static inline void merge_flush_func_001E50E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E50E0 */

/* merge_units: begin func_001E5120 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
/* Physical_SetChildOffsets: apply an orientation to every child root and mark it dirty */
typedef struct { char** p; } It_1E5120;
typedef struct { char pad[0xB4]; int vec; int count; } O_1E5120;
extern "C" {
#if 0 /* merge_units */
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(int* v);
#endif /* merge_units */
int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(PtrVec* v); /* merge_units */
#define std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(a0) ((char * *)std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(int* v);
#endif /* merge_units */
int* std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(PtrVec* v); /* merge_units */
#define std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(a0) ((char * *)std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(It_1E5120* out, int* v, char*** p);
#endif /* merge_units */
void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(Iter* out, void* self, Iter* src); /* merge_units */
#define std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(a0, a1, a2) (std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator((Iter *)(a0), (void *)(a1), (Iter *)(a2))) /* merge_units */

char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(char* r);
void cQuatVec_opAssign(char* t, void* q);
void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(char* r);
void Physical_SetChildOffsets(O_1E5120* self, void* q);
}
static inline int Eq_1E5120(char** a, char** b) { return a == b; }
static inline int EqI_1E5120(int a, int b) { return a == b; }
static inline void SetDirty_1E5120(char* c, unsigned char f) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c)[0xA0] = f; }
void Physical_SetChildOffsets(O_1E5120* self, void* q)
{
    It_1E5120 b;
    It_1E5120 e;
    char** t0;
    char** t1;
    char** it;
    char** end;
    if (EqI_1E5120(self->count, 0) ^ 1) {
        int* v = &self->vec;
        t0 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&b, &self->vec, &t0);
        it = b.p;
        t1 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&e, v, &t1);
        end = e.p;
        /* volatile read: retail reloads e.p for the loop guard separately from end */
        if (Eq_1E5120(it, *(char** volatile*)&e.p) ^ 1) {
            do {
                char* c = *it;
                cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c) + 0x50, q);
                SetDirty_1E5120(c, 1);
                cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(c);
                it++;
            } while (Eq_1E5120(it, end) ^ 1);
        }
    }
}
#undef std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin /* merge_units */
#undef std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end /* merge_units */
#undef std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator /* merge_units */
static inline void merge_flush_func_001E5120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5120 */

/* merge_units: begin func_001E5220 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

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

/* merge_units: begin func_001E54D0 */
#pragma push /* merge_units */
/* RayProbe implicit operator=: V members via asm lq/sq op=, the POD 16-aligned pair at 0x30 copied by the compiler (lq/sq). */
#pragma cplusplus on
struct V_001E54D0 {
    float x, y, z, w;
    V_001E54D0() {}
    V_001E54D0& operator=(const V_001E54D0& o) { V_001E54D0* pd = this; const V_001E54D0* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct P { float a, b; } __attribute__((aligned(16)));
struct S {
    signed char a;
    V_001E54D0 v10;
    V_001E54D0 v20;
    P v30;
    V_001E54D0 v40;
    V_001E54D0 v50;
    unsigned char c60;
    unsigned char c61;
    unsigned char c62;
    int i64;
};
extern "C" S* cCollisionProbe_Ray_opAssign(S* d, const S* s)
{
    *d = *s; return d;
}
static inline void merge_flush_func_001E54D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E54D0 */

/* merge_units: begin func_001E5550 */
#pragma push /* merge_units */
/* RayProbe ctor: function-local static zero V (guard D_004E1D88) written out by hand with externs. */
#pragma cplusplus on
struct V_001E5550 {
    float x, y, z, w;
    V_001E5550() {}
    V_001E5550(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_001E5550(const V_001E5550& o) { V_001E5550* pd = this; const V_001E5550* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V_001E5550& operator=(const V_001E5550& o) { V_001E5550* pd = this; const V_001E5550* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct P_001E5550 { int a, b; } __attribute__((aligned(16)));
struct S_001E5550 {
    signed char a;
    V_001E5550 v10;
    V_001E5550 v20;
    P_001E5550 v30;
    V_001E5550 v40;
    V_001E5550 v50;
    unsigned char c60;
    unsigned char c61;
    unsigned char c62;
    int i64;
};
extern signed char D_004E1D88; extern V_001E5550 D_004E1D90;
static inline const V_001E5550& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; D_004E1D88 = 1; } return D_004E1D90; }
static inline V_001E5550 Unit() { V_001E5550 l0; V_001E5550* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S_001E5550* cCollisionProbe_Ray_ctor(S_001E5550* p, const V_001E5550& e, const V_001E5550& s)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Unit();
    p->v30.a = 0;
    p->v30.b = 0;
    p->v40 = s;
    p->v50 = e;
    p->c60 = 0;
    p->c61 = 0;
    p->c62 = 0;
    p->i64 = 0;
    return p;
}
static inline void merge_flush_func_001E5550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5550 */

/* merge_units: begin func_001E5610 */
#pragma push /* merge_units */
V4* cVector_opAddAssign(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
    return a;
}
static inline void merge_flush_func_001E5610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5610 */

/* merge_units: begin func_001E5630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Read a scalar (used for the physical mass at actor +0x2E0, research
 * ACTOR_RESPONSE_PROBES.md). */
float cPointMass_GetMass(float* value) {
    return value[0];
}
static inline void merge_flush_func_001E5630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5630 */

/* merge_units: begin func_001E5640 */
#pragma push /* merge_units */
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
char* cSkaAnimAnchor_GetDeltaPos(void* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateDeltaPos(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x20;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x70;
}
static inline void merge_flush_func_001E5640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5640 */

/* merge_units: begin func_001E56A0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) ((void *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((a0))) /* merge_units */


extern void* cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(void* r);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(void* r) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r) != 0) {
        cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x30;
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x80;
}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
static inline void merge_flush_func_001E56A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E56A0 */

/* merge_units: begin func_001E5700 */
#pragma push /* merge_units */
FloatPair* cVector_SetY(FloatPair* self, float value) {
    self->b = value;
    return self;
}
static inline void merge_flush_func_001E5700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5700 */

/* merge_units: begin func_001E5710 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Placement inverse: out = inverse(in). rot is a quaternion, pos a vector. */

struct V_001E5710 { float x, y, z, w; } __attribute__((aligned(16)));

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct Plc {
    V_001E5710 rot, pos;
    Plc() {}
    /* The unused xx keeps retail's dead address addiu between the two copies. */
    Plc(const Plc& o) { V_001E5710* d = &rot; Q16(d, &o.rot); void* xx = this; Q16(&pos, &o.pos); }
    Plc& operator=(const Plc& o) { Q16(&rot, &o.rot); Q16(&pos, &o.pos); return *this; }
};

static inline float Dot4(V_001E5710* a, V_001E5710* b) {
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
static inline void Neg3(V_001E5710* v) { asm { lqc2 vf1, 0x0(v); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(v) } }
/* GCC-style form: keeps retail's re-materialised &pos for the rotate below. */
static inline void NegG(V_001E5710* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline void Scale(V_001E5710* v, float k) {
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
static inline void QRot(V_001E5710* v, V_001E5710* q) {
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

/* merge_units: begin func_001E5A10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* gcc-style asm on purpose: retail keeps bool temporaries as move/daddiu pairs (docs/HANDOFF.md) */
static inline void Cp(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }

static inline void Cp2(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); }struct V4_001E5A10 {
    float x, y, z, w;
    V4_001E5A10& operator=(const V4_001E5A10& o) { V4Copy(this, &o); return *this; }
} __attribute__((aligned(16)));

static inline void Cp3(void* d, const void* s) { void* dd = d; const void* ss = s; __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); }
struct Phys {
    char pad[0xA0];
    V4_001E5A10 vel;
};

struct Body {
    char pad[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2[0x54 - 0x2F];
    Phys* phys;
};

struct Contact {
    unsigned char active;
    char pad[0x1F];
    V4_001E5A10 normal;
    char pad2[0x64 - 0x30];
    Body** bodies;
};

struct Actor {
    char pad[0xC];
    char* world;
    char pad2[0x1F0 - 0x10];
    Body* ignore[3];
    char pad3[0x310 - 0x1FC];
    V4_001E5A10 ref;
};

struct cGameEventMsg;

extern "C" {
extern char D_004A03C8[];
extern char D_004DAD20[];
extern char D_004F82F0[];
void* RootCollection_FindByKey(void* coll, void* key, void* obj);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* root);
void* cQuatVec_Translation(void* xf);
void cMessage_ctor_cMessageNameR(cGameEventMsg* m, void* name);
void QueueMessage_cMessageR_cSystemP_int(cGameEventMsg* m, void* target, int immediate);
void cMessage_dtor(cGameEventMsg* m, int flags);
void cHumanCollisionRoutine_HandleAnyLethalCollisions(Actor* self, void* target, Contact* c);
}

struct cGameEventMsg {
    void* vtable;
    char base[0x20];
    unsigned char kind;
    char pad[3];
    Body* body;
    char pad2[4];
};

static inline bool Body_IsSolid(Body* b)
{
    bool r = false;
    if (b->f2D && b->f2C) {
        r = true;
    }
    return r;
}

static inline bool Body_IsFree(Body* b) { return !b->f2E; }

static inline bool Body_IsActive(Body* b)
{
    bool r = false;
    if (Body_IsSolid(b) && Body_IsFree(b)) {
        r = true;
    }
    return r;
}

static inline unsigned char V4_IsZero(V4_001E5A10* v)
{
    int k, f;
    int r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
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

static inline void V4_Sub(V4_001E5A10* out, V4_001E5A10* a, V4_001E5A10* b)
{
    V4_001E5A10 l0;
    V4_001E5A10* pb = b; V4_001E5A10* q1 = &l0; V4_001E5A10* pa = a;
    asm volatile {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    { V4_001E5A10* pd = out; const V4_001E5A10* ps = &l0; __int128 t; asm { lq t, 0(ps); sq t, 0(pd) } }
}

static inline float V4_Dot3(V4_001E5A10* a, V4_001E5A10* b)
{
    int t;
    V4_001E5A10* pb = b; V4_001E5A10* pa = a;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}

#pragma opt_common_subs off
void cHumanCollisionRoutine_HandleAnyLethalCollisions(Actor* self, void* target, Contact* c)
{
    V4_001E5A10 vel;
    V4_001E5A10 d;
    cGameEventMsg msg1;
    cGameEventMsg msg2;
    cGameEventMsg* m;
    Body* body;
    bool sent;
    bool found;
    Phys* phys;
    unsigned int i;
    float eps;

    if (!c->active) {
        return;
    }
    body = *c->bodies;
    phys = body->phys;
    if (phys == 0) {
        return;
    }
    if (!Body_IsActive(body)) {
        return;
    }
    Cp2(&vel, &phys->vel);
    if (V4_IsZero(&vel)) {
        return;
    }
    sent = false;
    if (!sent) {
        char* w = self->world;
        eps = 0.01f;
        cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(w + 0xB0, D_004A03C8, phys)));
        if (vel.z < -eps && c->normal.z < -0.9397f) {
            found = false;
            for (i = 0; i < 3; i++) {
                if (body == self->ignore[i]) {
                    found = true;
                }
            }
            if (!found) {
                m = &msg1;
                cMessage_ctor_cMessageNameR(m, D_004F82F0);
                m->vtable = D_004DAD20;
                m->kind = 2;
                m->body = body;
                QueueMessage_cMessageR_cSystemP_int(m, target, 1);
                msg1.vtable = D_004DAD20;
                cMessage_dtor(m, 0);
                sent = true;
            }
        }
    }
    if (!sent) {
        V4_001E5A10* pb; V4_001E5A10* pa;
        V4_Sub(&d, &vel, &self->ref);
        pb = &c->normal; pa = &d;
        float lim = 30.0f;
        if (!(V4_Dot3(pa, pb) <= lim)) {
            m = &msg2;
            cMessage_ctor_cMessageNameR(m, D_004F82F0);
            m->vtable = D_004DAD20;
            int one = 1;
            m->kind = one;
            m->body = body;
            QueueMessage_cMessageR_cSystemP_int(m, target, one);
            msg2.vtable = D_004DAD20;
            cMessage_dtor(m, 0);
        }
    }
}
static inline void merge_flush_func_001E5A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5A10 */
