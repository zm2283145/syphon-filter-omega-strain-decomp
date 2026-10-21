#pragma cplusplus on
#pragma inline_depth(10)

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct Box0 { V4 lo, hi; };
struct Box : Box0 {
    Box() { Init(); }
    void Init() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Grow(float h) {
        V4 p(-h, -h, -h, 1.0f);
        Extend(&p);
        V4 q(h, h, h, 1.0f);
        Extend(&q);
    }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
};

typedef struct { int x0; int x4; int x8; } L_SF;
typedef struct { int a; int b; } FxDef;
typedef struct { unsigned char flag; char pad[7]; } FxFlag;
typedef struct { char pad[0xC]; int xC; } PDef;

struct SnowSelf {
    int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70;
    L_SF list;
    Box box;
    V4 last;
    float fB0;
    float size;
    float fB8;
    int fBC;
    int weight;
    int c4;
    signed char id;
};

extern "C" {
extern char D_004DF860[];
extern char SnowField_vtable[];
extern FxFlag D_004F7A54[];
extern FxDef SpecFxTable[];
extern char D_0053B544[];
int IdMgr_Allocate(int*, int);
int cGOBJ_ctor(SnowSelf*, int*, int, int*);
void ScalarCollection_Init(L_SF*);
void ObjectList_EraseRange(int* out, L_SF* l, int* first, int** last);
PDef** ParticleDefs_SlotForId(void* p, int n);
void RainSnowPool_Create(int w);
}

static inline FxDef* GetDef_(int id)
{
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
static inline FxDef* GetDef(signed char id)
{
    if (!D_004F7A54[id].flag) return 0;
    return GetDef_(id);
}

extern "C" SnowSelf* SnowField_Construct(SnowSelf* self, signed char id, int weight, float a, float b, float c)
{
    int gid;
    int z;
    int r;
    int first;
    int* last;
    int* lp;
    IdMgr_Allocate(&gid, 0xE7);
    z = 0;
    cGOBJ_ctor(self, &gid, 4, &z);
    self->f0 = (int)D_004DF860;
    self->f60 = -1;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 0x3F800000;
    self->f2F = 1;
    self->f0 = (int)SnowField_vtable;
    ScalarCollection_Init(&self->list);
    lp = &self->list.x4;
    self->box.Init();
    last = lp;
    first = self->list.x8;
    { int** pl = &last; int* pf = &first; int* pr = &r; L_SF* ll = &self->list; ObjectList_EraseRange(pr, ll, pf, pl); }
    self->id = id;
    self->fB0 = a;
    self->size = b;
    self->fB8 = c;
    self->weight = weight;
    self->box.Reset();
    self->box.Grow(0.5f * self->size);
    self->fBC = 0;
    self->c4 = GetDef(id)->a;
    if (self->c4 >= 0) {
        PDef** pp = ParticleDefs_SlotForId(D_0053B544, self->c4);
        if (*pp) self->fBC = (*pp)->xC;
        RainSnowPool_Create(weight);
    }
    return self;
}





