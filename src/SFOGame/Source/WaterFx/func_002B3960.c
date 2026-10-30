// cWake::NextFrame(float, cMatrix&, cVector&). Op* as wrapper over Mul0 + return *pt removes dead addiu; Length asm non-volatile lets w copy-prop to a0;
// RandN via asm cvt.w.s/mfc1 helper with 'int r = 0' gives retail's dead daddu zero inits.
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q3960(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QS(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { { V* dd = this; const V* ss = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); } }
    V(const V* p, int) { Q3960(this, p); }
    V& operator=(const V& o) { { V* dd = this; const V* ss = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); } return *this; }
    void Set2(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct RotM;
extern "C" void cMatrix_ctor_void(RotM* m);
struct Q4 { float f[4]; } __attribute__((aligned(16)));
struct M {
    Q4 r[4];
    void Identity() { M* p = this; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    void Apply2(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%1); lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%1)" : : "r"(this), "r"(v) : "memory"); }
    V Mul0(const V& v) const { V t = v; const V* pt = &t; Apply((V*)pt); return *pt; }
    V operator*(const V& v) const { return Mul0(v); }
    void RotAxis(const V& a, float ang);
};
struct RotM { Q4 r[4]; RotM() { cMatrix_ctor_void(this); } };
static inline const V& Normalized(V v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(&v) : "memory"); return v; }
static inline float Length(const V* v) { float r; __asm__("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(r) : "r"(v) : "memory"); return r; }
struct RNode { RNode* next; };
struct It {
    RNode* p;
    It() {}
    It(RNode* q) : p(q) {}
    It(const It& o) : p(o.p) {}
    It& operator=(const It& o) { p = o.p; return *this; }
    It& operator++() { p = p->next; return *this; }
};
struct RHead { RNode* n0; RNode* n4; };
struct Ripple {
    V pos;
    V d[4];
    float f170;
    float f174;
    int i178;
    void* p17C;
};
struct RList { int size; RHead h; };
struct WaterFx {
    float timer;
    RList list;
    char pad10[8];
    float f18; char pad1C[4];
    int n20;
};
struct WObj { char pad[0x30]; V pos; };
extern "C" {
RNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(RHead* h);
It std_list_deleter_tNode_erase_listdeleter(RList* l, It pos);
It std_list_deleter_tNode_insert(RList* l, It pos, const Ripple& r);
float Libc_Atan2f(float y, float x);
void cMatrix_SetWithAxisAngle(RotM* m, float x, float y, float z, float a);
void cMatrix_Rotate(M* a, const RotM* b);
void cMatrix_ctor_void(RotM* m);
int Libc_Rand(void);
void cWake_NextFrame_float(WaterFx* w, float dt);
extern V D_004ABF60;
extern V D_004ABF70;
extern V D_004ABF80;
extern V D_004ABF90;
extern void* D_004ABFA0[];
}
static inline void MulRot(M* m, const V& a, float ang) { RotM rm; cMatrix_SetWithAxisAngle(&rm, a.x, a.y, a.z, ang); cMatrix_Rotate(m, &rm); }
static inline void MulRot2(M* m, const V& a, float ang) { MulRot(m, a, ang); }
static inline void MulRot3(M* m, const V& a, float ang) { MulRot2(m, a, ang); }
inline void M::RotAxis(const V& a, float ang) { MulRot3(this, a, ang); }
static inline void SetF(float* p, float v) { *p = v; }
static inline It End(RHead* h) { RHead* t = h; return It(t->n4); }
static inline It EndL(RList* l) { return End(&l->h); }
static inline It Begin(RList* l) { return It(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_7(&l->h)); }
static inline int FtoI(float f) { int r = 0; asm { cvt.w.s f, f; mfc1 r, f } return r; }
static inline int RandN(int n) { int r = Libc_Rand(); return FtoI((float)n * ((float)r / 2147483648.0f)); }
static inline int RandRange(int lo, int hi) { int n = hi - lo + 1; return lo + RandN(n); }
extern "C" void cWake_NextFrame_float_cMatrixR_cVectorR(WaterFx* w, WObj* o, V* vel, float dt)
{
    V v;
    v.Set2(vel->x, vel->y, 0.0f, 0.0f);
    float speed = Length(&v);
    float half = 0.5f * dt;
    if (!(w->timer < 0.0375f)) {
        w->timer -= 0.0375f;
        if (w->list.size >= 0x20) {
            It it;
            It e;
            it = Begin(&w->list);
            ++it;
            e = std_list_deleter_tNode_erase_listdeleter(&w->list, it);
        }
        float ang = Libc_Atan2f(-vel->x, vel->y);
        M m;
        m.Identity();
        m.RotAxis(V(0.0f, 0.0f, 1.0f, 0.0f), ang);
        Ripple r;
        r.pos = o->pos;
        r.pos.z = w->f18;
        r.d[0] = Normalized(m * D_004ABF60);
        r.d[1] = Normalized(m * D_004ABF70);
        r.d[2] = Normalized(m * D_004ABF80);
        r.d[3] = Normalized(m * D_004ABF90);
        r.f174 = (speed > -vel->z) ? 0.0f : 1.0f;
        r.p17C = D_004ABFA0[RandRange(0, 2)];
        r.f170 = 1.2f;
        int k = RandRange(0, w->n20 - 2);
        r.i178 = k;
        std_list_deleter_tNode_insert(&w->list, End(&w->list.h), r);
    }
    cWake_NextFrame_float(w, dt);
    if (!(speed <= half) || speed < -vel->z)
        w->timer += dt;
}



