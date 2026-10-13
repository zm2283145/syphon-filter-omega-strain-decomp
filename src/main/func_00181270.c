/* Collision_GatherScene: walks the scene's actor list in reverse and gathers collision
 * shapes overlapping the query sphere into the scratchpad gather buffer (0x70000000). */
#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sph { V4 c; float r; };
struct Bnd { V4 lo, hi; };
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
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Shape* GetShape();
};
struct Gath {
    virtual void v0(); virtual Lst* GetList(); virtual void v2(); virtual void Begin();
    char pad[0x10];
    PA list;
};
static inline int Ne(It* a, It* b) { return (a->p == b->p) ^ 1; }
extern "C" {
void Sphere_FromCenter(V4*, V4*);
float Vec4_Length(V4*);
void Box_GetCenter(V4*, Sph*);
void Sphere_Set(Sph*, V4*, float);
void func_0013B260(Scene*);
void func_00183270(It*, Lst*);
void func_00183260(It*, It*);
void func_00183230(It*, Lst*);
Xf* func_00183220(Actor*);
Sph* func_00183210(Shape*);
void func_001831F0(Sph*, Sph*);
void* Transform_GetUpdated(Xf*);
void Sphere_Transform(Sph*, void*);
int Sphere_Overlaps(Sph*, Sph*);
int func_001830D0(Actor*);
int* func_00183070(PA*, Actor**);
int* func_00183050(PA*);
void Bounds_SetEmpty(Bnd*);
void func_001828E0(Bnd*, Sph*, Actor*, Xf*);
void ColGather_GatherWrapper(Shape*, void*, void*);
void PtrVec_Begin(It*, void*);
void PtrVec_End(It*, void*);
int func_001815A0(It*, It*);
Actor** func_001827B0(It*);
void Collision_GatherNode(Gath*, void*, Actor*, Sph*, Sph*);
It* Iter_Advance4(It*);
void ColGather_ComputeNormals(Gath*, Scene*);
void Collision_GatherScene(Gath* self, Scene* scene, Sph* sph, int a3);
}

void Collision_GatherScene(Gath* self, Scene* scene, Sph* sph, int a3)
{
    It rit;
    It rend;
    It t114;
    It t110;
    Actor* act;
    It it1;
    It it2;
    Sph e0;
    V4 d0;
    V4 c0;
    Sph xs;
    Bnd bnd;
    Actor** q;
    float r;
    Lst* lst;

    *(Scene**)0x70000000 = scene;
    *(int*)0x70000004 = 0;
    *(int*)0x70000008 = a3;
    Sphere_FromCenter(&d0, (V4*)((char*)sph + 0x10));
    r = 0.5f * Vec4_Length(&d0);
    Box_GetCenter(&c0, sph);
    Sphere_Set(&e0, &c0, r);
    func_0013B260(scene);
    self->Begin();
    lst = self->GetList();
    func_00183270(&t114, lst);
    func_00183260(&rit, &t114);
    func_00183230(&t110, lst);
    func_00183260(&rend, &t110);
    while (q = *(Actor** volatile*)&rit, Ne(&rit, &rend)) {
        Actor* p = q[-1];
        if (p != 0) {
            act = p;
            Shape* sh = act->GetShape();
            if (sh != 0) {
                Xf* xf = func_00183220(act);
                if (xf != 0) {
                    func_001831F0(&xs, func_00183210(sh));
                    Sphere_Transform(&xs, Transform_GetUpdated(xf));
                    if ((unsigned char)Sphere_Overlaps(&xs, &e0) && func_001830D0(act)
                        && func_00183070(&self->list, &act) == func_00183050(&self->list)) {
                        Bounds_SetEmpty(&bnd);
                        func_001828E0(&bnd, sph, act, xf);
                        ColGather_GatherWrapper(sh, (void*)0x70000000, &bnd);
                    }
                } else {
                    if ((unsigned char)Sphere_Overlaps(func_00183210(sh), &e0) && func_001830D0(act)
                        && func_00183070(&self->list, &act) == func_00183050(&self->list)) {
                        ColGather_GatherWrapper(sh, (void*)0x70000000, sph);
                    }
                }
            }
            {
                void* ch = act->Children();
                if (ch != 0) {
                    PtrVec_Begin(&it1, ch);
                    PtrVec_End(&it2, ch);
                    while (func_001815A0(&it1, &it2)) {
                        Collision_GatherNode(self, (void*)0x70000000, *func_001827B0(&it1), sph, &e0);
                        Iter_Advance4(&it1);
                    }
                }
            }
        }
        rit.p--;
    }
    ColGather_ComputeNormals(self, scene);
}







