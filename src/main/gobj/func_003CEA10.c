#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QA(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QS(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
static inline void JC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); void* xx = d; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* m) { int t; void* p = m; asm { .set noreorder; sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p); .set reorder } }
static inline void VZ(void* d) { asm { .set noreorder; sq zero, 0(d); .set reorder } }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); void* xx = this; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
    void SetAdd(const V& a0, const V& b0);
} __attribute__((aligned(16)));
static inline void SetAddI_(V* self, const V& a0, const V& b0) { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory"); void* xx = self; const V* s = &r; V* d = self; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
inline void V::SetAdd(const V& a0, const V& b0) { SetAddI_(this, a0, b0); }

static inline V Add(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%2)" : : "r"(&a0), "r"(&b0), "r"(&r) : "memory");
    return r;
}
static inline V AddV(const V& a0, V b0) { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory"); return r; }
struct M34 { V r[3]; V t; };
struct M44;
static inline void MulRot(M44* d, M44* s, M44* r);
struct M44 {
    __int128 q[4];
    M44() {}
    void Rot(M44* r) { M44* p = this; MulRot(p, p, r); }
    M44* RotR(M44* r) { M44* p = this; MulRot(p, p, r); return p; }
};
static inline void MulRot(M44* d, M44* s, M44* r)
{
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddz.xyzw vf12, vf6, vf8z; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddz.xyzw vf13, vf6, vf9z; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddz.xyzw vf14, vf6, vf10z; vmove.xyzw vf15, vf7; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(s), "r"(r) : "memory");
}
extern "C" void Mtx44_FromMtx34(M44* d, const M34* s);
struct Xf {
    virtual void v0();
    virtual void Set34(M34* m);
    virtual void SetMtx(M44* m);
    virtual void SetPos(const V& p);
    VPAD16(a)
    virtual void Update();
    char pad04[0xC];
    M34 m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
    const V& Pos() { Sync(); return m.t; }
};
struct MoverH {
    VPAD16(a) VPAD2(b)
    virtual void Move(V* d);
};
struct NodeH { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; };
struct Msg { char pad[0x24]; char kind; char pad25[0xB]; M34 m; };
struct MsgClass { int id; };
extern "C" MsgClass* Event_GetType(Msg* m);
extern "C" signed char D_004E1D88;
extern "C" V D_004E1D90;
extern "C" MsgClass D_0055D4D8;
extern "C" MsgClass g_TeleportMsgClass;
extern "C" MsgClass g_cEnableMsgClass;
extern "C" MsgClass g_cDisableMsgClass;
struct Obj;
extern "C" int Object_BroadcastToChildren(Obj* o, Msg* m);
struct Obj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void OnEnable(int f);
    virtual void OnDisable(int f);
    char pad04[0x28];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x21];
    Xf* xf;
    NodeH* NodeH;
    MoverH* MoverH;
    bool Active() { bool r = false; if (b2D && b2C) r = true; return r; }
    bool Off() { return b2E; }
    bool Vis() { return Off() == false; }
    bool NotOff() { return !Off(); }
    bool Live() { bool r = false; if (Active() && (Off() ^ 1)) r = true; return r; }
};

static inline void Case4_3CEA10(Obj* obj, Msg* msg) {
            M44 b;
            M44 a;
            Mtx44_FromMtx34(&a, &msg->m);
            Xf* x = obj->xf;
            x->Sync();
            Mtx44_FromMtx34(&b, &x->m);
            obj->xf->SetMtx(b.RotR(&a));
}
extern "C" int Object_HandleMessage(Obj* obj, Msg* msg)
{
    int t;
    t = Event_GetType(msg)->id;
    if (t == D_0055D4D8.id || (t = Event_GetType(msg)->id, t == g_TeleportMsgClass.id)) {
        if (obj->xf) {
        if (!D_004E1D88) {
            D_004E1D90.x = 0;
            D_004E1D88 = 1;
            D_004E1D90.y = 0;
            D_004E1D90.z = 0;
            D_004E1D90.w = 0;
        }
        V delta;
        { const V* s = &D_004E1D90; V* d = &delta; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(q) : "r"(s), "r"(d) : "memory"); }
        switch ((unsigned char)msg->kind) {
        case 0:
            {
            V p = msg->m.t;
            obj->xf->SetPos(p);
            }
            break;
        case 1: {
            M44 a;
            Mtx44_FromMtx34(&a, &msg->m);
            obj->xf->SetMtx(&a);
            break;
        }
        case 2:
            obj->xf->Set34(&msg->m);
            break;
        case 3: {
            V np;
            V d = msg->m.t;
            np.SetAdd(obj->xf->Pos(), d);
            obj->xf->SetPos(np);
            delta = V(msg->m.t);
            break;
        }
        case 4:
            Case4_3CEA10(obj, msg);
            break;
        }
        t = Event_GetType(msg)->id;
        if (t == g_TeleportMsgClass.id) {
            if (obj->NodeH) {
                Xf* x = obj->xf;
                if (x) {
                    NodeH* n; if (x->b50) x->Update(); void* s; s = &x->m; n = obj->NodeH; n->flag = 0; void* d = &n->m; GQR(&n->m, s); void* xx = &n->xf; UM(&n->xf); VZ(&n->v90);
                    VZ(&n->vA0);
                }
            }
            if (obj->MoverH) obj->MoverH->Move(&delta);
        }
        return 1;
        }
        return 0;
    }
    t = Event_GetType(msg)->id;
    if (t == g_cEnableMsgClass.id) {
        if (!obj->Live()) obj->OnEnable(1);
        obj->b2C = 1;
        return 1;
    }
    t = Event_GetType(msg)->id;
    if (t == g_cDisableMsgClass.id) {
        if (obj->Live()) obj->OnDisable(1);
        obj->b2C = 0;
        return 1;
    }
    return Object_BroadcastToChildren(obj, msg);
}
