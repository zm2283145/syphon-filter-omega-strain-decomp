/*
 * SFOGame/Source/humanIk: 3 files, 001D0770-001D0C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D0770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_vector_deleter_cBone_data_void(char* self) {
    return self + 8;
}
static inline void merge_flush_func_001D0770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D0770 */

/* merge_units: begin func_001D0780 */
#pragma push /* merge_units */
/* humanIk.cc: independently aim the head and neck.
 * Quaternion multiplication follows the prototypes' named-result operator* and
 * static reference-result VU0Multiply API. VU0, abs.s and quad copies are the
 * original platform primitives; the surrounding control flow is C++.
 */
#pragma cplusplus on
#pragma inline_depth(10)
struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion GetConjugate() const;
    cQuaternion& operator=(const cQuaternion& o) { cQuaternion* pd = this; const cQuaternion* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
    static void VU0Multiply(cQuaternion&,const cQuaternion&,const cQuaternion&);
    cQuaternion operator*(const cQuaternion&) const;
    inline void PreMul(const cQuaternion& q);
    inline void PostMul(const cQuaternion& q);
    cQuaternion(const cQuaternion& o) { cQuaternion* pd = this; const cQuaternion* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
} __attribute__((aligned(16)));
/* Retail cBoneIk prefixes; pose storage is copied as three 16-byte lanes.
 * The third lane is a vector and is never used in quaternion arithmetic here. */
typedef struct Bone {
    char pad0[0x20];
    cQuaternion q20;
    char pad30[0x50];
    cQuaternion base[3]; /* 0x80 */
    char padB0[0x20];
    cQuaternion cur[3]; /* 0xD0 */
} Bone;

/* cBoneIk array element, stride 0x100; other is its related bone at 0xC0. */
typedef struct Slot {
    char pad0[0x20];
    cQuaternion q20;
    char pad30[0x50];
    cQuaternion base[3];
    char padB0[0x10];
    Bone* other; /* 0xC0 */
    char padC4[0xC];
    cQuaternion cur[3];
} Slot;


typedef struct Obj1D0780 {
    char pad0[0x250];
    cQuaternion q250;
} Obj1D0780;

extern Slot UpperBodyNodeTable[];


static inline float AbsF(float x) { asm { abs.s x, x } return x; }

static inline void LerpTo(cQuaternion* q1, const cQuaternion* b, const cQuaternion* c, float s)
{
    int rv;
    asm volatile {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv, s
        qmtc2.ni rv, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(q1)
    }
}
static inline cQuaternion QNlerp(float s, const cQuaternion& qx, const cQuaternion& qy) { cQuaternion r; const cQuaternion* a = &qx; cQuaternion* pr = &r; const cQuaternion* b = &qy; LerpTo(pr, a, b, s); return r; }
static inline cQuaternion QNlerpA(float s, const cQuaternion& qx, const cQuaternion& qy) { cQuaternion r; cQuaternion* pr = &r; const cQuaternion* a = &qx; const cQuaternion* b = &qy; LerpTo(pr, a, b, s); return r; }
static inline cQuaternion QIdent()
{
    cQuaternion l0;
    cQuaternion* p = &l0;
    asm volatile { sqc2 vf0, 0x0(p) }
    return l0;
}

inline void cQuaternion::VU0Multiply(cQuaternion& result,const cQuaternion& quat0,const cQuaternion& quat1)
{
    cQuaternion* q1=&result; const cQuaternion* pb=&quat0; const cQuaternion* pc=&quat1;
    asm volatile {
        lqc2 vf1, 0x0(pb)
        lqc2 vf2, 0x0(pc)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(q1)
    }
}
inline cQuaternion cQuaternion::operator*(const cQuaternion& quaternion) const { cQuaternion result; VU0Multiply(result,*this,quaternion); return result; }
inline void cQuaternion::PreMul(const cQuaternion& q) { const cQuaternion* pq=&q; *this=*pq * *this; }
inline void cQuaternion::PostMul(const cQuaternion& q) { cQuaternion* p=this; *p=*p * q; }



extern "C" void cHumanIkRoutine_AimHeadIndependently(Obj1D0780* self, const cQuaternion& qa, const cQuaternion& qb, unsigned int idx, float t)
{
    cQuaternion rot;
    cQuaternion a;
    cQuaternion b;
    float w = self->q250.w;
    float one;
    float tol = 1e-7f;
    one = 1.0f;
    one -= w;
    bool near = AbsF(one) <= tol;
    unsigned char notId = !near;
    Slot* s;
    Bone* o;

    if (notId) {
        rot = QNlerpA(0.5f, QIdent(), self->q250.GetConjugate());
    }
    s = &UpperBodyNodeTable[idx];
    o = s->other;
    if (t != 0.0f) {
        a = qa;
        a.PreMul(o->q20);
        o->cur[0] = QNlerp(t * 0.7f, o->base[0], a);
        if (notId)
            o->cur[0].PostMul(rot);
        b = qb;
        b.PreMul(s->q20);
        s->cur[0] = QNlerp(t * 0.7f, s->base[0], b);
        if (notId)
            s->cur[0].PostMul(rot);
    } else if (notId) {
        o->cur[0] = o->base[0];
        o->cur[0].PostMul(rot);
        s->cur[0] = s->base[0];
        s->cur[0].PostMul(rot);
    } else {
        { cQuaternion* p = o->base; cQuaternion* d = o->cur; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
        { cQuaternion* d = s->cur; cQuaternion* p = s->base; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    }
}
static inline void merge_flush_func_001D0780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D0780 */

/* merge_units: begin func_001D0C80 */
#pragma push /* merge_units */
#include "loose00_types.h"

extern int cHumanIkRoutine_OrientFoot_AfterPositionLeg(int self, int a1, int a2, int a3);
extern int cHumanIkRoutine_PositionLeg(int self, int a1, int a2, int a3);

/* Run cHumanIkRoutine_PositionLeg with the first argument, then cHumanIkRoutine_OrientFoot_AfterPositionLeg with the second. */
int cHumanIkRoutine_PositionLegAndOrientFoot(int self, int first, int second, int a3, int t0) {
    int result;

    cHumanIkRoutine_PositionLeg(self, first, a3, t0);
    result = cHumanIkRoutine_OrientFoot_AfterPositionLeg(self, second, a3, t0);
    return result;
}
static inline void merge_flush_func_001D0C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D0C80 */
