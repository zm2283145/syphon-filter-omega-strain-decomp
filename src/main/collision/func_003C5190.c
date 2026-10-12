/* func_003C5190: recursive per-actor LOS candidate gather (child walk of Los_GatherCandidates) */
#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sph { V4 c; float r; };
struct Bnd { V4 lo, hi; };
struct Q70 { char pad[0x60]; } __attribute__((aligned(16)));
struct Src { float x, y, z; };
struct Mesh;
struct Shp { int pad0; int mesh; };
struct M40 { V4 r[4]; };
struct Box { char pad[0x40]; V4 c; };
struct It { int* p; };
struct Scene;
struct Shape;
struct Xf;
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
static inline int Ne(It* a, It* b) { return (a->p == b->p) ^ 1; }
static inline bool Live(Actor* a) { return a->b2D && a->b2C && !a->b2E; }
static inline int NeP(Actor** a, Actor** b) { return (a == b) ^ 1; }
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
extern "C" {
void func_003C62F0(Q70*, Box*);
void Transform_GetInverseMatrix(M40*, Xf*);
void func_003C61D0(Q70*, M40*);
void ColGather_SetSource(Src*, Shp*);
Mesh* func_00182270(int);
void func_003C55C0(Mesh*, Src*, void*);
int PtrArray_Begin(void*);
int func_00181CB0(void*);
void func_00181CD0(It*, void*, int*);
Xf* func_00183220(Actor*);
int func_001830D0(Actor*);
int* func_00183070(PA*, Actor**);
int* func_00183050(PA*);
void func_003C65A0(Q70*);
void func_003C6440(Q70*, Box*, Actor*, Xf*);
void func_003C6330(Shp*, Src*, void*);
void PtrVec_Begin(It*, void*);
void PtrVec_End(It*, void*);
int func_001815A0(It*, It*);
Actor** func_001827B0(It*);
It* Iter_Advance4(It*);
void func_003C5190(Gath* self, Src* src, Actor* node, Box* box, Sph* e0);
}

void func_003C5190(Gath* self, Src* src, Actor* node, Box* box, Sph* e0)
{
    It ib;
    It ie;
    int tb;
    int te;
    Actor* act;
    It it1;
    It it2;
    Q70 bx;
    M40 inv;
    Q70 q;
    Shp* sh;
    Xf* xf;
    void* ch;

    sh = node->GetShape();
    if (sh != 0) {
        xf = node->xf;
        if (xf != 0) {
            if (Live(node) && !Has(&self->list, node)) {
                func_003C62F0(&bx, box);
                Transform_GetInverseMatrix(&inv, xf);
                func_003C61D0(&bx, &inv);
                Src s1 = *src;
                ColGather_SetSource(&s1, sh);
                func_003C55C0(func_00182270(sh->mesh), &s1, &bx);
            }
        } else {
            if (Live(node) && !Has(&self->list, node)) {
                Src s2 = *src;
                ColGather_SetSource(&s2, sh);
                func_003C55C0(func_00182270(sh->mesh), &s2, box);
            }
        }
    }
    ch = node->Children();
    if (ch != 0) {
        Actor** p;
        Actor** e;
        tb = PtrArray_Begin(ch);
        func_00181CD0(&ib, ch, &tb);
        p = (Actor**)ib.p;
        te = func_00181CB0(ch);
        func_00181CD0(&ie, ch, &te);
        e = (Actor**)ie.p;
        if (NeP(p, *(Actor** volatile*)&ie.p)) {
        do {
            {
                Actor* a = *p;
                Shp* s;
                act = a;
                s = a->GetShape();
                if (s != 0) {
                    Xf* x = func_00183220(act);
                    if (x != 0) {
                        if (func_001830D0(act)
                            && func_00183070(&self->list, &act) == func_00183050(&self->list)) {
                            func_003C65A0(&q);
                            func_003C6440(&q, box, act, x);
                            func_003C6330(s, src, &q);
                        }
                    } else {
                        if (func_001830D0(act)
                            && func_00183070(&self->list, &act) == func_00183050(&self->list)) {
                            func_003C6330(s, src, box);
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
                        func_003C5190(self, src, *func_001827B0(&it1), box, e0);
                        Iter_Advance4(&it1);
                    }
                }
            }
            p++;
        } while (NeP(p, e));
        }
    }
}
