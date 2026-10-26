#pragma cplusplus on
/* cGameCamera_CanSee: set the fog slot, push the camera inverse matrix, and LOS-test from the camera eye to the target position */
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
static inline void AddV2(V* d, V* a, V* b);
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
    V& operator+=(V o) { AddV2(this, this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void AddV2(V* d, V* a, V* b) { AddV(d, a, b); }
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
struct Mq { __int128 q[4]; Mq() {} };
struct M {
    V r0, r1, r2, r3;
    M() {}
    // 128-bit lq/sq quadword copy idiom
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
struct XNode {
    VPAD1(a)
    virtual void SetMatrix(M m);
    VPAD16(b) VPAD2(c)
    virtual void Update();
    char pad4[0xC];
    M m;
    unsigned char b50;
    const M& Mtx() { if (b50) Update(); return m; }
};
struct Cam { char pad0[0x50]; XNode* node; char pad54[0xC]; float x60; };
struct Tgt { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V GetPos(); };
struct Fog { char pad0[0x64]; float x64; };
struct Holder { char pad0[0xC]; Fog* fog; };
struct Slot { char pad[0x2E4]; float f2E4; int pad2E8; float f2EC; float f2F0; char f2F4; char f2F5; char f2F6; };
struct Rs { char pad[0xA80]; Mq mtx[1]; };
extern "C" {
extern Holder* D_004FFBD4;
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
extern char g_Game[];
extern char g_LosCheckService[];
void Event_Construct(void*, void*);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void* a, void* b);
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
void* Camera_GetNode(void* o);
Mq Transform_GetInverseMatrix(void* xf);
int XLib_Inside(void* r, V* p);
bool cGameCamera_CanSee(Cam* c, Tgt* t);
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
    LosMsg(LosRes* r, const V& f, const V& d, void* o, int mask)
    {
        LosMsg* m = this;
        Event_Construct(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = mask;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};

#define RS ((Rs*)g_Video)
#define SLOT(i) ((Slot*)(g_Video + (i) * 0x110))

static inline void SetFog(Cam* c, float b) { Fog* fg = D_004FFBD4->fog; float fx = fg->x64; float fa = c->x60; int i = D_00538C60; char* base = g_Video; Slot* s = (Slot*)(base + i * 0x110); s->f2F0 = fa; s->f2E4 = b; s->f2EC = 12.0f + fx; s->f2F6 = 1; s->f2F4 = 0; }
// 64-byte quadword copy (lq/sq pairs)
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

/* the unused xx reproduces retail's dead addiu of the matrix temporary's address */
static inline void SetTop(const Mq& m) { const Mq* xx = &m; QR(&RS->mtx[D_00538C64], (void*)&m); }

bool cGameCamera_CanSee(Cam* c, Tgt* t)
{
    bool vis = 0;
    SetFog(c, 2.0f);
    QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
    D_00538C64++;
    SetTop(Transform_GetInverseMatrix(Camera_GetNode(c)));
    D_00538C68 = 1;
    V p = t->GetPos();
    if ((unsigned char)XLib_Inside(g_Video, &p)) {
        LosRes res;
        M m = c->node->Mtx();
        V eye = m.r3;
        V dir = p - eye;
        float len = Len(&dir);
        eye += dir * 2.0f / len;
        {
            LosMsg msg(&res, eye, dir, t, 4);
            Service_Lookup(g_Game, g_LosCheckService)->Post(&msg);
            if (!res.hit) vis = 1;
        }
    }
    D_00538C64--;
    D_00538C68 = 1;
    return vis;
}
