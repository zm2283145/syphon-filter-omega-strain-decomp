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
void std_vector_deleter_cCollisionFace_clear(Scene*);
void std_vector_cGOBJPtr_rbegin(It*, Lst*);
void cArray_cGOBJPtr_ConstReverseIterator_ctor(It*, It*);
void std_vector_cGOBJPtr_rend(It*, Lst*);
Xf* Object_GetRootNode(Actor*);
Sph* cCollisionModel_BoundingSphere_LocalSpace(Shape*);
void cSphere_ctor_cSphereR(Sph*, Sph*);
void* Transform_GetUpdated(Xf*);
void Sphere_Transform(Sph*, void*);
int Sphere_Overlaps(Sph*, Sph*);
int GameObject_IsCollisionEnabled(Actor*);
int* InlinePtrArray_Find(PA*, Actor**);
int* InlinePtrArray_End(PA*);
void Bounds_SetEmpty(Bnd*);
void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(Bnd*, Sph*, Actor*, Xf*);
void ColGather_GatherWrapper(Shape*, void*, void*);
void PtrVec_Begin(It*, void*);
void PtrVec_End(It*, void*);
int cArray_cGOBJPtr_Iterator_opNe(It*, It*);
Actor** cArray_cGOBJPtr_Iterator_opMul(It*);
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
    std_vector_deleter_cCollisionFace_clear(scene);
    self->Begin();
    lst = self->GetList();
    std_vector_cGOBJPtr_rbegin(&t114, lst);
    cArray_cGOBJPtr_ConstReverseIterator_ctor(&rit, &t114);
    std_vector_cGOBJPtr_rend(&t110, lst);
    cArray_cGOBJPtr_ConstReverseIterator_ctor(&rend, &t110);
    while (q = *(Actor** volatile*)&rit, Ne(&rit, &rend)) {
        Actor* p = q[-1];
        if (p != 0) {
            act = p;
            Shape* sh = act->GetShape();
            if (sh != 0) {
                Xf* xf = Object_GetRootNode(act);
                if (xf != 0) {
                    cSphere_ctor_cSphereR(&xs, cCollisionModel_BoundingSphere_LocalSpace(sh));
                    Sphere_Transform(&xs, Transform_GetUpdated(xf));
                    if ((unsigned char)Sphere_Overlaps(&xs, &e0) && GameObject_IsCollisionEnabled(act)
                        && InlinePtrArray_Find(&self->list, &act) == InlinePtrArray_End(&self->list)) {
                        Bounds_SetEmpty(&bnd);
                        nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(&bnd, sph, act, xf);
                        ColGather_GatherWrapper(sh, (void*)0x70000000, &bnd);
                    }
                } else {
                    if ((unsigned char)Sphere_Overlaps(cCollisionModel_BoundingSphere_LocalSpace(sh), &e0) && GameObject_IsCollisionEnabled(act)
                        && InlinePtrArray_Find(&self->list, &act) == InlinePtrArray_End(&self->list)) {
                        ColGather_GatherWrapper(sh, (void*)0x70000000, sph);
                    }
                }
            }
            {
                void* ch = act->Children();
                if (ch != 0) {
                    PtrVec_Begin(&it1, ch);
                    PtrVec_End(&it2, ch);
                    while (cArray_cGOBJPtr_Iterator_opNe(&it1, &it2)) {
                        Collision_GatherNode(self, (void*)0x70000000, *cArray_cGOBJPtr_Iterator_opMul(&it1), sph, &e0);
                        Iter_Advance4(&it1);
                    }
                }
            }
        }
        rit.p--;
    }
    ColGather_ComputeNormals(self, scene);
}







