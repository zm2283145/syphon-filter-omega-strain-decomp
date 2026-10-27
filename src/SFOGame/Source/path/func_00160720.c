#pragma cplusplus on
#include "types.h"
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
    virtual M GetMatrix();
    char pad4[0x54];
    Actor* owner;
};
struct PNode;
struct Path {
    V pos;
    V dir;
    char pad20[0x20];
    float dist;
    float dist2;
    char pad48[4];
    int node;
    int cur;
    char pad54[0x1C];
    Actor* actor;
};
struct Msg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
PNode* cAIPathData_GetNode(int id);
void cNode_GetLoc(V* out, PNode* node);
void cPathNavigator_SetNodeIndex(Path* p, int id);
int cAIPathData_GetLinkType(int a, int b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, Actor* to, int flags);
void cMessage_dtor(void* m, int flags);
unsigned char cPathNavigator_StartPathSegment_cVectorR_int(Path* self, V* target, int seg);
}
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
unsigned char cPathNavigator_StartPathSegment_cVectorR_int(Path* self, V* target, int seg)
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
            Notify(self, 7, cAIPathData_GetLinkType(self->node, seg));
        }
        self->cur = seg;
    }
    if (!(self->dist <= 2.0f)) {
        self->pos = *target;
        r = 1;
    }
    return r;
}


