/* cCollisionModelList_CollectFaces_MainCode_cArrayR_cBoxR_int: walks the scene's actor list in reverse and gathers collision
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
void cVector_opSub(V4*, V4*);
float cVector_GetLength(V4*);
void cBox_Center(V4*, Sph*);
void cSphere_ctor_float_cVectorR(Sph*, V4*, float);
void std_vector_deleter_cCollisionFace_clear(Scene*);
void std_vector_cGOBJPtr_rbegin(It*, Lst*);
void cArray_cGOBJPtr_ConstReverseIterator_ctor(It*, It*);
void std_vector_cGOBJPtr_rend(It*, Lst*);
Xf* cGOBJ_GetXform_void_2(Actor*);
Sph* cCollisionModel_BoundingSphere_LocalSpace(Shape*);
void cSphere_ctor_cSphereR(Sph*, Sph*);
void* cXform_GetMatrix(Xf*);
void Sphere_Transform(Sph*, void*);
int cSphere_Intersects(Sph*, Sph*);
int cGOBJ_IsActive(Actor*);
int* cArray_FixedCapacity_cGOBJPtr_2_Find(PA*, Actor**);
int* cArray_FixedCapacity_cGOBJPtr_2_End(PA*);
void cBox_ctor_void(Bnd*);
void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(Bnd*, Sph*, Actor*, Xf*);
void cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(Shape*, void*, void*);
void cArray_cGOBJPtr_Begin(It*, void*);
void cArray_cGOBJPtr_End(It*, void*);
int cArray_cGOBJPtr_Iterator_opNe(It*, It*);
Actor** cArray_cGOBJPtr_Iterator_opMul(It*);
void cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR(Gath*, void*, Actor*, Sph*, Sph*);
It* cArray_cGOBJPtr_Iterator_opInc(It*);
void cCollisionModelList_CalculateFaceNormals(Gath*, Scene*);
void cCollisionModelList_CollectFaces_MainCode_cArrayR_cBoxR_int(Gath* self, Scene* scene, Sph* sph, int a3);
}

void cCollisionModelList_CollectFaces_MainCode_cArrayR_cBoxR_int(Gath* self, Scene* scene, Sph* sph, int a3)
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
    cVector_opSub(&d0, (V4*)((char*)sph + 0x10));
    r = 0.5f * cVector_GetLength(&d0);
    cBox_Center(&c0, sph);
    cSphere_ctor_float_cVectorR(&e0, &c0, r);
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
                Xf* xf = cGOBJ_GetXform_void_2(act);
                if (xf != 0) {
                    cSphere_ctor_cSphereR(&xs, cCollisionModel_BoundingSphere_LocalSpace(sh));
                    Sphere_Transform(&xs, cXform_GetMatrix(xf));
                    if ((unsigned char)cSphere_Intersects(&xs, &e0) && cGOBJ_IsActive(act)
                        && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                        cBox_ctor_void(&bnd);
                        nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(&bnd, sph, act, xf);
                        cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(sh, (void*)0x70000000, &bnd);
                    }
                } else {
                    if ((unsigned char)cSphere_Intersects(cCollisionModel_BoundingSphere_LocalSpace(sh), &e0) && cGOBJ_IsActive(act)
                        && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                        cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(sh, (void*)0x70000000, sph);
                    }
                }
            }
            {
                void* ch = act->Children();
                if (ch != 0) {
                    cArray_cGOBJPtr_Begin(&it1, ch);
                    cArray_cGOBJPtr_End(&it2, ch);
                    while (cArray_cGOBJPtr_Iterator_opNe(&it1, &it2)) {
                        cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR(self, (void*)0x70000000, *cArray_cGOBJPtr_Iterator_opMul(&it1), sph, &e0);
                        cArray_cGOBJPtr_Iterator_opInc(&it1);
                    }
                }
            }
        }
        rit.p--;
    }
    cCollisionModelList_CalculateFaceNormals(self, scene);
}







