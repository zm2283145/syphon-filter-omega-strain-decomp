#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
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
extern char D_0049C1B8[];
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
void* Mem_Alloc(int pool, int size, void* file, int line);
void* Service_Lookup(void*, void*);
}
struct Route {
    char pad0[0x10];
    int x10; int x14; int x18; char pad1C[4];
    int* nodes; int cap; int count; char pad2C[4];
    Route(int c) { cap = c; nodes = 0; count = 0; x14 = -1; x10 = -1; }
    void* operator new(unsigned int sz) { void* p; AllocGuard g; p = Mem_Alloc(0, sz, D_0049C1B8, 0x5CC); return p; }
    void Reserve() { if (!nodes) { int sz = cap * 4; int* q; { AllocGuard g; q = (int*)Mem_Alloc(0, sz, D_0049C1B8, 0x4F2); } nodes = q; } }
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
PNode* NpcPath_GetNode(int id);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, Actor* to, int flags);
void cMessage_dtor(void* m, int flags);
unsigned char NpcPath_SetSegment(Path* p, int seg);
void NpcPath_HoldNode(Path* p, int node);
int NpcPath_NextPatrolNode(int seg);
unsigned char NpcPath_RebuildRoute(void* r, int to, int from, Route* obj);
}
static inline void Construct(Msg* m, unsigned char kind, int id) { Event_Construct(m, D_004ED9B8); m->vt = D_004D9760; m->kind = kind; m->id = id; }
static inline void Destroy(Msg* loc) { loc->vt = D_004D9760; cMessage_dtor(loc, 0); }
static inline void Notify(Path* p, unsigned char kind, int id)
{
    Msg msg;
    Msg* m = &msg;
    Construct(m, kind, id);
    Actor* a = p->actor; Actor* o = a->owner; Actor* to = a; if (!o) { asm { .set reorder } } else to = o;
    Event_Send(&msg, to, 0);
    Destroy(&msg);
}
static inline void Copy(V4* d, V4* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void GetPos(V4* out, Path* p)
{
    Mat m = p->actor->GetMatrix(); V4* dp = out; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; __asm__ volatile("lq %0, 0x0(%0)" : "=r"(x) : "0"(s));__asm__ volatile("sq %0, 0x0(%1)" : : "r"(x), "r"(dp) : "memory");
}
#pragma opt_propagation off

extern "C" void NpcPath_Start(Path* self)
{
    if (self->b6) {
        { int z = 0; self->b6 = z; }
        if (self->node >= 0) {
            PNode* n = NpcPath_GetNode(self->node);
            NpcPath_HoldNode(self, self->node);
            Copy(&self->pos, &self->x20);
            if (n->flags & 8) {
                self->b0 = 1;
                self->b1 = 1;
                int next = NpcPath_NextPatrolNode(self->node);
                if (next >= 0) {
                    self->seg = self->node;
                    self->b3 = !NpcPath_SetSegment(self, next);
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
        NpcPath_RebuildRoute(Service_Lookup(D_004FFB50, g_NpcRouteMgr), r->x14, r->x18, r);
}



