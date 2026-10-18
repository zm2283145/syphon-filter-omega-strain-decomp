/* Collision_GatherNode: recursive per-actor collision gather (child walk of Collision_GatherScene).
 * The node's own shape is tested with inlined sphere/transform helpers; children go through the
 * out-of-line ones, as in Collision_GatherScene. */
#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sph { float r; float pad[3]; V4 c; };
struct Bnd { V4 lo, hi; };
struct Box2 { __int128 a, b; };
struct M40 { V4 r[4]; };
struct Src { float x, y, z; };
struct Mesh;
struct Shp { int pad0; char* node; };
struct It { int* p; };
struct Xf {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0xC];
    M40 transform;
    unsigned char dirty;
};
struct Lst { int cap; int count; int* data; };
struct PA { int count; int items[1]; };
struct Actor {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void* Children(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Shp* GetShape();
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x21]; Xf* xf;
};
struct Gath {
    virtual void v0(); virtual Lst* GetList(); virtual void v2(); virtual void Begin();
    char pad[0x10];
    PA list;
};
static inline int Eq(It* a, It* b) { int* y = b->p; int* x = a->p; return x == y; }
static inline bool Ne(It* a, It* b) { return !Eq(a, b); }
static inline bool Live(Actor* a) { return a->b2D && a->b2C && !a->b2E; }
static inline Actor** Find(Actor** b, Actor** e, Actor* v)
{
    for (; b != e; b++)
        if (*b == v) return b;
    return e;
}
static inline bool Has(PA* l, Actor* v)
{
    Actor** e = (Actor**)&l->items[l->count];
    return Find((Actor**)l->items, e, v) != e;
}
static inline M40* GetUpdated(Xf* x)
{
    if (x->dirty)
        x->Update();
    return &x->transform;
}
static inline void CopySph(Sph* d, Sph* s)
{
    __int128* sp; __int128* dp; __int128 v;
    d->r = s->r;
    sp = (__int128*)&s->c; dp = (__int128*)&d->c;
    __asm__ volatile("lq %0, 0(%1)" : "=r"(v) : "r"(sp));
    __asm__ volatile("sq %0, 0(%1)" : : "r"(v), "r"(dp) : "memory");
}
static inline void XformSph(Sph* a, M40* b)
{
    char* po = (char*)a + 0x10;
    char* pi = (char*)a + 0x10;
    asm {
        lqc2 vf8, 0x0(pi)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(po)
    }
}
static inline bool Overlaps(Sph* a, Sph* b)
{
    int t; float d;
    asm {
        lqc2 vf1, 0x10(a)
        lqc2 vf2, 0x10(b)
        vsub.xyzw vf3, vf2, vf1
        lqc2 vf5, 0x0(a)
        lqc2 vf6, 0x0(b)
        vadd.x vf7, vf5, vf6
        vmul.xyz vf4, vf3, vf3
        vaddw.x vf9, vf0, vf0w
        vmul.x vf8, vf7, vf7
        vmulax.x ACC, vf9, vf4x
        vmadday.x ACC, vf9, vf4y
        vmaddaz.x ACC, vf9, vf4z
        vmsubw.x vf10, vf8, vf0w
        qmfc2.ni t, vf10
    }
    asm { mtc1 t, d }
    bool r = d <= 0.0f; return r;
}
static inline void SetEmpty(Bnd* b)
{
    b->lo.x = 3.4028235e38f;
    b->lo.y = 3.4028235e38f;
    b->lo.z = 3.4028235e38f;
    b->lo.w = 1.0f;
    b->hi.x = -3.4028235e38f;
    b->hi.y = -3.4028235e38f;
    b->hi.z = -3.4028235e38f;
    b->hi.w = 1.0f;
}
extern "C" {
void* func_001827A0(Actor*);
unsigned char func_00182790(void*);
void* func_00182780(void*);
M40* Transform_GetUpdated(Xf*);
void func_00182760(Box2*, Bnd*);
void Mtx_InvertRigid_13ECA0(M40*, void*);
void ColTree_GatherBounds(void*, M40*);
void func_001822F0(Bnd*, Bnd*);
void Box_Union(Bnd*, Box2*);
void Transform_GetInverseMatrix(M40*, Xf*);
void ColGather_SetSource(Src*, Shp*);
Mesh* func_00182270(char*);
void ColTree_VisitRootNode(Mesh*, Src*, Bnd*);
int PtrArray_Begin(void*);
int PtrArray_End(void*);
void func_00181CD0(It*, void*, int*);
Xf* Object_GetRootNode(Actor*);
Sph* func_00183210(Shp*);
void func_001831F0(Sph*, Sph*);
void Sphere_Transform(Sph*, M40*);
int Sphere_Overlaps(Sph*, Sph*);
int GameObject_IsCollisionEnabled(Actor*);
int* InlinePtrArray_Find(PA*, Actor**);
int* InlinePtrArray_End(PA*);
void Bounds_SetEmpty(Bnd*);
void func_001828E0(Bnd*, Bnd*, Actor*, Xf*);
void ColGather_GatherWrapper(Shp*, Src*, Bnd*);
void PtrVec_Begin(It*, void*);
void PtrVec_End(It*, void*);
int func_001815A0(It*, It*);
Actor** func_001827B0(It*);
It* Iter_Advance4(It*);
void Collision_GatherNode(Gath* self, Src* src, Actor* node, Bnd* box, Sph* e0);
}

void Collision_GatherNode(Gath* self, Src* src, Actor* node, Bnd* box, Sph* e0)
{
    It p;
    It e;
    It ib;
    It ie;
    int tb;
    int te;
    Actor* act;
    It it1;
    It it2;
    Sph xs;
    Bnd bb;
    Box2 b4;
    M40 m1;
    M40 m2;
    M40 m3;
    Sph xs2;
    Bnd bnd;
    Shp* sh;
    Xf* xf;
    void* ch;

    sh = node->GetShape();
    if (sh != 0) {
        xf = node->xf;
        if (xf != 0) {
            CopySph(&xs, (Sph*)(sh->node + 16));
            XformSph(&xs, GetUpdated(xf));
            if (Overlaps(&xs, e0) && Live(node) && !Has(&self->list, node)) {
                void* t;
                SetEmpty(&bb);
                t = func_001827A0(node);
                if (t != 0 && func_00182790(t)) {
                    void* m = func_00182780(t);
                    M40* u = Transform_GetUpdated(xf);
                    func_00182760(&b4, box);
                    Mtx_InvertRigid_13ECA0(&m1, m);
                    ColTree_GatherBounds(&b4, &m1);
                    func_001822F0(&bb, box);
                    Mtx_InvertRigid_13ECA0(&m2, u);
                    ColTree_GatherBounds(&bb, &m2);
                    Box_Union(&bb, &b4);
                } else {
                    func_001822F0(&bb, box);
                    Transform_GetInverseMatrix(&m3, xf);
                    ColTree_GatherBounds(&bb, &m3);
                }
                Src s1 = *src;
                ColGather_SetSource(&s1, sh);
                ColTree_VisitRootNode(func_00182270(sh->node), &s1, &bb);
            }
        } else {
            if (Overlaps((Sph*)(sh->node + 16), e0) && Live(node) && !Has(&self->list, node)) {
                Src s2 = *src;
                ColGather_SetSource(&s2, sh);
                ColTree_VisitRootNode(func_00182270(sh->node), &s2, box);
            }
        }
    }
    ch = node->Children();
    if (ch != 0) {
        /* argument pointers taken into locals first: retail sets a2 before a0 for both converter calls */
        tb = PtrArray_Begin(ch);
        { int* pt = &tb; It* pi = &ib; func_00181CD0(pi, ch, pt); }
        p = ib;
        te = PtrArray_End(ch);
        { int* pt = &te; It* pi = &ie; func_00181CD0(pi, ch, pt); }
        e = ie;
        while (Ne(&p, &e)) {
            act = *(Actor**)p.p;
            {
                Shp* s = act->GetShape();
                if (s != 0) {
                    Xf* x = Object_GetRootNode(act);
                    if (x != 0) {
                        func_001831F0(&xs2, func_00183210(s));
                        Sphere_Transform(&xs2, Transform_GetUpdated(x));
                        if ((unsigned char)Sphere_Overlaps(&xs2, e0) && GameObject_IsCollisionEnabled(act)
                            && InlinePtrArray_Find(&self->list, &act) == InlinePtrArray_End(&self->list)) {
                            Bounds_SetEmpty(&bnd);
                            func_001828E0(&bnd, box, act, x);
                            ColGather_GatherWrapper(s, src, &bnd);
                        }
                    } else {
                        if ((unsigned char)Sphere_Overlaps(func_00183210(s), e0) && GameObject_IsCollisionEnabled(act)
                            && InlinePtrArray_Find(&self->list, &act) == InlinePtrArray_End(&self->list)) {
                            ColGather_GatherWrapper(s, src, box);
                        }
                    }
                }
            }
            {
                void* c2 = act->Children();
                if (c2 != 0) {
                    PtrVec_Begin(&it1, c2);
                    PtrVec_End(&it2, c2);
                    while (func_001815A0(&it1, &it2)) {
                        Collision_GatherNode(self, src, *func_001827B0(&it1), box, e0);
                        Iter_Advance4(&it1);
                    }
                }
            }
            p.p++;
        }
    }
}
