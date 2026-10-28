/* cHermiteSplineWithScaledDuration<cQuaternion>(p0, v0, p1, v1, duration): base cHermiteSpline(p0, v0*duration, p1, v1*duration), then duration and its inverse. */
#pragma cplusplus on
#pragma exceptions off
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { __int128 r = 0; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct CP {
    V position;
    V tangent;
    CP() {}
};
struct Arr { CP d[2]; CP& operator[](int i) { return d[i]; } };
struct HSD {
    Arr mPoints;
    float mDuration;
    float mOneOverDuration;
};
static inline void HS_ctor(HSD* p, const V& p0, V v0, const V& p1, V v1)
{
    {
        CP* q = p->mPoints.d;
        do { q++; } while (q != p->mPoints.d + 2);
    }
    p->mPoints[0].position = p0;
    p->mPoints[0].tangent = v0;
    p->mPoints[1].position = p1;
    p->mPoints[1].tangent = v1;
}
extern "C" HSD* cHermiteSplineWithScaledDuration_cQuaternion_ctor(HSD* p, const V* p0, const V* v0, const V* p1, const V* v1, float duration)
{
    HS_ctor(p, *p0, *v0 * duration, *p1, *v1 * duration);
    p->mDuration = duration;
    p->mOneOverDuration = (duration != 0.0f) ? 1.0f / duration : 0.0f;
    return p;
}