/* 0025CDC0 cGrenade::CalculateArcPoints(const cVector&, const cVector&, float, float) (grenade.cc),
 * rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, int) { const void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    V& Normalize();
    V GetNormalized() const;
    V GetNormalizedX() const;
    float LengthSq() const;
} __attribute__((aligned(16)));

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void SubM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void MulT(V* d, const V* p, float s) { __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
static inline void NormM(V* v) { asm volatile { lqc2 vf1, 0x0(v); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(v) } }
static inline void CrossM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0; sqc2 vf3, 0x0(d) } }
static inline float LenSqM(const V* v)
{
    int rv0;
    float ret = 0.0f;
    asm volatile {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
inline V& V::Normalize() { V* t = this; NormM(t); return *this; }
inline float V::LengthSq() const { return LenSqM(this); }
static inline V operator-(const V& a, const V& b) { V r; V* pd = &r; const V* pa = &a; const V* pb = &b; SubM(pd, pa, pb); return r; }
static inline V operator*(const V& v, float s) { V r; MulT(&r, &v, s); return r; }
static inline V MulB(const V& v, float s) { V r; const V* pv = &v; V* pd = &r; MulT(pd, pv, s); return r; }
static inline V MulC(const V& v, float s) { V r; V* pd = &r; const V* pv = &v; MulT(pd, pv, s); return r; }
static inline V MulD(const V& v, float s) { V r; MulT(&r, &v, s); return r; }
static inline void AddA(V& a, const V& b) { AddM(&a, &a, &b); }
static inline void AddB(V& a, const V& b) { V* pd = &a; const V* pa = &a; const V* pb = &b; AddM(pd, pa, pb); }
static inline void AddC(V& a, const V& b) { const V* pa = &a; V* pd = &a; const V* pb = &b; AddM(pd, pa, pb); }
static inline void AddD(V& a, const V& b) { const V* pb = &b; AddM(&a, &a, pb); }
static inline void AddE(V& a, V b) { AddM(&a, &a, &b); }
static inline void MeA(V& a, float s) { V* pd = &a; const V* pp = &a; MulT(pd, pp, s); }
static inline void MeB(V& a, float s) { MulT(&a, &a, s); }
static inline void MeC(V& a, float s) { const V* pp = &a; V* pd = &a; MulT(pd, pp, s); }
static inline V CrA(const V& a, const V& b) { V r; CrossM(&r, &a, &b); return r; }
static inline V CrB(const V& a, const V& b) { V r; V* pd = &r; const V* pa = &a; const V* pb = &b; CrossM(pd, pa, pb); return r; }
static inline V CrC(const V& a, const V& b) { V r; const V* pa = &a; const V* pb = &b; V* pd = &r; CrossM(pd, pa, pb); return r; }
static inline V CrD(const V& a, const V& b) { V r; CrossM(&r, &a, &b); V* p = &r; return *p; }

static inline V operator*(float s, const V& v) { V r; MulT(&r, &v, s); return r; }
static inline V& operator+=(V& a, const V& b) { AddM(&a, &a, &b); return a; }
static inline V& operator*=(V& a, float s) { V* pd = &a; const V* pp = &a; MulT(pd, pp, s); return a; }
static inline V NormalizedV(V v) { V* p = &v; p->Normalize(); return *p; }
static inline V NormalizedX(V v) { V* p = &v; p->Normalize(); return V(*p, 0); }
inline V V::GetNormalized() const { return NormalizedV(*this); }
inline V V::GetNormalizedX() const { return NormalizedX(*this); }
static inline V Cross(const V& a, const V& b) { V r; CrossM(&r, &a, &b); return r; }

extern "C" {
V* cVector_ctor_float_float_float_float(V* d, float x, float y, float z, float w);
V* cVector_ctor_cVectorR(V* d, const V* s);
const V* cVector_GetZero(void);
void cPointMass_SetMass(void* pm, float m);
V nPhysics_CalculateInitialVelocityForTrajectory(const V* from, const V* to, float g, float k, float minAng, V* extra);
V cVector_opSub(const V* a, const V* b);
V cVector_opMul(const V* a, float s);
V cVector_opAdd(const V* a, const V* b);
V opMul(float s, const V* v);
V* cVector_opAssign(V* d, const V* s);
void cVector_WSet1(V* v);
struct VList { int pad0; int count; V* data; };
void std_vector_deleter_cVector_clear(VList* l);
void std_vector_imp_cVector_insert(VList* l, V* pos, int n, const V* v);
extern float g_ThrowGravity;
extern V g_GameGravity;
extern float D_004F7FE0;
extern float D_0048AFD8, D_0048AFA8, D_0048AF80;
extern VList D_004F8000;
extern V D_004F8010;
}

struct cPointMass {
    float mass;
    float invMass;
    char pad8[0x10 - 8];
    V pos;
    V prevPos;
    V vel;
    V accel;
    V force;
    V v60;
    int n70;
    cPointMass() { Init1(); }
    void Init1() { Init2(); }
    void Init2() { Init3(); }
    void Init3()
    {
        cVector_ctor_cVectorR(&pos, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 1.0f));
        cVector_ctor_cVectorR(&prevPos, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 1.0f));
        cVector_ctor_cVectorR(&vel, cVector_GetZero());
        cVector_ctor_cVectorR(&accel, cVector_GetZero());
        cVector_ctor_cVectorR(&force, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 0.0f));
        cVector_ctor_cVectorR(&v60, cVector_ctor_float_float_float_float(&V(), 0.0f, 0.0f, 0.0f, 0.0f));
        n70 = 0;
        cPointMass_SetMass(this, 1.0f);
    }
    void SetPosition(V p) { pos = p; }
    void SetPositionR(const V& p) { pos = p; }
    V Disp() const { return pos - prevPos; }
    void SetPrevPosition(V p) { prevPos = p; }
    void AddForce(V f) { force += f; }
    void Integrate(float timeStep, float invTimeStep, float sqTimeStep) { Integrate2(timeStep, invTimeStep, sqTimeStep); }
    void Integrate2(float timeStep, float invTimeStep, float sqTimeStep) { Integrate3(timeStep, invTimeStep, sqTimeStep); }
    void Integrate3(float timeStep, float invTimeStep, float sqTimeStep) { Integrate4(timeStep, invTimeStep, sqTimeStep); }
    void Integrate4(float timeStep, float invTimeStep, float sqTimeStep)
    {
        V newPos = cVector_opAdd(&cVector_opSub(&opMul(2.0f, &pos), &prevPos), &cVector_opMul(&force, invMass * sqTimeStep));
        cVector_opAssign(&prevPos, &pos);
        cVector_opAssign(&pos, &newPos);
        cVector_WSet1(&pos);
        V oldVel;
        cVector_ctor_cVectorR(&oldVel, &vel);
        cVector_opAssign(&vel, &cVector_opMul(&cVector_opSub(&pos, &prevPos), invTimeStep));
        cVector_opAssign(&accel, &cVector_opMul(&cVector_opSub(&vel, &oldVel), invTimeStep));
    }
};

static inline void PushBack(VList& l, const V& v) { const V* pv = &v; std_vector_imp_cVector_insert(&l, l.data + l.count, 1, pv); }

extern "C" void cGrenade_CalculateArcPoints(const V& startPos, const V& targetPos, float angle, float maxVel)
{
    cPointMass pointMass;
    float gravity = g_ThrowGravity;
    V fwd = (targetPos - startPos).GetNormalized();
    D_004F8010 = Cross(fwd, V(0.0f, 0.0f, 1.0f, 1.0f));
    V start = startPos;
    AddB(start, D_004F8010 * D_0048AFD8);
    D_004F8010 *= D_0048AFA8 / 3.0f;
    pointMass.SetPosition(start);
    V velocity = nPhysics_CalculateInitialVelocityForTrajectory(&start, &targetPos, gravity, angle, D_004F7FE0, 0);
    float maxVelSq = maxVel * maxVel;
    if (velocity.LengthSq() > maxVelSq)
        velocity = MulB(velocity.GetNormalizedX(), maxVel);
    float timeStep = 1.0f / D_0048AF80;
    float invTimeStep = 1.0f / timeStep;
    float sqTimeStep = timeStep * timeStep;
    V vec = velocity * timeStep;
    pointMass.prevPos = start - vec;
    pointMass.AddForce(g_GameGravity * pointMass.mass);
    unsigned char goingUp = 1;
    float endz = targetPos.z;
    std_vector_deleter_cVector_clear(&D_004F8000);
    PushBack(D_004F8000, pointMass.pos);
    do {
        pointMass.Integrate(timeStep, invTimeStep, sqTimeStep);
        goingUp = pointMass.Disp().z >= 0.0f;
        PushBack(D_004F8000, pointMass.pos);
    } while (goingUp || pointMass.pos.z > endz);
}
