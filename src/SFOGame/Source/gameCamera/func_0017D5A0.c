/* cSplinedMotion::UpdateSplinePoints: on target change rebuild the hermite spline with GetSpeed() as end tangent, else rescale the end tangent into the existing spline. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void ScaleTo(V* d, const V* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V* d, const V* v, float k) { ScaleTo(d, v, k); }
static inline V Scaled(const V& v, float k)
{
    V r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V* d, const V& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V a;
    V b;
    float t;
    void Set(const V& na, const V& nb) { V* p = &a; V* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V& a, const V& z, float t) { s->Set(a, Scaled(z, t)); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V GetSpeed();
    char pad4[0x1C];
    V p20;
    V p30;
    V p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
};

extern "C" {
void cHermiteSplineWithScaledDuration_float_dtor(void* p, int f);
void* opNew_uint_voidP(int size, void* p);
void cHermiteSplineWithScaledDuration_cQuaternion_ctor(void* p, V* a, V* b, V* c, V* d, float t);
}

extern "C" void cSplinedMotion_cQuaternion_UpdateSplinePoints(Cam* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        V z = c->GetSpeed();
        cHermiteSplineWithScaledDuration_float_dtor(&c->sp, -1);
        void* p = opNew_uint_voidP(0x50, &c->sp);
        if (p)
            cHermiteSplineWithScaledDuration_cQuaternion_ctor(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            V z = c->GetSpeed();
            SetSc(&c->sp, c->p40, z, c->sp.t);
        }
    }
}
