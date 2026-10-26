/* SecondaryAim_KickRecoil: apply a pending recoil kick to the aim
 * quaternion: a randomised pitch about the yaw-rotated X axis, then a small
 * random roll about Y; clears the kick. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct M;
extern "C" {
void Mtx44_SetRotation(M* m, float, float, float, float, float, float, float, float, float);
int Random_Next(void);
float Math_SinThunk(float);
float Math_CosThunk(float);
float Math_Sin(float);
float Math_Cos(float);
}
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { Mtx44_SetRotation(this, a, b, c, d, e, f, g, h, i); }
} __attribute__((aligned(16)));
struct AA {
    float x, y, z, angle;
    AA(const V& a, float ang) { x = a.x; y = a.y; z = a.z; angle = ang; }
};
struct QA : V {
    QA(const AA& a) { float h = 0.5f * a.angle; float c = Math_Cos(h); float s = Math_Sin(h); w = c; x = s * a.x; y = s * a.y; z = s * a.z; }
};
struct Aim { char p0[0x324]; float kick; };
extern "C" unsigned char SecondaryAim_KickRecoil(Aim* self, V* q);
/* VU0 macro ops have no C equivalent (asm). */
static inline void Apply33(V* out, const V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(out), "r"(m), "r"(v) : "memory"); }
static inline void QMul(V* o, const V* b, const V* c) {
    __asm__ volatile("lqc2 vf1, 0x0(%1)\n lqc2 vf2, 0x0(%2)\n vmul.xyzw vf3, vf1, vf2\n vopmula.xyz ACC, vf1, vf2\n vmaddaw.xyz ACC, vf1, vf2w\n vmaddaw.xyz ACC, vf2, vf1w\n vopmsub.xyz vf4, vf2, vf1\n vsubaz.w ACC, vf3, vf3z\n vmsubay.w ACC, vf0, vf3y\n vmsubx.w vf4, vf0, vf3x\n sqc2 vf4, 0x0(%0)" : : "r"(o), "r"(b), "r"(c) : "memory");
}
static inline V operator*(V v, const M& m) { V* p = &v; Apply33(p, p, &m); return *p; }
static inline V operator*(const V& a, const V& b) { V r; QMul(&r, &a, &b); return r; }
static inline float Rand01() { return (float)Random_Next() / 2147483648.0f; }
/* k: retail keeps the span in a saved register across Random_Next. */
static inline float Rnd(float span, float lo) { float k = span; float r = Rand01(); float t = k * r; return t + lo; }
static inline float Around(float c, float span, float lo) { float t = Rnd(span, lo); return t + c; }
unsigned char SecondaryAim_KickRecoil(Aim* self, V* q)
{
    unsigned char r = 0;
    if (self->kick > 0.0f) {
        V q1;
        float pitch = self->kick * Around(0.0964294448f, 0.014835299f, -0.0074176495f);
        float yaw = Rnd(0.69813168f, -0.17453292f);
        float s = Math_SinThunk(yaw);
        float c = Math_CosThunk(yaw);
        M m(c, 0.0f, s, 0.0f, 1.0f, 0.0f, -s, 0.0f, c);
        V axis = V(1.0f, 0.0f, 0.0f, 0.0f) * m;
        QA qa1(AA(axis, pitch));
        { const V& t = qa1; q1 = t; }
        QA qa2(AA(V(0.0f, 1.0f, 0.0f, 0.0f), Rnd(0.0445058979f, -0.022252949f)));
        q1 = q1 * qa2;
        *q = *q * q1;
        r = 1;
        self->kick = 0.0f;
    }
    return r;
}
