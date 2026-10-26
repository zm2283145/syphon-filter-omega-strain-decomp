/*
 * main/particle: range (9 files, 003A26A0-003A33B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003A26A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* ParticleDefs_SlotForId(void* self, int n);
extern char D_0053B544[];
extern char D_004BC5D0[];
}

struct Desc3A26A0 {
    char pad0[4];
    unsigned char b4;
    char pad5[0x5C - 5];
    int prio;
};

struct V43A26A0 {
    float x, y, z, w;
};

struct Node3A26A0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Desc3A26A0* GetDesc();
    virtual void v4();
    virtual int IsAttached();
    Node3A26A0* next;
    Node3A26A0* prev;
    unsigned char bC;
};

struct Head3A26A0 {
    void* vt;
    Node3A26A0* next;
    Node3A26A0* prev;
};

struct Mgr3A26A0 {
    void* vt;
    Head3A26A0 head;
    Head3A26A0 tail;
    int count;
    char pad20[0x50 - 0x20];
    float f50;
};

extern "C" {
Node3A26A0* ParticleEmitter_Construct(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f);
Node3A26A0* PhysEmitter_Construct(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f);
Node3A26A0* ShatterEmitter_Construct(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f, V43A26A0* v);
}

static inline void* Alloc3A26A0(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

static inline Node3A26A0* New3A26A0(Node3A26A0* ins, Desc3A26A0* d, int a3, float f)
{
    void* t = Alloc3A26A0(0x180, 0x59C);
    if (t)
        t = ParticleEmitter_Construct(t, ins, d, a3, f);
    return (Node3A26A0*)t;
}

extern "C" Node3A26A0* ParticleEmitter_SpawnChildren(Mgr3A26A0* mgr, Node3A26A0* ins, int name, int a3, float f)
{
    Node3A26A0* t;
    bool found;
    Node3A26A0* n;
    Desc3A26A0* d;
    bool after;
    bool seen;

    d = *(Desc3A26A0**)ParticleDefs_SlotForId(D_0053B544, name);
    after = 0;
    if (d->b4 == 1) {
        t = New3A26A0(ins, d, a3, f);
    } else if (!ins || !ins->bC) {
        t = (Node3A26A0*)Alloc3A26A0(0x130, 0x5A3);
        if (t)
            t = PhysEmitter_Construct(t, ins, d, a3, mgr->f50);
        if (ins && ins->IsAttached())
            after = 1;
    } else {
        t = (Node3A26A0*)Alloc3A26A0(0x180, 0x5AB);
        if (t) {
            V43A26A0 v;
            v.x = 0.0f;
            v.y = 1.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            t = ShatterEmitter_Construct(t, ins, d, a3, mgr->f50, &v);
        }
    }
    found = 0;
    seen = 0;
    for (n = mgr->head.next; n != (Node3A26A0*)&mgr->tail; n = n->next) {
        if (!after) {
            if (d->prio >= n->GetDesc()->prio) {
                found = 1;
                Node3A26A0* p = n->prev;
                t->next = n;
                t->prev = p;
                p->next = t;
                n->prev = t;
                mgr->count++;
                break;
            }
        } else {
            if (seen && (n != ins || d->prio >= n->GetDesc()->prio)) {
                found = 1;
                Node3A26A0* p = n->prev;
                t->next = n;
                t->prev = p;
                p->next = t;
                n->prev = t;
                mgr->count++;
                break;
            }
            if (n == ins)
                seen = 1;
        }
    }
    if (!found) {
        Node3A26A0* p = mgr->tail.prev;
        t->next = (Node3A26A0*)&mgr->tail;
        t->prev = p;
        p->next = t;
        mgr->tail.prev = t;
        mgr->count++;
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A26A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A26A0 */

/* merge_units: begin func_003A2A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
} __attribute__((aligned(16)));
static inline V operator+(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
struct Box {
    __int128 q[2];
    void Add(const V& p) {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(&q[0]), "r"(&q[1]), "r"(&p) : "memory");
    }
    V& Min() { return *(V*)&q[0]; }
    V& Max() { return *(V*)&q[1]; }
} __attribute__((aligned(16)));
struct Data { char pad[0x890]; Box box; };
struct Obj { char pad[0x24]; Data* d; char pad28[0x18]; V pos; char pad50[0x19]; unsigned char f69; Box* Get() { return &d->box; } };
extern "C" Box D_0053B660;
extern "C" Box* ParticleInst_ComputeBounds(Obj* o);
Box* ParticleInst_ComputeBounds(Obj* o)
{
    if (!o->f69) return &o->d->box;
    {
        /* 32-byte box copy: both lq before both sq, as four GCC-style lq/sq statements */
        __int128 t0, t1;
        Box* d = &D_0053B660;
        const Box* s = &o->d->box;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t0) : "r"(s) : "memory");
        __asm__ volatile("lq %0, 0x10(%1)" : "=r"(t1) : "r"(s) : "memory");
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t0), "r"(d) : "memory");
        __asm__ volatile("sq %0, 0x10(%1)" : : "r"(t1), "r"(d) : "memory");
    }
    V a = o->pos + *(V*)&o->d->box.q[0];
    D_0053B660.Add(a);
    V b = o->pos + *(V*)&o->d->box.q[1];
    D_0053B660.Add(b);
    return &D_0053B660;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A2A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A2A90 */

/* merge_units: begin func_003A2BA0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004DFAC8[];
extern char D_004DFAB8[];
extern char D_004DFAD8[];
void operator_delete(void* allocation);
}

struct Obj_3A2BA0 {
    virtual void Destroy(int flag);
};

struct Node_3A2BA0 {
    void* vtable;
    Node_3A2BA0* next;
    Node_3A2BA0* prev;
};

struct Self_3A2BA0 {
    void* vtable;
    Node_3A2BA0 head;
    Node_3A2BA0 tail;
    int count;
    Obj_3A2BA0* owned;
};

static inline void NodeDtor_3A2BA0(Node_3A2BA0* m)
{
    if (m) {
        m->vtable = D_004DFAB8;
        if (m)
            m->vtable = D_004DFAD8;
    }
}

extern "C" Self_3A2BA0* ParticleInst_Kill(Self_3A2BA0* self, short deleteFlag)
{
    if (self) {
        while (self->count != 0) {
            Node_3A2BA0* n = self->head.next;
            Node_3A2BA0* nx = n->next;
            Node_3A2BA0* pv = n->prev;
            pv->next = nx;
            nx->prev = pv;
            self->count--;
            {
                AllocGuard g;
                ((Obj_3A2BA0*)n)->Destroy(-1);
                Mem_Free(0, n, D_004BC5D0, 0x570);
            }
        }
        self->head.next = &self->tail;
        self->head.prev = &self->head;
        self->tail.next = &self->tail;
        self->tail.prev = &self->head;
        self->count = 0;
        Obj_3A2BA0* o = self->owned;
        if (o) {
            {
                AllocGuard g;
                o->Destroy(-1);
                Mem_Free(0, o, D_004BC5D0, 0x576);
            }
            self->owned = 0;
        }
        if (self) {
            self->vtable = D_004DFAC8;
            NodeDtor_3A2BA0(&self->tail);
            NodeDtor_3A2BA0(&self->head);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A2BA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A2BA0 */

/* merge_units: begin func_003A2DD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct TblTC {
    int pad[3];
    float f[1];
};

extern "C" {
extern int D_0053B5A0;
extern int D_0053B5A8;
extern int D_0053B5B0;
extern int D_0053B5B8;
extern TblTC D_0053B6A0;
}

struct DescTC {
    char pad0[4];
    unsigned char b4;
    char pad5[0x4C - 5];
    float x4C;
};

struct V4TC {
    float x, y, z, w;
};

struct NodeTC {
    void* vt;
    NodeTC* next;
    NodeTC* prev;
    char padC[0x70 - 0xC];
    unsigned char b70;
};

struct HeadTC {
    void* vt;
    NodeTC* next;
    NodeTC* prev;
};

struct TracerTC {
    void* vt;
    HeadTC head;
    HeadTC tail;
    int count;
    int x20;
    DescTC* desc;
    char pad28[0x50 - 0x28];
    float x50;
    float x54;
    float x58;
    float x5C;
    int x60;
    int x64;
    unsigned char b68;
    unsigned char b69;
    unsigned char b6A;
};

extern "C" {
#if 0 /* merge_units */
NodeTC* ParticleEmitter_Construct(void* p, NodeTC* ins, DescTC* d, int a, float f);
#endif /* merge_units */
#define ParticleEmitter_Construct(a0, a1, a2, a3, a4) ((NodeTC *)ParticleEmitter_Construct((a0), (Node3A26A0 *)(a1), (Desc3A26A0 *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
NodeTC* PhysEmitter_Construct(void* p, NodeTC* ins, DescTC* d, int a, float f);
#endif /* merge_units */
#define PhysEmitter_Construct(a0, a1, a2, a3, a4) ((NodeTC *)PhysEmitter_Construct((a0), (Node3A26A0 *)(a1), (Desc3A26A0 *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
NodeTC* ShatterEmitter_Construct(void* p, NodeTC* ins, DescTC* d, int a, float f, V4TC* v);
#endif /* merge_units */
#define ShatterEmitter_Construct(a0, a1, a2, a3, a4, a5) ((NodeTC *)ShatterEmitter_Construct((a0), (Node3A26A0 *)(a1), (Desc3A26A0 *)(a2), (a3), (a4), (V43A26A0 *)(a5))) /* merge_units */

NodeTC* WeatherEmitter_Construct(void* p, NodeTC* ins, DescTC* d, int a, float f, V4TC* v);
TracerTC* Tracer_Create(TracerTC* self, int name, int a3, float f);
}

static inline void* AllocTC(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

static inline NodeTC* New1TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x180, 0x52D);
    if (t)
        t = ParticleEmitter_Construct(t, 0, self->desc, a3, self->x50);
    return (NodeTC*)t;
}

static inline NodeTC* New2TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x180, 0x533);
    if (t) {
        V4TC v;
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        t = ShatterEmitter_Construct(t, 0, self->desc, a3, self->x50, &v);
    }
    return (NodeTC*)t;
}

static inline NodeTC* New3TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x140, 0x537);
    if (t) {
        V4TC v;
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        t = WeatherEmitter_Construct(t, 0, self->desc, a3, self->x50, &v);
    }
    return (NodeTC*)t;
}

static inline NodeTC* New4TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x130, 0x53B);
    if (t)
        t = PhysEmitter_Construct(t, 0, self->desc, a3, self->x50);
    return (NodeTC*)t;
}

extern "C" TracerTC* Tracer_Create(TracerTC* self, int name, int a3, float f)
{
    NodeTC* t;
    NodeTC* p;

    HeadTC* hd = &self->head;
    HeadTC* tl = &self->tail;
    void* a = D_004DFAD8;
    void* b = D_004DFAB8;
    self->vt = D_004DFAC8;
    self->head.vt = a;
    self->head.vt = b;
    self->tail.vt = a;
    self->tail.vt = b;
    self->head.next = (NodeTC*)tl;
    self->head.prev = (NodeTC*)hd;
    self->tail.next = (NodeTC*)tl;
    self->tail.prev = (NodeTC*)hd;
    self->count = 0;
    self->x50 = 0;
    self->b68 = 0;
    self->x20 = 0;
    self->x64 = 0;
    self->x5C = 1.0f;
    self->b6A = 0;
    self->head.next = (NodeTC*)tl;
    self->head.prev = (NodeTC*)hd;
    self->tail.next = (NodeTC*)tl;
    self->tail.prev = (NodeTC*)hd;
    self->count = 0;
    self->desc = *(DescTC**)ParticleDefs_SlotForId(D_0053B544, name);
    if (self->desc->b4 == 1) {
        t = New1TC(self, a3);
    } else if (name == D_0053B5A0) {
        t = New2TC(self, a3);
    } else if (name == D_0053B5A8 || name == D_0053B5B0 || name == D_0053B5B8) {
        t = New3TC(self, a3);
    } else {
        t = New4TC(self, a3);
    }
    self->x58 = self->desc->x4C * (2.0f * (((float*)&D_0053B6A0)[t->b70 + 3] - 0.5f));
    self->x54 = f + f * self->x58;
    p = self->tail.prev;
    t->next = (NodeTC*)&self->tail;
    t->prev = p;
    p->next = t;
    self->tail.prev = t;
    self->count++;
    return self;
}
#undef ParticleEmitter_Construct /* merge_units */
#undef PhysEmitter_Construct /* merge_units */
#undef ShatterEmitter_Construct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A2DD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A2DD0 */

/* merge_units: begin func_003A3210 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with two inlined member destructors (vtable chains). */
extern "C" {
}

struct Member_3A3210 { void* vtable; };
struct Obj_3A3210 {
    void* vtable;
    Member_3A3210 a;
    int pad[2];
    Member_3A3210 b;
};

static inline void MemberDtor_3A3210(Member_3A3210* m)
{
    if (m) {
        m->vtable = D_004DFAB8;
        if (m)
            m->vtable = D_004DFAD8;
    }
}

extern "C" Obj_3A3210* cInsertList_cParticleBase_dtor(Obj_3A3210* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DFAC8;
        MemberDtor_3A3210(&self->b);
        MemberDtor_3A3210(&self->a);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3210 */

/* merge_units: begin func_003A32B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cInsertList_cParticleBase_cStartNode_dtor, D_004DFAB8, D_004DFAD8)
#pragma pop /* merge_units */
/* merge_units: end func_003A32B0 */

/* merge_units: begin func_003A3310 */
#pragma push /* merge_units */
void cParticle_SetBoxData_float_float(int a0, float f12, float f13) {
    int v1;
    int cond;

    a0 = *(int*)((char*)a0 + 8);
    v1 = *(int*)((char*)a0 + 116);
    cond = v1 == 0;
    if (cond) goto L003A3328;
    a0 = v1;
L003A3328:;
    *(float*)((char*)a0 + 288) = f12;
    *(float*)((char*)a0 + 292) = f13;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3310 */

/* merge_units: begin func_003A3340 */
#pragma push /* merge_units */
typedef struct PSys {
    char pad000[0x74];
    struct PSys* sub;           /* 0x74 */
    char pad078[0xE0 - 0x78];
    float dx;                   /* 0xE0 */
    float dy;                   /* 0xE4 */
    float dz;                   /* 0xE8 */
    char pad0EC[0x104 - 0xEC];
    int mode;                   /* 0x104 */
    char pad108[0x11C - 0x108];
    float z;                    /* 0x11C */
    char pad120[0x130 - 0x120];
    unsigned char flag130;      /* 0x130 */
    unsigned char flag131;      /* 0x131 */
} PSys;

typedef enum { F_OFF, F_ON } FlagE;
typedef struct PHandle {
    char pad00[0x08];
    PSys* system;
} PHandle;

void func_003A3340(PHandle* h, int mode, float* seg, int on) {
    PSys* s = h->system;
    if (s->sub) s = s->sub;
    s->mode = mode;
    s->flag130 = on ? F_OFF : F_ON;
    s->dx = seg[4] - seg[0];
    s->dy = seg[5] - seg[1];
    s->dz = seg[6] - seg[2];
    s->z = seg[2];
    s->flag131 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3340 */

/* merge_units: begin func_003A33B0 */
#pragma push /* merge_units */
typedef struct PSys_003A33B0 {
    char pad000[0x74];
    struct PSys_003A33B0* sub;           /* 0x74 */
    char pad078[0xE0 - 0x78];
    float dx;                   /* 0xE0 */
    float dy;                   /* 0xE4 */
    float dz;                   /* 0xE8 */
    char pad0EC[0x104 - 0xEC];
    int mode;                   /* 0x104 */
    char pad108[0x10C - 0x108];
    float sx;                   /* 0x10C */
    float sy;                   /* 0x110 */
    float sz;                   /* 0x114 */
    float half;                 /* 0x118 */
    char pad11C[0x130 - 0x11C];
    unsigned char flag130;      /* 0x130 */
    unsigned char flag131;      /* 0x131 */
} PSys_003A33B0;

typedef struct PHandle_003A33B0 {
    char pad00[0x08];
    PSys_003A33B0* system;
} PHandle_003A33B0;

void cParticle_SetBoxData_cGOBJP_float_float_float_etc(PHandle_003A33B0* h, int mode, int on, float x, float y, float z) {
    PSys_003A33B0* s = h->system;
    if (s->sub) s = s->sub;
    s->mode = mode;
    s->flag130 = on ? F_OFF : F_ON;
    s->sx = x;
    s->sy = y;
    s->sz = z;
    s->half = 0.5f * s->sy;
    s->dx = s->sy;
    s->dy = s->sy;
    s->dz = s->sy;
    s->flag131 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A33B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A33B0 */
