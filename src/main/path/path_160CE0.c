/*
 * main/path: range (12 files, 00160CE0-00161840)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vc_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_00160CE0 */
#pragma push /* merge_units */
#pragma bool off
#pragma cplusplus on
struct CxStartActor{char pad[0x10];int id;unsigned char networked;};
struct CxStartRoute{char pad[0x10];int type;char pad14[0xC];int*nodes;int unknown;int count;};
struct CxStartPath{char pad[0x48];int remaining;int node;int segB;int segA;int type;int unknown;unsigned long long hold:1;unsigned long long flag1:1;unsigned long long flag2:1;unsigned long long stopped:1;unsigned long long rest:4;char pad64[0xC];CxStartActor*actor;CxStartRoute*route;};
struct CxStartMsg{void*vt;char pad[0x28];int a,b;int unk34;float x,y,z;};
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_0051F0C0[],D_004DE510[];
void cMessage_ctor_cMessageNameR(CxStartMsg*,void*);
void cMessage_dtor(CxStartMsg*,int);
void cNetPathMsg_SendPath(CxStartMsg*,int,CxStartRoute*);
void cPathNavigator_SetNodeIndex(CxStartPath*,int);
int cPathNavigator_NextPathSegment(CxStartPath*);
}
static inline void CxStart_Construct(CxStartMsg*m,CxStartMsg*loc){cMessage_ctor_cMessageNameR(m,D_0051F0C0);loc->x=-1.0f;loc->vt=D_004DE510;loc->y=-1.0f;loc->z=-1.0f;m->a=-1;m->b=-1;}
static inline void CxStart_Destroy(CxStartMsg*m,CxStartMsg*loc){loc->vt=D_004DE510;cMessage_dtor(m,0);}
#pragma opt_propagation off
extern "C" int cPathNavigator_NewPath(CxStartPath*self){
 if(g_IsMultiplayer && self->actor->networked){CxStartMsg msg;CxStartMsg*m=&msg;CxStart_Construct(m,&msg);cNetPathMsg_SendPath(m,self->actor->id,self->route);CxStart_Destroy(m,&msg);}
 if(self->hold){self->hold=0;cPathNavigator_SetNodeIndex(self,-1);}
 self->remaining=self->route->count;
 int n=self->remaining;
if(n>1){int*end;int seg;seg=self->segA;unsigned offset=n<<2;end=(int*)(offset+(unsigned)self->route->nodes);if(seg==end[-1] && self->segB==end[-2])self->remaining=n-1;}
 self->segB=-1;
 self->type=self->route->type;
 self->stopped=!cPathNavigator_NextPathSegment(self);
 return !self->stopped;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160CE0 */

/* merge_units: begin func_00160E60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct T_0E60 { char pad[0x14]; int last; int first; char pad1C[4]; int* ids; int pad24; int n; };
struct S_0E60 { char pad[0x74]; T_0E60* t; };
extern "C" {
extern char D_0049C1B8[];
}
extern "C" void cPathNavigator_Deactivate(S_0E60* self)
{
    T_0E60* t = self->t;
    if (t) {
        int* a;
        if (t->n > 0) {
            t->last = t->ids[t->n - 1];
            t->first = t->ids[0];
        } else {
            t->last = -1;
        }
        a = t->ids;
        if (a) {
            {
                AllocGuard g;
                cMemMan_Deallocate(0, a, D_0049C1B8, 0x508);
            }
            t->ids = 0;
            t->n = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160E60 */

/* merge_units: begin func_00160F60 */
#pragma push /* merge_units */
#pragma cplusplus on
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
    char pad4[0x54];
    Actor* owner;
};
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
extern char g_Game[];
extern char g_NpcRouteMgr[];
void* cMemMan_Allocate(int pool, int size, void* file, int line);
void* cSystemContainer_GetSystem(void*, void*);
}
struct Route {
    char pad0[0x10];
    int x10; int x14; int x18; char pad1C[4];
    int* nodes; int cap; int count; char pad2C[4];
    Route(int c) { cap = c; nodes = 0; count = 0; x14 = -1; x10 = -1; }
    void* operator new(unsigned int sz) { void* p; AllocGuard g; p = cMemMan_Allocate(0, sz, D_0049C1B8, 0x5CC); return p; }
    void Reserve() { if (!nodes) { int sz = cap * 4; int* q; { AllocGuard g; q = (int*)cMemMan_Allocate(0, sz, D_0049C1B8, 0x4F2); } nodes = q; } }
};
struct PNode { char pad[0x64]; int flags; char pad68[0x14]; int f7C; };
struct Path {
    V4 pos;
    char pad10[0x10];
    V4 x20;
    char pad30[0x1C];
    int node;
    int seg;
    char pad54[8];
    int f5C;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    char pad61[0xF];
    Actor* actor;
    Route* route;
    int x78;
};
struct Msg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
PNode* cAIPathData_GetNode(int id);
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((CxStartMsg *)(a0), (a1))) /* merge_units */

void QueueMessage_cMessageR_cSystemP_int(void* m, Actor* to, int flags);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((CxStartMsg *)(a0), (a1))) /* merge_units */

unsigned char cPathNavigator_StartPathSegment_int(Path* p, int seg);
#if 0 /* merge_units */
void cPathNavigator_SetNodeIndex(Path* p, int node);
#endif /* merge_units */
#define cPathNavigator_SetNodeIndex(a0, a1) (cPathNavigator_SetNodeIndex((CxStartPath *)(a0), (a1))) /* merge_units */

int cAIPathData_GetNextPatrolPathNodeIndex(int seg);
unsigned char cPathSystem_RestorePath(void* r, int to, int from, Route* obj);
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
static inline void Copy(V4* d, V4* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void GetPos(V4* out, Path* p)
{
    Mat m = p->actor->GetMatrix(); V4* dp = out; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; __asm__ volatile("lq %0, 0x0(%0)" : "=r"(x) : "0"(s));__asm__ volatile("sq %0, 0x0(%1)" : : "r"(x), "r"(dp) : "memory");
}
#pragma opt_propagation off

extern "C" void cPathNavigator_Activate(Path* self)
{
    if (self->b6) {
        { int z = 0; self->b6 = z; }
        if (self->node >= 0) {
            PNode* n = cAIPathData_GetNode(self->node);
            cPathNavigator_SetNodeIndex(self, self->node);
            Copy(&self->pos, &self->x20);
            if (n->flags & 8) {
                self->b0 = 1;
                self->b1 = 1;
                int next = cAIPathData_GetNextPatrolPathNodeIndex(self->node);
                if (next >= 0) {
                    self->seg = self->node;
                    self->b3 = !cPathNavigator_StartPathSegment_int(self, next);
                    { int z = 0; self->b4 = z; }
                    if (!self->b3)
                        Notify(self, 4, -1);
                }
            }
            if (n->f7C >= 0)
                self->f5C = n->f7C;
        } else {
            GetPos(&self->x20, self);
            Copy(&self->pos, &self->x20);
        }
    }
    if (!self->route)
        self->route = new Route(self->x78);
    Route* r = self->route;
    r->Reserve();
    if (r->x14 >= 0)
        cPathSystem_RestorePath(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), r->x14, r->x18, r);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cPathNavigator_SetNodeIndex /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160F60 */

/* merge_units: begin func_001612D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x7C]; int x7C; } Node_12D0;
typedef struct { char pad[0x4C]; int start; char pad2[0x5C - 0x50]; int val; unsigned char flags; } S_12D0;
#if 0 /* merge_units */
extern int cAIPathData_GetNextPatrolPathNodeIndex(int id);
#endif /* merge_units */
#define cAIPathData_GetNextPatrolPathNodeIndex(a0) (cAIPathData_GetNextPatrolPathNodeIndex((a0))) /* merge_units */

#if 0 /* merge_units */
extern Node_12D0* cAIPathData_GetNode(int id);
#endif /* merge_units */
#define cAIPathData_GetNode(a0) ((Node_12D0 *)cAIPathData_GetNode((a0))) /* merge_units */

int cPathNavigator_GetGroupIndexForPatrolPath(S_12D0* self)
{
    int r = self->val;
    if (r < 0 && (self->flags & 1)) {
        int id = self->start;
        while (id >= 0 && r < 0) {
            id = cAIPathData_GetNextPatrolPathNodeIndex(id);
            if (id == self->start)
                break;
            if (id >= 0) {
                int v = cAIPathData_GetNode(id)->x7C;
                if (v)
                    r = v;
            }
        }
    }
    return r;
}
#undef cAIPathData_GetNextPatrolPathNodeIndex /* merge_units */
#undef cAIPathData_GetNode /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001612D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001612D0 */

/* merge_units: begin func_00161370 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; unsigned char lo:4; unsigned char a:1; unsigned char b:1; } PfD4;
void cPathNavigator_SetDestinationReached(PfD4* p, int v)
{
    if (p->b != (unsigned char)v) {
        p->a = v;
        p->b = v;
    } else {
        p->a = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161370 */

/* merge_units: begin func_001613E0 */
#pragma push /* merge_units */
static inline void QCopy_13E0(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
void cPathNavigatorTransfer_Put(void* src, void* dst)
{
    QCopy_13E0(dst, src, 0x70);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001613E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001613E0 */

/* merge_units: begin func_00161450 */
#pragma push /* merge_units */
static inline void QCopy_1450(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
void cPathNavigatorTransfer_Get(void* dst, void* src)
{
    QCopy_1450(dst, src, 0x70);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161450 */

/* merge_units: begin func_001614C0 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QCopy_14C0(void* dst, void* src, int n0)
{
    int n;
    int t;
    int m;
    char* d;
    n = n0;
    d = (char*)dst;

    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu d, d, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

extern "C" {
typedef struct { char pad[0x14]; int id; int arg; int pad1c; void* buf; int count; } S_14C0;
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (void *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void* cSystemContainer_GetSystem(void* reg, void* key);
#endif /* merge_units */
#define cSystemContainer_GetSystem(a0, a1) (cSystemContainer_GetSystem((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
unsigned char cPathSystem_RestorePath(void* svc, int id, int arg, S_14C0* s);
#endif /* merge_units */
#define cPathSystem_RestorePath(a0, a1, a2, a3) (cPathSystem_RestorePath((a0), (a1), (a2), (Route *)(a3))) /* merge_units */

}
#pragma opt_common_subs off
extern "C" void cPathTransfer_Put(void* src, S_14C0* self)
{
    QCopy_14C0(self, src, 0x20);
    if (!self->buf) {
        int size = self->count * 4;
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, size, D_0049C1B8, 0x4F2);
        }
        self->buf = p;
    }
    if (self->id >= 0)
        cPathSystem_RestorePath(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->id, self->arg, self);
}
#undef cMemMan_Allocate /* merge_units */
#undef cSystemContainer_GetSystem /* merge_units */
#undef cPathSystem_RestorePath /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001614C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001614C0 */

/* merge_units: begin func_00161610 */
#pragma push /* merge_units */
typedef struct { __int128 q; int x10; int x14; int x18; int pad1c; int* list; int pad24; int count; } S_1610;
void cPathTransfer_Get(S_1610* dst, S_1610* src)
{
    dst->q = src->q;
    dst->x10 = src->x10;
    if (!src->list) {
        dst->x14 = src->x14;
        dst->x18 = src->x18;
    } else if (src->count > 0) {
        dst->x14 = src->list[src->count - 1];
        dst->x18 = src->list[0];
    } else {
        dst->x14 = -1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161610 */

/* merge_units: begin func_00161680 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct T_1720 { char pad[0x14]; int last; int first; char pad1C[4]; int* ids; int pad24; int n; };
extern "C" T_1720* cPathNavigator_dtor(T_1720* t, short del); /* gsynth: defined below */
#pragma pop

extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int flag);
#if 0 /* merge_units */
extern void cPathNavigator_dtor(void* p, int flag);
#endif /* merge_units */
#define cPathNavigator_dtor(a0, a1) ((void)cPathNavigator_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void operator_delete(void* p);
typedef struct { char pad[0x74]; void* p; } S_1680;
S_1680* func_00161680(S_1680* self, short flag)
{
    if (self) {
        void* p = self->p;
        if (p) {
            int g[1];
            cTimerDisable_ctor(g);
            cPathNavigator_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_0049C1B8, 0x542);
            cTimerDisable_dtor(g, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#undef cPathNavigator_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161680 */

/* merge_units: begin func_00161720 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void operator_delete(void* p);
}
extern "C" T_1720* cPathNavigator_dtor(T_1720* t, short del)
{
    if (t) {
        int* a;
        if (t->n > 0) {
            t->last = t->ids[t->n - 1];
            t->first = t->ids[0];
        } else {
            t->last = -1;
        }
        a = t->ids;
        if (a) {
            {
                AllocGuard g;
                cMemMan_Deallocate(0, a, D_0049C1B8, 0x508);
            }
            t->ids = 0;
            t->n = 0;
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161720 */

/* merge_units: begin func_00161840 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
typedef struct {
    __int128 pad0;
    __int128 q10;
    char pad20[0x4C - 0x20];
    int x4C; int x50; int x54; int x58; int x5C;
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1;
    unsigned char b4 : 1; unsigned char b5 : 1; unsigned char b6 : 1; unsigned char b7 : 1;
    char pad61[0x70 - 0x61];
    int x70; int x74; int x78;
} S_1840;
S_1840* cPathNavigator_ctor(S_1840* self, int a, int b, int c)
{
    self->x4C = c;
    self->x70 = a;
    self->x78 = b;
    self->x74 = 0;
    self->x5C = -1;
    self->x50 = -1;
    self->x54 = -1;
    self->x58 = -1;
    { int z = 0; self->b0 = z; self->b1 = z; self->b2 = z; }
    self->b3 = 1;
    self->b4 = 1;
    self->b5 = 1;
    self->b6 = 1;
    VZeroF(&self->q10);
    return self;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00161840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00161840 */
