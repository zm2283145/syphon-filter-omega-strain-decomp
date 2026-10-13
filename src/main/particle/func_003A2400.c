#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)

/* lq/sq quad copies and the VU0 subtract as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BC5D0[];
}

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline V Sub(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

struct Pos {
    char pad0[0x30];
    V pos;
};

struct Src {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Pos* Get();
};

struct Mgr2400;

struct Node2400 {
    virtual void Destroy(int);
    virtual void v1();
    virtual void Update(Mgr2400* m, Pos* p, void* a, float t);
    virtual void v3();
    virtual int IsDone(float t);
    virtual int IsActive();
    Node2400* next;
    Node2400* prev;
};

struct Head2400 {
    void* vt;
    Node2400* next;
    Node2400* prev;
};

struct Mgr2400 {
    void* vt;
    int pad4;
    Node2400* hnext;
    Node2400* hprev;
    Node2400* tnext;
    Node2400* tprev;
    Src* src;
    int count;
    char pad20[0x40 - 0x20];
    V v40;
    float f50;
    char pad54[0x5C - 0x54];
    float f5C;
    float f60;
    float f64;
    unsigned char b68;
    unsigned char b69;
};

extern "C" void func_003A2400(Mgr2400* mgr, Pos* p, void* a, float dt)
{
    Node2400* n;
    Node2400* nx;

    mgr->f50 += dt;
    mgr->b68 = 0;
    mgr->b69 = 0;
    if (mgr->f64 > 0.0f) {
        mgr->f5C += mgr->f60;
        mgr->f64 -= dt;
    }
    if (mgr->count) {
        for (n = mgr->hnext; n != (Node2400*)&mgr->tnext; n = nx) {
            nx = n->next;
            if (n->IsDone(mgr->f50)) {
                Node2400* nn = n->next;
                Node2400* np = n->prev;
                np->next = nn;
                nn->prev = np;
                mgr->count--;
                {
                    AllocGuard g;
                    n->Destroy(-1);
                    Mem_Free(0, n, D_004BC5D0, 0x638);
                }
            } else {
                if (n->IsActive() && !mgr->b69) {
                    Src* s = mgr->src;
                    if (s->Get()) {
                        const V* pv = &p->pos;
                        V d = Sub(s->Get()->pos, *pv);
                        mgr->v40 = d;
                        mgr->b69 = 1;
                    }
                }
                n->Update(mgr, p, a, mgr->f50);
            }
        }
    }
}
