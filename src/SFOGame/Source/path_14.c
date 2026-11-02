/*
 * SFOGame/Source/path: 3 files, 00160220-00160720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00160220 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vc_copy.h"
struct V4 { __int128 q; V4() {} };
struct Mat { V4 r[4]; Mat() {} };
class Actor {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual Mat GetMatrix();
    char pad4[0xC];
    int f10;
    unsigned char f14;
    char pad15[0x43];
    Actor* owner;
};
struct Route { char pad[0x20]; int* nodes; int cap; int count; };
struct PNode { char pad[0x64]; int flags; char pad68[0x14]; int f7C; };
struct Path {
    V4 pos;
    char pad10[0x30];
    float dist;
    char pad44[8];
    int node;
    int seg;
    int prev;
    char pad58[4];
    int f5C;
    unsigned char patrol : 1;
    unsigned char b1 : 2;
    unsigned char held : 1;
    unsigned char arrived : 1;
    unsigned char b5 : 3;
    char pad61[0xF];
    Actor* actor;
    Route* route;
};
struct Msg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
struct Msg2 { void* vt; char pad[0x28]; int ids[3]; float f38; float f3C; float f40; char pad44[0xC]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
extern char D_0051F0C0[];
extern char D_004DE510[];
extern unsigned char g_IsMultiplayer;
PNode* cAIPathData_GetNode(int id);
#if 0 /* merge_units */
void cNode_GetLoc(V4* out, PNode* node);
#endif /* merge_units */
void cNode_GetLoc(void*, void*); /* merge_units */
#define cNode_GetLoc(a0, a1) (cNode_GetLoc((void *)(a0), (void *)(a1))) /* merge_units */

void cMessage_ctor_cMessageNameR(void* m, void* type);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* m, Actor* to, int flags);
#endif /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int); /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

unsigned char cPathNavigator_StartPathSegment_int(Path* p, int seg);
#if 0 /* merge_units */
void cPathNavigator_SetNodeIndex(Path* p, int node);
#endif /* merge_units */
void cPathNavigator_SetNodeIndex(void*, int); /* merge_units */
#define cPathNavigator_SetNodeIndex(a0, a1) (cPathNavigator_SetNodeIndex((void *)(a0), (a1))) /* merge_units */

int cAIPathData_GetNextPatrolPathNodeIndex(int seg);
unsigned char cPathNavigator_NextPathSegment(Path* p);
void cNetPathMsg_SendPath(Msg2* m, int a, Route* r);
}
static inline void Push(Route* r, int v) { r->nodes[r->count] = v; r->count++; }
static inline void Construct(Msg* m, unsigned char kind, int id) { cMessage_ctor_cMessageNameR(m, D_004ED9B8); m->vt = D_004D9760; m->kind = kind; m->id = id; }
static inline void Destroy(Msg* loc) { loc->vt = D_004D9760; cMessage_dtor(loc, 0); }
static inline void Notify(Path* p, unsigned char kind, int id)
{
    Msg msg;
    Msg* m = &msg;
    Construct(m, kind, id);
    Actor* a = p->actor; Actor* o = a->owner; Actor* to = a; if (!o) { asm { .set reorder } } else to = o;
    QueueMessage_cMessageR_cSystemP_int(&msg, to, 0);
    Destroy(&msg);
}
static inline void Notify5(Path* p, unsigned char kind)
{
    Msg msg;
    Msg* m;
    int i = p->seg;
    m = &msg;
    Construct(m, kind, i);
    Actor* a = p->actor; Actor* o = a->owner; Actor* to = a; if (!o) { asm { .set reorder } } else to = o;
    QueueMessage_cMessageR_cSystemP_int(&msg, to, 0);
    Destroy(&msg);
}
static inline void GetPos(V4* out, Path* p)
{
    Mat m = p->actor->GetMatrix(); V4* dp = out; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } VStoreN(dp, x);
}
static inline void VSub(V4* r, V4* a, V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline float Length(V4* a)
{
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory");
    return r;
}
static inline float LengthSq(V4* a)
{
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory");
    return r;
}
#pragma opt_propagation off

extern "C" void cPathNavigator_Update(Path* self)
{
    V4 pos;
    V4 d;
    V4 t;
    GetPos(&pos, self);
    if (self->held) return;
    { V4* s = &self->pos; V4* dd; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); dd = &d; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(dd) : "memory"); }
    VSub(&d, &d, &pos);
    self->dist = Length(&d);
    int node = self->node;
    if (node >= 0) {
        cNode_GetLoc(&t, cAIPathData_GetNode(node));
        VSub(&t, &t, &pos);
        if (!(LengthSq(&t) <= 4.0f)) {
            self->prev = self->node;
            self->node = -1;
        }
    }
    if (!self->arrived) return;
    self->arrived = 0;
    if (self->patrol) {
        int next = cAIPathData_GetNextPatrolPathNodeIndex(self->seg);
        if (next >= 0) {
            Notify5(self, 5);
            self->held = !cPathNavigator_StartPathSegment_int(self, next);
            self->f5C = cAIPathData_GetNode(self->seg)->f7C;
            if (g_IsMultiplayer && self->actor->f14) {
                Route* r = self->route;
                if (r->nodes) {
                    r->count = 0;
                    Push(self->route, next);
                    Push(self->route, self->node);
                    Push(self->route, self->prev);
                    {
                        Msg2 m2;
                        Msg2* m = &m2;
                        int i;
                        cMessage_ctor_cMessageNameR(m, D_0051F0C0);
                        m->vt = D_004DE510;
                        m->f38 = -1.0f;
                        m->f3C = -1.0f;
                        m->f40 = -1.0f;
                        for (i = 0; i != 2; i++)
                            m->ids[i] = -1;
                        cNetPathMsg_SendPath(&m2, self->actor->f10, self->route);
                        m2.vt = D_004DE510;
                        cMessage_dtor(&m2, 0);
                    }
                }
            }
        } else {
            PNode* n = cAIPathData_GetNode(self->seg);
            cPathNavigator_SetNodeIndex(self, self->seg);
            self->held = 1;
            Notify(self, 6, self->seg);
            if (!(n->flags & 0x80))
                cPathNavigator_SetNodeIndex(self, -1);
        }
    } else {
        self->held = !cPathNavigator_NextPathSegment(self);
    }
}
#undef cNode_GetLoc /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cPathNavigator_SetNodeIndex /* merge_units */
static inline void merge_flush_func_00160220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00160220 */

/* merge_units: begin func_001606C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetPathMsg_dtor, D_004DE510, cMessage_dtor)
static inline void merge_flush_func_001606C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001606C0 */

/* merge_units: begin func_00160720 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
} __attribute__((aligned(16)));
struct M { V r[4]; M() {} };
static inline int IsZero(const V* v)
{
    int k, fl; unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Normalize(V* v, float* len) {
    int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%1); qmfc2.ni %0, $vf4; sw %0, 0x0(%2)" : "=&r"(t) : "r"(v), "r"(len) : "memory");
}
class Actor_00160720 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual M GetMatrix();
    char pad4[0x54];
    Actor_00160720* owner;
};
struct PNode;
struct Path_00160720 {
    V pos;
    V dir;
    char pad20[0x20];
    float dist;
    float dist2;
    char pad48[4];
    int node;
    int cur;
    char pad54[0x1C];
    Actor_00160720* actor;
};
extern "C" {
#if 0 /* merge_units */
void cNode_GetLoc(V* out, PNode* node);
#endif /* merge_units */
#define cNode_GetLoc(a0, a1) (cNode_GetLoc((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cPathNavigator_SetNodeIndex(Path_00160720* p, int id);
#endif /* merge_units */
#define cPathNavigator_SetNodeIndex(a0, a1) (cPathNavigator_SetNodeIndex((void *)(a0), (a1))) /* merge_units */

int cAIPathData_GetLinkType(int a, int b);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* m, Actor_00160720* to, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

unsigned char cPathNavigator_StartPathSegment_cVectorR_int(Path_00160720* self, V* target, int seg);
}
static inline void Notify_00160720(Path_00160720* p, unsigned char kind, int id)
{
    Msg msg;
    Msg* m = &msg;
    Construct(m, kind, id);
    Actor_00160720* a = p->actor; Actor_00160720* o = a->owner; Actor_00160720* to = a; if (!o) { asm { .set reorder } } else to = o;
    QueueMessage_cMessageR_cSystemP_int(&msg, to, 0);
    Destroy(&msg);
}
unsigned char cPathNavigator_StartPathSegment_cVectorR_int(Path_00160720* self, V* target, int seg)
{
    unsigned char r = 0;
    V pos;
    if (self->cur >= 0) {
        V t;
        cNode_GetLoc(&t, cAIPathData_GetNode(self->cur));
        pos = t;
        cPathNavigator_SetNodeIndex(self, self->cur);
    } else {
        M m = self->actor->GetMatrix();
        M* pm = &m; pos = pm->r[3];
    }
    self->dir = *target - pos;
    if (IsZero(&self->dir)) self->dist = 0.0f;
    else Normalize(&self->dir, &self->dist);
    self->dist2 = self->dist;
    if (self->cur != seg) {
        if (self->node >= 0 && seg >= 0) {
            Notify_00160720(self, 7, cAIPathData_GetLinkType(self->node, seg));
        }
        self->cur = seg;
    }
    if (!(self->dist <= 2.0f)) {
        self->pos = *target;
        r = 1;
    }
    return r;
}
#undef cNode_GetLoc /* merge_units */
#undef cPathNavigator_SetNodeIndex /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00160720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00160720 */
