#pragma cplusplus on
#pragma peephole off
#pragma inline_depth(10)
struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { cQuaternion* pd = this; const cQuaternion* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    cQuaternion& operator=(const cQuaternion& o) { cQuaternion* pd = this; const cQuaternion* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
    cQuaternion& operator*=(const cQuaternion& o);
} __attribute__((aligned(16)));

struct cHumanIkRoutine {
    char pad[0x250];
    cQuaternion gunRecoilCurr;
};

static inline cQuaternion Identity() { cQuaternion l0; cQuaternion* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
static inline cQuaternion Ident2() { return Identity(); }
static inline void LerpTo(cQuaternion* q1, const cQuaternion* b, const cQuaternion* c, float s)
{
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
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
static inline void MulTo(cQuaternion* q1, const cQuaternion* b, const cQuaternion* c)
{
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
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
static inline cQuaternion Mul(const cQuaternion* pa, const cQuaternion* pb) { cQuaternion r; cQuaternion* pr = &r; const cQuaternion* qb = pa; MulTo(pr, qb, pb); return r; }
static inline cQuaternion LerpN(const cQuaternion* pa, const cQuaternion* pb, float t) { cQuaternion r; cQuaternion* pr = &r; LerpTo(pr, pa, pb, t); return r; }
static inline cQuaternion Lerp(cQuaternion a, const cQuaternion& b, float t) { return LerpN(&a, &b, t); }
static inline cQuaternion operator*(const cQuaternion& a, const cQuaternion& b) { return Mul(&a, &b); }
static inline float Fabs(float x) { return x < 0.0f ? -x : x; }
static inline void MulEq(cQuaternion& d, const cQuaternion& o) { d = d * o; }
inline cQuaternion& cQuaternion::operator*=(const cQuaternion& o) { MulEq(*this, o); return *this; }
// abs.s via asm: mw38 has no fabsf intrinsic (C ternary emits a branch)
static inline bool IsNearIdentity(const cQuaternion& cQuaternion) { float d = 1.0f - cQuaternion.w; float r; asm { abs.s r, d } return r <= 1e-7f; }

extern "C" cQuaternion cHumanIkRoutine_GetCurrentGunRecoilAnimation(const cHumanIkRoutine* self)
{
    const cQuaternion& currVal = self->gunRecoilCurr;
    unsigned char currValNotNearIdentity = !IsNearIdentity(self->gunRecoilCurr);
    cQuaternion result = currVal;
    if (currValNotNearIdentity) {
        // retail frame reserves slots for a dead duplicate of this block (dossier lists the local twice)
        if (0) {
        cQuaternion gunRecoilAdditionalFraction = Lerp(Ident2(), currVal, 0.35f);
        result *= gunRecoilAdditionalFraction;
        } else {
        cQuaternion gunRecoilAdditionalFraction = Lerp(Ident2(), currVal, 0.35f);
        result *= gunRecoilAdditionalFraction;
        }
    }
    return result;
}
