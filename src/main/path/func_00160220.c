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
PNode* NpcPath_GetNode(int id);
void Node_GetTranslation(V4* out, PNode* node);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, Actor* to, int flags);
void cMessage_dtor(void* m, int flags);
unsigned char NpcPath_SetSegment(Path* p, int seg);
void NpcPath_HoldNode(Path* p, int node);
int NpcPath_NextPatrolNode(int seg);
unsigned char NpcRoute_Step(Path* p);
void func_002D7BE0(Msg2* m, int a, Route* r);
}
static inline void Push(Route* r, int v) { r->nodes[r->count] = v; r->count++; }
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
static inline void Notify5(Path* p, unsigned char kind)
{
    Msg msg;
    Msg* m;
    int i = p->seg;
    m = &msg;
    Construct(m, kind, i);
    Actor* a = p->actor; Actor* o = a->owner; Actor* to = a; if (!o) { asm { .set reorder } } else to = o;
    Event_Send(&msg, to, 0);
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

extern "C" void NpcPath_Update(Path* self)
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
        Node_GetTranslation(&t, NpcPath_GetNode(node));
        VSub(&t, &t, &pos);
        if (!(LengthSq(&t) <= 4.0f)) {
            self->prev = self->node;
            self->node = -1;
        }
    }
    if (!self->arrived) return;
    self->arrived = 0;
    if (self->patrol) {
        int next = NpcPath_NextPatrolNode(self->seg);
        if (next >= 0) {
            Notify5(self, 5);
            self->held = !NpcPath_SetSegment(self, next);
            self->f5C = NpcPath_GetNode(self->seg)->f7C;
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
                        Event_Construct(m, D_0051F0C0);
                        m->vt = D_004DE510;
                        m->f38 = -1.0f;
                        m->f3C = -1.0f;
                        m->f40 = -1.0f;
                        for (i = 0; i != 2; i++)
                            m->ids[i] = -1;
                        func_002D7BE0(&m2, self->actor->f10, self->route);
                        m2.vt = D_004DE510;
                        cMessage_dtor(&m2, 0);
                    }
                }
            }
        } else {
            PNode* n = NpcPath_GetNode(self->seg);
            NpcPath_HoldNode(self, self->seg);
            self->held = 1;
            Notify(self, 6, self->seg);
            if (!(n->flags & 0x80))
                NpcPath_HoldNode(self, -1);
        }
    } else {
        self->held = !NpcRoute_Step(self);
    }
}
