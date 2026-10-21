#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Nrm_(void* p) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void Crs_(void* d, const void* l, const void* r) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); }
static inline void UnitM(void* m) {
    int t;
    asm {
        sqc2 vf0, 0x30(m)
        qmfc2.ni t, vf0
        pcpyud t, t, zero
        sq t, 0x10(m)
        pexcw t, t
        sq t, 0x20(m)
        pcpyud t, t, zero
        sq t, 0(m)
    }
}
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { Q16(this, &o); }
    V(const V* o) { V* d = this; const V* s = o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { Q16(this, &o); return *this; }
    void Normalize() { Nrm_(this); }
    void Set(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
    V& NormalizeR() { Nrm_(this); return *this; }
} __attribute__((aligned(16)));
struct VX : V { VX() {} };
static inline V Cross(const V& a, const V& b) { VX c; Crs_(&c, &a, &b); return c; }
static inline V Normalized(V v) { v.Normalize(); return v; }
struct M;
extern "C" {
void Mtx_Transpose3x3(M* m);
int Mtx_IsTranslationZero(M* m);
V* func_00133EC0(M* m);
void Vec4_Assign(V* d, V* s);
void Vec3_Negate(V* v);
void Mtx_TransformByTranspose(V* v, M* m);
void Mtx_SetTranslation(M* m, V* t);
void Effect_CreateInstance(int id, M* m);
}
struct M {
    V r0, r1, r2, t;
    void Identity() { UnitM(this); }
    void Invert() { InvertJ(); }
    void InvertJ() { InvertI(); }
    void InvertI() {
        Mtx_Transpose3x3(this);
        if (!Mtx_IsTranslationZero(this)) {
            V tr;
            Vec4_Assign(&tr, func_00133EC0(this));
            Vec3_Negate(&tr);
            Mtx_TransformByTranspose(&tr, this);
            Mtx_SetTranslation(this, &tr);
        }
    }
} __attribute__((aligned(16)));
extern "C" void Effect_SpawnDirectional(int id, V* pos, V* dir)
{
    M m;
    V p(pos);
    V a;
    V b;
    V c;
    p.w = 1.0f;
    m.Identity();
    if (0.0f == dir->x && 0.0f == dir->y) {
        if (dir->z < 0.0f) {
            m.Invert();
        }
    } else {
        a = Cross(*dir, V(0.0f, 0.0f, 1.0f, 1.0f)); a.Normalize(); a = a;
        b = Cross(*dir, a); b.Normalize(); b = b;
        c = Cross(a, b); c.Normalize(); c.Set(c);
        m.r0 = a;
        m.r1 = b;
        m.r2 = c;
    }
    m.t = p;
    Effect_CreateInstance(id, &m);
}












