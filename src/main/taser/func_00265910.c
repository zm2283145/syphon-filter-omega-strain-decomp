#pragma cplusplus on
/* func_00265910: LOS ray from just behind the first trail segment to the last one; returns the hit flag */
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
static inline void SubV(V* d, V* a, V* b);
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V& operator-=(V o) { SubV(this, this, &o); return *this; }
    void Set(V o) { *this = o; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void SubV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void SubV2(V* d, V* a, V* b) { SubV(d, a, b); }
static inline V operator/(V v, float s) { V* pv = &v; return *pv * (1.0f / s); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len0(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }

static inline float Len(V* a) { return Len0(a); }
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
};
struct Svc { VPAD1(a) virtual void Post(void* m); };
struct Seg { V p; char pad[0x30]; };
struct HeldItem { char pad0[4]; void* ctl; char pad8[0xC]; int idx; Seg* segs; Seg* Back() { Seg** d = &segs; return *d + idx - 1; } };

extern "C" {
extern float D_0048B1C8;
extern char D_005435A0[];
extern char D_004D9180[];
extern char D_004FFB50[];
extern char D_004EA0B0[];
void Event_Construct(void*, void*);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void* a, void* b);
int func_00265910(HeldItem* h);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct LosMsg : MsgB {
    int x24;
    int x28;
    LosRes* res;
    V from;
    V dir;
    void* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V& f, const V& d, void* o)
    {
        LosMsg* m = this;
        Event_Construct(m, D_005435A0);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = 0x10;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};

int func_00265910(HeldItem* h)
{
    int hit = 0;
    if (h->idx > 1) {
        V from = h->segs[0].p;
        V* last = &h->Back()->p;
        V d = *last - from;
        float len = Len(&d);
        from -= d * D_0048B1C8 / len;
        d.Set(*last - from);
        LosRes res;
        LosMsg msg(&res, from, d, h->ctl);
        Service_Lookup(D_004FFB50, D_004EA0B0)->Post(&msg);
        hit = res.hit;
    }
    return hit;
}
