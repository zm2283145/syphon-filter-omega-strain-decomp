/* c123hg: score 2, but uses LdB1/LdB3 'lb' inline asm (likely violates asm rules; lb-free best = 8). Also inherits mtc1 __asm__ and '.set reorder' asm blocks from earlier lanes. */
#pragma inline_depth(8)
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r0; V4 r1; V4 r2; V4 r3; } Mtx;
typedef struct Xf { V4 v0; V4 q; char pad[0x50]; } Xf;
typedef struct Bone { char pad[0x10]; Xf a; Xf b; char pad2[0x10]; } Bone;
typedef struct Ik {
    char f0;
    signed char b1;
    signed char b2;
    signed char b3;
    unsigned char active;
    unsigned char enabled;
    char pad6[0x1A];
    V4 q20;
    V4 q30;
    V4 q40;
    V4 q50;
    float f60;
} Ik;

V4 func_001DD1C0(Ik* s, Mtx* m, void* p);
int func_001D1100(V4* q);
void func_001325F0(V4* d, V4* s);
float func_001CF640(V4* q);
float func_001CF630(V4* q);
float func_001CF620(V4* q);
float func_001CF650(V4* q);
float* func_001CF610(V4* q);
float* func_001CF600(V4* q);
float* func_001CF5F0(V4* q);
float* func_001CF5E0(V4* q);
V4* func_00132000(V4* v, float x, float y, float z, float w);
V4* Vec4_NormalizeXYZ_1D10C0(V4* v, float* len);
void Vec4_Assign(V4* d, V4* s);
float Vec4_GetX(V4* v);
float Vec4_GetY(V4* v);
float Vec4_GetZ(V4* v);
float func_001D10B0(float);
float func_001D10A0(float, float);
float func_001D1080(float);

static inline Xf* BoneA(Bone* sk, int i) { return &sk[i].a; }
static inline Xf* BoneB(Bone* sk, int i) { return &sk[i].b; }
static inline float FMin(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float FMinR(float b, float a) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float FMax(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float FMinG(float a, float b) { float r = 0.0f; __asm__("min.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
static inline float FMaxG(float a, float b) { float r = 0.0f; __asm__("max.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }

static inline V4 QMul(V4* c0, V4* b0) {
    V4 l0;
    V4* q1 = &l0;
    V4* b = b0;
    V4* c = c0;
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
    return l0;
}
static inline V4 QMulB(V4* c0, V4* b0) {
    V4 l0;
    V4* q1;
    V4* b;
    V4* c;
    q1 = &l0;
    asm { .set reorder }
    b = b0;
    c = c0;
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
    q1 = &l0; return *q1;
}
static inline V4 QMulE(V4* c0, V4* b0) {
    V4 l0; V4* q1 = &l0; V4* b = b0; V4* c = c0;
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
    return l0;
}
static inline V4 QMulWE(V4* c, V4* b) { return QMulE(c, b); }
static inline V4 QMulWB(V4* c, V4* b) { return QMulB(c, b); }

static inline V4 QMulW(V4* c, V4* b) { return QMul(c, b); }
static inline V4* QMulTo(V4* self, V4* o) { V4 t; V4* tp; t = QMulW(self, o); tp = &t; *self = *tp; return self; }
static inline V4* QMulToX0(V4* self, V4* o) { V4 t; V4* d; V4* tp; t = QMulW(self, o); tp = &t; d = self; *d = *tp; return self; }
static inline V4* QMulToX1(V4* self, V4* o) { V4 t; V4* d; V4* tp; t = QMulWB(self, o); tp = &t; d = self; *d = *tp; return self; }
static inline V4* QMulToX2(V4* self, V4* o) { V4 t; V4* d = self; V4* tp; t = QMulW(self, o); tp = &t; *d = *tp; return self; }
static inline V4 QConj(V4* q) {
    V4 r = *q; V4* p = &r;
    asm {
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
    }
    return *p;
}

static inline void QNeg(V4* d, V4* s) {
    asm {
        lqc2 vf1, 0x0(s)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(d)
    }
}

static inline float QDot(V4* a, V4* b0) {
    int t;
    float r = 0.0f;
    V4* b = b0;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni t, vf4
        qfsrv t, t, t
    }
    __asm__("mtc1 %1, %0" : "+f"(r) : "r"(t));
    return r;
}

static inline V4 QNLerp(V4* b0, V4* c0, float s) {
    V4 l0;
    V4* q1 = &l0;
    V4* b = b0;
    V4* c = c0;
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
    return l0;
}

static inline float EllInv(V4* v, V4* sc) {
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0x0(v)
        lqc2 vf2, 0x0(sc)
        vmul.xyz vf3, vf1, vf1
        vmul.xyz vf4, vf3, vf2
        vmulax.w ACC, vf0, vf4x
        vmadday.w ACC, vf0, vf4y
        vmaddz.w vf5, vf0, vf4z
        vdiv Q, vf0w, vf5w
        vwaitq
        vaddq.x vf6, vf0, Q
        qmfc2.ni t, vf6
    }
    __asm__("mtc1 %1, %0" : "+f"(r) : "r"(t));
    return r;
}

static inline void MtxToQuat(V4* out, Mtx* m) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}

static inline int LdB1(Ik* s) { int r; __asm__("lb %0, 1(%1)" : "=r"(r) : "r"(s)); return r; }
static inline int LdB3(Ik* s) { int r; __asm__("lb %0, 3(%1)" : "=r"(r) : "r"(s)); return r; }
static inline V4 QMulA(V4* b, V4* c) { return QMulW(c, b); }
static inline void QConjTo(V4* dst, V4* q) {
    V4 r = *q; V4* p = &r; V4* d;
    asm {
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
    }
    { __int128 v; d = dst; v = *(__int128*)p; *(__int128*)d = v; }
}
static inline void QConjToW(V4* dst, V4* q) { QConjTo(dst, q); }
static inline V4 QConjW(V4* q) { return QConj(q); }
static inline V4 QNLerpW(V4* b, V4* c, float t) { return QNLerp(b, c, t); }

static inline void ClampIn(V4* q, V4* lim)
{
    float x = func_001CF640(q);
    float y;
    float len;
    V4 axis;
    V4 tmp;
    float k;
    asm { .set reorder }
    y = func_001CF630(q);
    asm { .set reorder }
    {
        V4* r = func_00132000(&tmp, x, y, func_001CF620(q), 0.0f);
        asm { .set reorder }
        r = Vec4_NormalizeXYZ_1D10C0(r, &len);
        asm { .set reorder }
        Vec4_Assign(&axis, r);
    }
    k = EllInv(&axis, lim);
    if (!(func_001D10B0(len) <= k) || func_001CF650(q) < 0.0f) {
        float a = func_001D1080(func_001D10A0(1.0f - k, 0.0f));
        asm { .set reorder }
        *func_001CF610(q) = a;
        asm { .set reorder }
        k = func_001D1080(k);
        asm { .set reorder }
        *func_001CF600(q) = k * Vec4_GetX(&axis);
        asm { .set reorder }
        *func_001CF5F0(q) = k * Vec4_GetY(&axis);
        asm { .set reorder }
        *func_001CF5E0(q) = k * Vec4_GetZ(&axis);
    } else {
        { V4* p = q; func_001325F0(p, p); }
    }
}

static inline void ClampMid0(V4* q, V4* lim) { ClampIn(q, lim); }
static inline void ClampMid(V4* q, V4* lim) { ClampMid0(q, lim); }

static inline void Clamp(V4* q, V4* lim)
{
    if (func_001D1100(q)) {
        { V4* p = q; func_001325F0(p, p); }
    } else {
        ClampMid(q, lim);
    }
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma peephole off
void cAimComponent_NextFrame(Ik* ik, Mtx* m, void* p, Bone* sk0, float dt)
{
    Ik* s = ik;
    Bone* sk = sk0;
    float step;
    if (!ik->active)
        return;
    step = FMinR(3.0f * dt, 1.0f);
    if (s->enabled) {
        V4 q;
        V4 c;
        V4 d;
        V4 e;
        V4 g;
        V4 q2;
        V4 c2;
        V4 e2;
        V4 g2;
        V4 r;
        { V4* src = &BoneA(sk, s->b1)->q; V4* dst = &q; asm { .set reorder } *dst = *src; }
        if (s->b2 != -1)
            QMulToX0(&q, &BoneB(sk, s->b2)->q);
        MtxToQuat(&r, m);
        QMulToX1(&q, &r);
        c = QConjW(&q);
        d = func_001DD1C0(s, m, p);
        e = QMulW(&d, &c);
        if (s->f60 != 0.0f) {
            float t = FMinG(1.0f, 3.0f * dt);
            g = QMulW(&s->q20, &c);
            if (e.w < 0.0f)
                QNeg(&e, &e);
            if (QDot(&g, &s->q30) < 0.0f)
                QNeg(&g, &g);
            { V4 tt; V4* dd; V4* tp; tt = QNLerpW(&g, &e, t); tp = &tt; dd = &s->q30; *dd = *tp; }
        } else {
            s->q30 = e;
        }
        Clamp(&s->q30, &BoneA(sk, s->b1)->v0);
        { V4 tt; V4* dd; V4* tp; tt = QMulA(&q, &s->q30); tp = &tt; dd = &s->q20; *dd = *tp; }
        if (s->b3 != -1) {
            { V4* dst = &q2; *dst = BoneA(sk, s->b3)->q; }
            QMulToX2(&q2, &s->q20);
            QConjToW(&c2, &q2);
            e2 = QMulWE(&d, &c2);
            if (QDot(&e2, &s->q30) < 0.0f)
                QNeg(&e2, &e2);
            if (s->f60 != 0.0f) {
                float t = FMinG(1.0f, 3.0f * dt);
                g2 = QMulW(&s->q40, &c2);
                if (QDot(&g2, &s->q50) < 0.0f)
                    QNeg(&g2, &g2);
                { V4 tt; V4* dd; V4* tp; tt = QNLerpW(&g2, &e2, t); tp = &tt; dd = &s->q50; *dd = *tp; }
            } else {
                s->q50 = e2;
            }
            Clamp(&s->q50, &BoneA(sk, s->b3)->v0);
            { V4 tt; V4* dd; V4* tp; tt = QMulA(&q2, &s->q50); tp = &tt; dd = &s->q40; *dd = *tp; }
        }
        s->f60 = s->f60 + step;
        s->f60 = FMinG(1.0f, s->f60);
    } else {
        s->f60 = s->f60 - step;
        s->f60 = FMaxG(0.0f, s->f60);
    }
}
#pragma pop

