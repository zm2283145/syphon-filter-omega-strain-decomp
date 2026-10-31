#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
struct V4 {
    float x, y, z, w;
    V4() {}
    V4& operator=(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
    inline void PreMul(const V4& q);
    inline void PostMul(const V4& q);
    V4(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
} __attribute__((aligned(16)));
typedef struct Bone {
    char pad0[0x20];
    V4 q20;
    char pad30[0x50];
    V4 base[3]; /* 0x80 */
    char padB0[0x20];
    V4 cur[3]; /* 0xD0 */
} Bone;

typedef struct Slot {
    char pad0[0x20];
    V4 q20;
    char pad30[0x50];
    V4 base[3];
    char padB0[0x10];
    Bone* other; /* 0xC0 */
    char padC4[0xC];
    V4 cur[3];
} Slot;


typedef struct Obj1D0780 {
    char pad0[0x250];
    V4 q250;
} Obj1D0780;

extern Slot D_004F32B0[];
extern "C" V4 cQuaternion_GetConjugate(const V4& v);

static inline float AbsF(float x) { asm { abs.s x, x } return x; }

static inline void LerpTo(V4* q1, const V4* b, const V4* c, float s)
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
static inline V4 QNlerp(float s, const V4& qx, const V4& qy) { V4 r; const V4* a = &qx; V4* pr = &r; const V4* b = &qy; LerpTo(pr, a, b, s); return r; }
static inline V4 QNlerpA(float s, const V4& qx, const V4& qy) { V4 r; V4* pr = &r; const V4* a = &qx; const V4* b = &qy; LerpTo(pr, a, b, s); return r; }
static inline V4 QIdent()
{
    V4 l0;
    V4* p = &l0;
    asm volatile { sqc2 vf0, 0x0(p) }
    return l0;
}

static inline void QMulTo(V4* q1, const V4* pb, const V4* pc)
{
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
static inline V4 QMul(const V4& qx, const V4& qy) { V4 l0; QMulTo(&l0, &qx, &qy); return l0; }

struct V4B : V4 { V4B() {} V4B(const V4B& o) { __int128* pd = (__int128*)this; const __int128* ps = (const __int128*)&o; *pd = *ps; } };
static inline V4B QMulB(const V4& qx, const V4& qy) { V4B l0; QMulTo(&l0, &qx, &qy); return l0; }
static inline void PostMulB(V4* p0, const V4& q) { V4* p = p0; *p = QMulB(*p, q); }
static inline void QMulToC(const V4* pb, const V4* pc, V4* q1)
{
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
static inline V4 QMulC(const V4& qx, const V4& qy) { V4 l0; QMulToC(&qx, &qy, &l0); return l0; }
static inline void PostMulC(V4* p0, const V4& q) { V4* p = p0; *p = QMulC(*p, q); }
inline void V4::PreMul(const V4& q) { const V4* pq = &q; *this = QMul(*pq, *this); }
inline void V4::PostMul(const V4& q) { V4* p = this; *p = QMul(*p, q); }

static inline V4 QIdentW() { return QIdent(); }

static inline V4 QHalf(const V4& qx, const V4& qy) { return QNlerp(0.5f, qx, qy); }

static inline bool IsIdentT(V4* q, float tol) { float one = 1.0f; one -= q->w; return AbsF(one) <= tol; }
static inline bool IsIdentW(float w, float tol) { float one = 1.0f; one -= w; return AbsF(one) <= tol; }
static inline bool CmpLe(float a, float b) { return a <= b; }
static inline bool IsIdentOW(float one, float w, float tol) { one -= w; return AbsF(one) <= tol; }
static inline bool IsIdentR(float tol, V4* q) { float one = 1.0f; one -= q->w; return AbsF(one) <= tol; }
static inline float AbsSub(float a, float b) { a -= b; return AbsF(a); }
static inline float GetWv(const V4* q) { return q->w; }
static inline const float& GetWr(const V4* q) { return q->w; }
extern "C" void cHumanIkRoutine_AimHeadIndependently(Obj1D0780* self, float t, V4* qa, V4* qb, int idx)
{
    V4 rot;
    V4 a;
    V4 b;
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
        rot = QNlerpA(0.5f, QIdent(), cQuaternion_GetConjugate(self->q250));
    }
    s = &D_004F32B0[idx];
    o = s->other;
    if (t != 0.0f) {
        a = *qa;
        a.PreMul(o->q20);
        o->cur[0] = QNlerp(t * 0.7f, o->base[0], a);
        if (notId)
            o->cur[0].PostMul(rot);
        b = *qb;
        b.PreMul(s->q20);
        s->cur[0] = QNlerp(t * 0.7f, s->base[0], b);
        if (notId)
            s->cur[0].PostMul(rot);
    } else if (notId) {
        o->cur[0] = o->base[0];
        PostMulB(&o->cur[0], rot);
        s->cur[0] = s->base[0];
        PostMulC(&s->cur[0], rot);
    } else {
        { V4* p = o->base; V4* d = o->cur; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
        { V4* d = s->cur; V4* p = s->base; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    }
}
