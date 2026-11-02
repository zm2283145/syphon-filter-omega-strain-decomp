/*
 * SFOGame/Source/Generator: 15 files, 00220350-00221460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00220350 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetGeneratorDeleteMsg_dtor, D_004DE260, cMessage_dtor)
static inline void merge_flush_func_00220350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220350 */

/* merge_units: begin func_002203B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "Generator_types.h"

Word* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_3(GenListPos* a, GenListPos* b) {
    return 0u < (unsigned int)((int)a->node ^ (int)b->node);
}

void cLList_cSafePtr_cGOBJ_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
GenListPos* cLListIterator_cSafePtr_cGOBJ_opInc(GenListPos* it) {
    it->node = it->node->next;
    return it;
}
static inline void merge_flush_func_002203B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002203B0 */

/* merge_units: begin func_00220410 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O00220410 { char p[0xC]; int id; };
struct H00220410 { O00220410* p; int id; };
static inline O00220410* Get00220410(H00220410* h) {
    bool isNull;
bool ok;
O00220410* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
extern "C" bool cSafePtr_cGOBJ_opEq(H00220410* x, H00220410* y)
{
    O00220410* b = Get00220410(y); return Get00220410(x) == b;
}
static inline void merge_flush_func_00220410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220410 */

/* merge_units: begin func_00220480 */
#pragma push /* merge_units */
/* Iterator dereference: address of the node value. */
int* cLListIterator_cSafePtr_cGOBJ_opMul(GenListPos* it) {
    return &it->node->value;
}

Word* cLListIterator_cSafePtr_cGOBJ_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cLList_cSafePtr_cGOBJ_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cSafePtr_cGOBJ_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_00220480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220480 */

/* merge_units: begin func_002204C0 */
#pragma push /* merge_units */
#include "vslot_pad.h"
#include "net_local_id.h"

#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    void SubEq(const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&b) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    void AddEq(V b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&b) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator*(float s) const { V r; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(&r), "r"(this), "f"(s) : "memory"); return r; }
} __attribute__((aligned(16)));
struct Mtx { V r0, r1, r2, t; const V& T() const { return t; } void SubT(V& d) const { d.SubEq(T()); } };
static inline const V& MTrans(const Mtx& m) { return m.t; }
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
static inline const V& SubPos(Sub* o) { if (o->f50) o->Sync(); return o->m.t; }
static inline const Mtx& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
struct Obj { char pad[0x50]; Sub* sub; };
struct Tgt {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) virtual void e0();
    virtual Mtx GetMtx();
    VPAD4(f)
    virtual unsigned char State();
    int pad4[2]; int id;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct It { LNode* n; };
struct Gen { char pad[0x90]; int list90; char pad94[0xB8 - 0x94]; float radius; char padBC[0xD0 - 0xBC]; signed char busy; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0x1F]; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } };
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Obj* pl; Obj* cl; int f58; unsigned char b5C; };
struct Plr { char pad[0x30]; Obj* obj; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern Plr* g_LocalPlayer;
extern char g_CameraObject[];
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
#if 0 /* merge_units */
LNode* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_tail(void*); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((LNode *)std_list_deleter_cSafePtr_cGOBJ_tail((a0))) /* merge_units */

#if 0 /* merge_units */
LNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(It* it, LNode* n);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(void*, void*); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((LNode * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
LNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(It* it, LNode* n);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(void*, void*); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(a0, a1) ((LNode * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP((void *)(a0), (void *)(a1))) /* merge_units */

void cNode_GetLoc(V* out, void* node);
Obj* cNetObj_GetPlayer(int i);
Obj** cLList_cCAMERA_GOBJPtr_Front(void* v);
float Libc_Cosf(float a);
#if 0 /* merge_units */
Obj* cGOBJ_GetClosestPlayer(void* node, int a);
#endif /* merge_units */
void* cGOBJ_GetClosestPlayer(void*, int); /* merge_units */
#define cGOBJ_GetClosestPlayer(a0, a1) ((Obj *)cGOBJ_GetClosestPlayer((a0), (a1))) /* merge_units */

Svc* cSystemContainer_GetSystem(void* a, void* b);
int cMessage_ctor_cMessageNameR(void* m, void* type);
#if 0 /* merge_units */
int cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((a0), (short)(a1))) /* merge_units */

}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline void Begin(It* o, Gen* g) { It t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(&g->list90)->next); *o = t; }
static inline void End(It* o, Gen* g) { It t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(&g->list90)); *o = t; }
static inline void DoRay(Svc* svc, HitRes* res, const V& start, const V& end, Obj* pl, Obj* cl) {
    RayMsg msg;
    RayMsg* m = &msg;
    cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
    m->vt = D_004D9180;
    m->f24 = 0;
    m->f28 = 0;
    m->res = res;
    m->start = start;
    m->end = end;
    m->pl = pl;
    m->cl = cl;
    m->f58 = 0;
    m->b5C = 0;
    m->start.w = 1.0f;
    m->end.w = 0.0f;
    svc->Send(&msg);
    msg.vt = D_004D9180;
    cMessage_dtor(m, 0);
}
extern "C" int cGenerator_CheckSpawnNode(Gen* self, void* node)
{
    int r = self->busy;
    if (!(unsigned char)r) {
        It it;
        It b;
        It e;
        bool found = false;
        Begin(&b, self);
        for (it = b; End(&e, self), it.n != e.n; it.n = it.n->next) {
            Tgt* t = HGet(&it.n->h);
            if (t->State() != 3) {
                V d;
                cNode_GetLoc(&d, node);
                t->GetMtx().SubT(d);
                if (d.LenSq() < 9.0f) found = true;
            }
        }
        if (found) goto done;
        r = 1;
        if (g_IsMultiplayer) {
            for (int i = 0; i < 4; i++) {
                Obj* p = cNetObj_GetPlayer(i);
                if (p) {
                    V d;
                    cNode_GetLoc(&d, node);
                    d.SubEq(SubPos(p->sub));
                    if (d.LenSq() < self->radius) {
                        r = 0;
                        break;
                    }
                }
            }
        } else {
            Obj* p = g_LocalPlayer->obj;
            V d;
            cNode_GetLoc(&d, node);
            d.SubEq(SubPos(p->sub));
            if (d.LenSq() < self->radius) r = 0;
        }
        if ((unsigned char)r == 1) {
            float ang = 0.87266463f;
            V d;
            cNode_GetLoc(&d, node);
            d.SubEq(SubPos((*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->sub));
            d.z = 0.0f;
            d.Normalize();
            V f = SubMtx((*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->sub).r1;
            f.z = 0.0f;
            float dot = f.Dot(d);
            if (dot + (1.0f - Libc_Cosf(ang)) < 1.0f) {
                r = 1;
            } else {
                Obj* pl = g_LocalPlayer->obj;
                Obj* cl = 0;
                if (g_IsMultiplayer) cl = cGOBJ_GetClosestPlayer(node, 0);
                Svc* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                V end;
                V start;
                cNode_GetLoc(&start, node);
                start.z += 6.0f;
                end = SubPos((*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->sub);
                end.AddEq(SubMtx((*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->sub).r1 * 1.5f);
                end.SubEq(start);
                HitRes res;
                DoRay(svc, &res, start, end, pl, cl);
                r = res.hit ? 1 : 0;
            }
        }
    }
done:
    if ((unsigned char)r == 1) self->busy = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002204C0(void) {}
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP /* merge_units */
#undef cGOBJ_GetClosestPlayer /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002204C0 */

/* merge_units: begin func_00220BB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Tgt_00220BB0 {
    V5(a) V5(b) V5(c) V5(d) virtual void e0(); virtual void e1();
    virtual void Deactivate(int);
    int pad4[2]; int id;
};
struct Hnd_00220BB0 { Tgt_00220BB0* p; int id; };
struct LNode_00220BB0 { LNode_00220BB0* prev; LNode_00220BB0* next; Hnd_00220BB0 h; };
struct Gen_00220BB0;
struct Ev {
    char* vt; char p4[0x1C]; signed char f20; char p21[3]; Tgt_00220BB0* f24;
};
extern "C" {
#if 0 /* merge_units */
LNode_00220BB0* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((LNode_00220BB0 *)std_list_deleter_cSafePtr_cGOBJ_tail((a0))) /* merge_units */



#if 0 /* merge_units */
LNode_00220BB0** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(LNode_00220BB0** it, LNode_00220BB0* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((LNode_00220BB0 * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (void *)(a1))) /* merge_units */



#if 0 /* merge_units */
LNode_00220BB0** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(LNode_00220BB0** it, LNode_00220BB0* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(a0, a1) ((LNode_00220BB0 * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP((void *)(a0), (void *)(a1))) /* merge_units */



#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(void*, char*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((a0), (void *)(a1))) /* merge_units */



int QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
#if 0 /* merge_units */
int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((a0), (short)(a1))) /* merge_units */



#if 0 /* merge_units */
void cGOBJ_Deactivate(Gen_00220BB0*, int);
#endif /* merge_units */
void cGOBJ_Deactivate(void*, int); /* merge_units */
#define cGOBJ_Deactivate(a0, a1) (cGOBJ_Deactivate((void *)(a0), (a1))) /* merge_units */

extern char D_004A4A88[];
extern char D_004DB620[];
extern char D_004DB660[];
}
struct Gen_00220BB0 {
    char pad[0x90]; int list90;
};
static inline Tgt_00220BB0* HGet_00220BB0(Hnd_00220BB0* h) {
    unsigned char valid = 1;
    Tgt_00220BB0* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
extern "C" void cGenerator_DeactivateImmediate(Gen_00220BB0* self)
{
    Tgt_00220BB0* t;
    LNode_00220BB0* it;
    LNode_00220BB0* end;
    LNode_00220BB0* n;
    std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(&it, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90)->next);
    for (n = it; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90)), n != end; n = n->next) {
        Hnd_00220BB0* h = &n->h;
        t = HGet_00220BB0(h);
        t->Deactivate(1);
        Ev ev;
        cMessage_ctor_cMessageNameR(&ev, D_004A4A88);
        ev.f24 = t;
        ev.vt = D_004DB620;
        ev.f20 = 2;
        QueueMessage_cMessageR_cSystemP_int(&ev, self, 0);
        ev.vt = D_004DB660;
        cMessage_dtor(&ev, 0);
    }
    cGOBJ_Deactivate(self, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220BB0(void) {}
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cGOBJ_Deactivate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220BB0 */

/* merge_units: begin func_00220D00 */
#pragma push /* merge_units */
typedef struct cGen00220D00 {
    char pad0[0xC];
    char f0C[0x20];
    char b2C;
    char pad2D[0xCC - 0x2D];
    unsigned int mask;
} cGen00220D00;
extern void cGenInfoObject_ctor(void* msg);
extern void cGenInfoObject_Deactivate(void* msg, void* target);
void cGenerator_NetDisable(cGen00220D00* self, int bit)
{
    if (bit >= 0)
        self->mask &= ~(1 << bit);
    else
        self->mask = 0;
    if (self->mask == 0) {
        int msg[1];
        self->b2C = 0;
        cGenInfoObject_ctor(msg);
        cGenInfoObject_Deactivate(msg, self->f0C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220D00 */

/* merge_units: begin func_00220D70 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad04[0x18]; int size; signed char kind; char pad21[3]; int target; } Msg_220D70;
typedef struct { char pad[0xC]; char sub[4]; int id; char pad14[0x18]; unsigned char state; char pad2d[0xCC - 0x2D]; int mask; } G_220D70;
#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_220D70* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */



#if 0 /* merge_units */
int cMessage_dtor(Msg_220D70* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */



extern char g_cDisableMsgClass[];
extern char D_004E0860[];
void cDisableMsg_SendDisabled(Msg_220D70* msg, int id, int x);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* t);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */



#if 0 /* merge_units */
void cGenInfoObject_Deactivate(void* t, void* p);
#endif /* merge_units */
#define cGenInfoObject_Deactivate(a0, a1) (cGenInfoObject_Deactivate((a0), (a1))) /* merge_units */



void cGenerator_v18(G_220D70* g, int bit)
{
    if (g_IsMultiplayer) {
        int t[1];
        Msg_220D70 msg;
        if (bit >= 0)
            g->mask &= ~(1 << bit);
        if (g->mask == 0) {
            cGenInfoObject_ctor(t);
            cGenInfoObject_Deactivate(t, g->sub);
            g->state = 0;
        }
        cMessage_ctor_cMessageNameR(&msg, g_cDisableMsgClass);
        msg.target = bit;
        msg.vtable = D_004E0860;
        msg.size = 0x40;
        msg.kind = 4;
        cDisableMsg_SendDisabled(&msg, g->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    } else {
        g->state = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220D70(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cGenInfoObject_ctor /* merge_units */
#undef cGenInfoObject_Deactivate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220D70 */

/* merge_units: begin func_00220E60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
typedef struct { char pad[0xC]; char key[0x20]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_12D0;
extern "C" {
void cGOBJ_NetActivate(void);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */



int cGenInfoObject_HasOwner(void* ctx, void* key);
void cGenInfoObject_SetOwner(void* ctx, void* key, int id);
void cGenInfoObject_Activate(void* ctx, void* key);
}
extern "C" void cGenerator_v08(Gen_12D0* g, int who)
{
    char ctx[4];
    g->b2C = 1;
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        cGenInfoObject_ctor(ctx);
        if (who == NetLocalId() && g->maskCC == 0) {
            void* key = g->key;
            cGenInfoObject_SetOwner(ctx, key, NetLocalId());
        }
        cGenInfoObject_Activate(ctx, g->key);
    }
    if (who >= 0) g->maskCC |= 1 << who; else g->maskCC = 0xFF;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220E60(void) {}
#undef cGenInfoObject_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220E60 */

/* merge_units: begin func_00220FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
typedef struct { char pad[0xC]; unsigned int h; } Own_0FD0;
typedef struct { char pad[0xC]; char key[4]; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_0FD0;
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[3]; int f24; } Msg_0FD0;
extern "C" {
extern char D_004E0880[];
extern char g_cEnableMsgClass[];
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */



#if 0 /* merge_units */
Own_0FD0* cGOBJ_GetClosestPlayer(Gen_0FD0* g, int i);
#endif /* merge_units */
#define cGOBJ_GetClosestPlayer(a0, a1) ((Own_0FD0 *)cGOBJ_GetClosestPlayer((void *)(a0), (a1))) /* merge_units */



#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_0FD0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */



void cEnableMsg_SendEnabled(Msg_0FD0* m, int id);
#if 0 /* merge_units */
int cMessage_dtor(Msg_0FD0* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */



}
static inline int Owner_0FD0(Own_0FD0* o) { return ((o->h & 0x7F000000) >> 24) - 1; }
extern "C" void cGenerator_Enable(Gen_0FD0* g, int who)
{
    char ctx[4];
    char ctx2[4];
    Msg_0FD0 msg;
    g->b2C = 1;
    if (g_IsMultiplayer) {
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        if (ok) {
            cGenInfoObject_ctor(ctx);
            if (who < 0) {
                Own_0FD0* o = cGOBJ_GetClosestPlayer(g, 0);
                cGenInfoObject_SetOwner(ctx, g->key, o ? Owner_0FD0(o) : NetLocalId());
            } else {
                if (who == NetLocalId() && g->maskCC == 0) {
                    void* key = g->key;
                    cGenInfoObject_SetOwner(ctx, key, NetLocalId());
                }
            }
            cGenInfoObject_Activate(ctx, g->key);
        } else if (who < 0) {
            int own = -1;
            Own_0FD0* o = cGOBJ_GetClosestPlayer(g, 0);
            if (o) own = Owner_0FD0(o);
            if (own != NetLocalId()) {
                cGenInfoObject_ctor(ctx2);
                cGenInfoObject_SetOwner(ctx2, g->key, own);
            }
        }
        if (who >= 0) g->maskCC |= 1 << who; else g->maskCC = 0xFF;
        cMessage_ctor_cMessageNameR(&msg, g_cEnableMsgClass);
        msg.f24 = who;
        msg.vt = D_004E0880;
        msg.f1C = 0x40;
        msg.f20 = 4;
        cEnableMsg_SendEnabled(&msg, g->id10);
        msg.vt = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220FD0(void) {}
#undef cGenInfoObject_ctor /* merge_units */
#undef cGOBJ_GetClosestPlayer /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00220FD0 */

/* merge_units: begin func_002212D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
extern "C" {
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */



}
extern "C" void cGenerator_v06(Gen_12D0* g)
{
    char ctx[4];
    cGOBJ_NetActivate();
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        cGenInfoObject_ctor(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && cGenInfoObject_HasOwner(ctx, g->key) == 0) {
            void* key = g->key;
            cGenInfoObject_SetOwner(ctx, key, NetLocalId());
        }
        cGenInfoObject_Activate(ctx, g->key);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002212D0(void) {}
#undef cGenInfoObject_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002212D0 */

/* merge_units: begin func_00221420 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cGenInfoObject_ctor(int*);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cGenInfoObject_Deactivate(int*, void*);
#endif /* merge_units */
#define cGenInfoObject_Deactivate(a0, a1) (cGenInfoObject_Deactivate((void *)(a0), (a1))) /* merge_units */


extern void cGOBJ_NetDeactivate(void*);

/* vtable slot 7 of cGenerator. */
void cGenerator_NetDeactivate(char* self) {
    int tmp;
    cGenInfoObject_ctor(&tmp);
    cGenInfoObject_Deactivate(&tmp, self + 0xC);
    cGOBJ_NetDeactivate(self);
}
#undef cGenInfoObject_ctor /* merge_units */
#undef cGenInfoObject_Deactivate /* merge_units */
static inline void merge_flush_func_00221420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00221420 */

/* merge_units: begin func_00221460 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; char f0C[4]; } Gen00221460;
#if 0 /* merge_units */
extern void cGOBJ_Deactivate(Gen00221460* self, int a);
#endif /* merge_units */
#define cGOBJ_Deactivate(a0, a1) (cGOBJ_Deactivate((void *)(a0), (a1))) /* merge_units */

void cGenerator_Deactivate(Gen00221460* self)
{
    cGOBJ_Deactivate(self, 0);
    if (g_IsMultiplayer) {
        int msg[1];
        cGenInfoObject_ctor(msg);
        cGenInfoObject_Deactivate(msg, self->f0C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221460(void) {}
#undef cGOBJ_Deactivate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00221460 */

/* merge_units: begin func_002214B0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
extern "C" {
void cGOBJ_Activate(void* o, int on);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */

}
extern "C" void cGenerator_v15(Gen_12D0* g)
{
    char ctx[4];
    cGOBJ_Activate(g, 0);
    if (g_IsMultiplayer) {
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        cGenInfoObject_ctor(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && cGenInfoObject_HasOwner(ctx, g->key) == 0) {
            void* key = g->key;
            cGenInfoObject_SetOwner(ctx, key, NetLocalId());
        }
        cGenInfoObject_Activate(ctx, g->key);
    }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002214B0(void) {}
#undef cGenInfoObject_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002214B0 */

/* merge_units: begin func_00221610 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_221610 {
    V5(a) V5(b) V5(c) V5(d)
    virtual int IsPlayer(); /* +0x58 */
};
struct Tgt_221610 {
    V5(a) virtual void b0(); virtual void b1();
    virtual void Deactivate(); /* +0x24 */
    V5(c) V5(d) virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void Kill(int f); /* +0x60 */
    V5(f) V5(g) V5(h) V5(i) V5(j) V5(k) V5(l) V5(m) virtual void n0();
    virtual unsigned char State(); /* +0x108 */
    int magic;
    int pad8;
    int id;
    char pad10[0x48];
    Ctl_221610* ctl;
};
struct Hnd_221610 { Tgt_221610* p; int id; };
struct It_221610 { void* n; };
struct List_221610 { int size; void* head[2]; };
struct Gen_221610 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void Enable(int f);   /* +0x28 */
    virtual void Disable(int f);  /* +0x2C */
    V5(b) V5(c) virtual void d0(); virtual void d1(); virtual void d2();
    virtual void EnableNet(int f);  /* +0x64 */
    virtual void DisableNet(int f); /* +0x68 */
    char pad4[0x8C];
    List_221610 list90;
    List_221610 list9C;
    char padA8[0x10];
    float fB8;
    char padBC[4];
    int nC0;
    char padC4[0xD];
    unsigned char bD1;
    unsigned char bD2;
};
struct Ev_221610 { void* vt; char pad4[0x20]; int arg; unsigned char kind; };
struct Ev2_221610 { void* vt; char pad4[0x28]; int id; };
extern "C" {
extern int g_LosResultMsgClass;
extern int D_004A4A68;
extern int D_0051F058;
extern int D_0051F068;
extern int D_004A4A78;
#if 0 /* merge_units */
extern int g_cEnableMsgClass;
#endif /* merge_units */
#define g_cEnableMsgClass (*(int*)&g_cEnableMsgClass) /* merge_units */

#if 0 /* merge_units */
extern int g_cDisableMsgClass;
#endif /* merge_units */
#define g_cDisableMsgClass (*(int*)&g_cDisableMsgClass) /* merge_units */

extern int g_VideoFrameCounter;
extern int D_004F56C0;
extern int g_ActorList;
extern char D_00555070[];
extern unsigned char D_005721C0;
int* cMessage_Name(void* ev);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void* ctx);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */


void cGenerator_NetSpawn(Gen_221610* self, void* m);
Tgt_221610* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#if 0 /* merge_units */
void* cLListIterator_cSafePtr_cGOBJ_ctor_void(It_221610* it);
#endif /* merge_units */
#define cLListIterator_cSafePtr_cGOBJ_ctor_void(a0) (cLListIterator_cSafePtr_cGOBJ_ctor_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cLList_cSafePtr_cGOBJ_Begin(It_221610* out, List_221610* l);
#endif /* merge_units */
#define cLList_cSafePtr_cGOBJ_Begin(a0, a1) (cLList_cSafePtr_cGOBJ_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
It_221610* cLListIterator_cSafePtr_cGOBJ_opAssign(It_221610* dst, It_221610* src);
#endif /* merge_units */
#define cLListIterator_cSafePtr_cGOBJ_opAssign(a0, a1) ((It_221610 *)cLListIterator_cSafePtr_cGOBJ_opAssign((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cLList_cSafePtr_cGOBJ_End(It_221610* out, List_221610* l);
#endif /* merge_units */
#define cLList_cSafePtr_cGOBJ_End(a0, a1) (cLList_cSafePtr_cGOBJ_End((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
int opNe_cLListIteratorR_cLListIteratorR_3(It_221610* a, It_221610* b);
#endif /* merge_units */
#define opNe_cLListIteratorR_cLListIteratorR_3(a0, a1) (opNe_cLListIteratorR_cLListIteratorR_3((GenListPos *)(a0), (GenListPos *)(a1))) /* merge_units */

#if 0 /* merge_units */
Hnd_221610* cLListIterator_cSafePtr_cGOBJ_opMul(It_221610* it);
#endif /* merge_units */
#define cLListIterator_cSafePtr_cGOBJ_opMul(a0) ((Hnd_221610 *)cLListIterator_cSafePtr_cGOBJ_opMul((GenListPos *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cSafePtr_cGOBJ_opEq(Hnd_221610* a, Hnd_221610* b);
#endif /* merge_units */
#define cSafePtr_cGOBJ_opEq(a0, a1) ((int)cSafePtr_cGOBJ_opEq((H00220410 *)(a0), (H00220410 *)(a1))) /* merge_units */

#if 0 /* merge_units */
It_221610* cLListIterator_cSafePtr_cGOBJ_opInc(It_221610* it);
#endif /* merge_units */
#define cLListIterator_cSafePtr_cGOBJ_opInc(a0) ((It_221610 *)cLListIterator_cSafePtr_cGOBJ_opInc((GenListPos *)(a0))) /* merge_units */

#if 0 /* merge_units */
It_221610* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(It_221610* dst, It_221610* src);
#endif /* merge_units */
#define cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(a0, a1) ((It_221610 *)cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_tail(List_221610* l);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) (std_list_deleter_cSafePtr_cGOBJ_tail((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
It_221610* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(It_221610* it, void* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((It_221610 *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (a1))) /* merge_units */

void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(It_221610* ret, List_221610* l, It_221610* pos);
void cBaseObjList_Remove(int a, Tgt_221610* o);
void cScriptInterpreter_RemoveFromAllGroups(void* a, Tgt_221610* o);
void cSystem_ActualScheduleDelete(Tgt_221610* o, float f);
}
static inline bool IsType_221610(void* m, int* cls) { int t = *cMessage_Name(m); return t == *cls; }
static inline bool IsDying_221610(Tgt_221610* o) { unsigned char s = o->State(); return s == 2 || s == 3; }
static inline int IsAuth_221610(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" bool cGenerator_HandleMessage(Gen_221610* self, void* msg)
{
    char ctx[4];
    int id;
    It_221610 found1;
    It_221610 found2;
    It_221610 ret2;
    It_221610 arg2;
    It_221610 ret1;
    It_221610 arg1;
    It_221610 endc1;
    It_221610 endc2;
    int none1;
    int none2;
    It_221610 it1;
    It_221610 beg1;
    It_221610 end1;
    It_221610 it2;
    It_221610 beg2;
    It_221610 end2;
    Hnd_221610 h1;
    Hnd_221610 h2;
    Ev_221610* m = (Ev_221610*)msg;
    bool r;
    if (IsType_221610(m, &g_LosResultMsgClass)) {
        r = 1;
    } else if (IsType_221610(m, &D_004A4A68)) {
        if (m->kind == 1)
            cGenInfoObject_ctor(ctx);
        r = 1;
    } else if (IsType_221610(m, &D_0051F058)) {
        cGenerator_NetSpawn(self, m);
    } else if (IsType_221610(m, &D_0051F068)) {
        Tgt_221610* o;
        id = ((Ev2_221610*)m)->id;
        o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        if (o) {
            bool pl = 0;
            if (o->ctl && o->ctl->IsPlayer())
                pl = 1;
            if (pl)
                o->Kill(0);
            else
                o->Deactivate();
            {
                int* pid = &h1.id;
                *pid = -1;
                h1.p = o;
                *pid = *(o ? &o->id : (none1 = -1, &none1));
            }
            cLListIterator_cSafePtr_cGOBJ_ctor_void(&it1);
            cLList_cSafePtr_cGOBJ_Begin(&beg1, &self->list90);
            cLListIterator_cSafePtr_cGOBJ_opAssign(&it1, &beg1);
            for (; cLList_cSafePtr_cGOBJ_End(&end1, &self->list90), opNe_cLListIteratorR_cLListIteratorR_3(&it1, &end1); cLListIterator_cSafePtr_cGOBJ_opInc(&it1)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it1), &h1)) break; //
            cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found1, &it1);
            {
                void* f1 = found1.n;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                if (f1 != endc1.n) {
                    if (self->list9C.size > 0) {
                        void* f2;
                        int* pid = &h2.id;
                        *pid = -1;
                        h2.p = o;
                        *pid = *(o ? &o->id : (none2 = -1, &none2));
                        cLListIterator_cSafePtr_cGOBJ_ctor_void(&it2);
                        cLList_cSafePtr_cGOBJ_Begin(&beg2, &self->list9C);
                        cLListIterator_cSafePtr_cGOBJ_opAssign(&it2, &beg2);
                        for (; cLList_cSafePtr_cGOBJ_End(&end2, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it2, &end2); cLListIterator_cSafePtr_cGOBJ_opInc(&it2)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it2), &h2)) break; //
                        cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found2, &it2);
                        f2 = found2.n;
                        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                        if (f2 != endc2.n) {
                            arg2.n = f2;
                            std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret2, &self->list9C, &arg2);
                        }
                    }
                    {
                        if (!IsDying_221610(o) && !self->bD2)
                            self->nC0--;
                    }
                    arg1.n = f1;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret1, &self->list90, &arg1);
                }
            }
            cBaseObjList_Remove(g_ActorList, o);
            cScriptInterpreter_RemoveFromAllGroups(D_00555070, o);
            if (o->magic == (int)0xBEBAAFDE)
                cSystem_ActualScheduleDelete(o, 1.0f);
        }
        r = 1;
    } else if (IsType_221610(m, &D_004A4A78)) {
        unsigned char k = m->kind;
        if (k == 0) {
            self->bD1 = m->arg != 0;
        } else if (k == 1) {
            self->fB8 = m->arg;
        } else if (k == 2) {
            self->nC0 = 0;
        } else if (k == 3) {
            if (D_004F56C0 != g_VideoFrameCounter)
                D_004F56C0 = g_VideoFrameCounter;
        }
        r = 1;
    } else {
        if (IsType_221610(m, &g_cEnableMsgClass)) {
            if (!g_IsMultiplayer || IsAuth_221610())
                self->EnableNet(m->arg);
            else
                self->Enable(m->arg);
        } else if (IsType_221610(m, &g_cDisableMsgClass)) {
            if (!g_IsMultiplayer || IsAuth_221610())
                self->DisableNet(m->arg);
            else
                self->Disable(m->arg);
        }
        r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221610(void) {}
#undef g_cEnableMsgClass /* merge_units */
#undef g_cDisableMsgClass /* merge_units */
#undef cGenInfoObject_ctor /* merge_units */
#undef cLListIterator_cSafePtr_cGOBJ_ctor_void /* merge_units */
#undef cLList_cSafePtr_cGOBJ_Begin /* merge_units */
#undef cLListIterator_cSafePtr_cGOBJ_opAssign /* merge_units */
#undef cLList_cSafePtr_cGOBJ_End /* merge_units */
#undef opNe_cLListIteratorR_cLListIteratorR_3 /* merge_units */
#undef cLListIterator_cSafePtr_cGOBJ_opMul /* merge_units */
#undef cSafePtr_cGOBJ_opEq /* merge_units */
#undef cLListIterator_cSafePtr_cGOBJ_opInc /* merge_units */
#undef cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00221610 */
