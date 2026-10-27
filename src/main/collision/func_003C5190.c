/* cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cRayMatrixR_cSphereR: recursive per-actor LOS candidate gather (child walk of cCollisionModelList_CollectFaces_MainCode_cArrayR_cRayMatrixR_int) */
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
void cRayMatrix_opAssign(Q70*, Box*);
void cXform_GetInverseMatrix(M40*, Xf*);
void cRayMatrix_Transform(Q70*, M40*);
void cCollisionFaceCollector_ResetModelInstance(Src*, Shp*);
Mesh* cCollisionModelMaster_GetData(int);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR(Mesh*, Src*, void*);
int std_vector_imp_cGOBJPtr_1_begin(void*);
int std_vector_imp_cGOBJPtr_1_end_void(void*);
void std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(It*, void*, int*);
Xf* cGOBJ_GetXform_void_2(Actor*);
int cGOBJ_IsActive(Actor*);
int* cArray_FixedCapacity_cGOBJPtr_2_Find(PA*, Actor**);
int* cArray_FixedCapacity_cGOBJPtr_2_End(PA*);
void cRayMatrix_ctor_void(Q70*);
void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cRayMatrixR_cRayMatrixR_cGOBJP_cXformP(Q70*, Box*, Actor*, Xf*);
void cCollisionModel_GetNearFaces_cCollisionFaceCollector_cRayMatrixR(Shp*, Src*, void*);
void cArray_cGOBJPtr_Begin(It*, void*);
void cArray_cGOBJPtr_End(It*, void*);
int cArray_cGOBJPtr_Iterator_opNe(It*, It*);
Actor** cArray_cGOBJPtr_Iterator_opMul(It*);
It* cArray_cGOBJPtr_Iterator_opInc(It*);
void cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cRayMatrixR_cSphereR(Gath* self, Src* src, Actor* node, Box* box, Sph* e0);
}

void cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cRayMatrixR_cSphereR(Gath* self, Src* src, Actor* node, Box* box, Sph* e0)
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
                cRayMatrix_opAssign(&bx, box);
                cXform_GetInverseMatrix(&inv, xf);
                cRayMatrix_Transform(&bx, &inv);
                Src s1 = *src;
                cCollisionFaceCollector_ResetModelInstance(&s1, sh);
                cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR(cCollisionModelMaster_GetData(sh->mesh), &s1, &bx);
            }
        } else {
            if (Live(node) && !Has(&self->list, node)) {
                Src s2 = *src;
                cCollisionFaceCollector_ResetModelInstance(&s2, sh);
                cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR(cCollisionModelMaster_GetData(sh->mesh), &s2, box);
            }
        }
    }
    ch = node->Children();
    if (ch != 0) {
        Actor** p;
        Actor** e;
        tb = std_vector_imp_cGOBJPtr_1_begin(ch);
        std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(&ib, ch, &tb);
        p = (Actor**)ib.p;
        te = std_vector_imp_cGOBJPtr_1_end_void(ch);
        std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(&ie, ch, &te);
        e = (Actor**)ie.p;
        if (NeP(p, *(Actor** volatile*)&ie.p)) {
        do {
            {
                Actor* a = *p;
                Shp* s;
                act = a;
                s = a->GetShape();
                if (s != 0) {
                    Xf* x = cGOBJ_GetXform_void_2(act);
                    if (x != 0) {
                        if (cGOBJ_IsActive(act)
                            && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                            cRayMatrix_ctor_void(&q);
                            nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cRayMatrixR_cRayMatrixR_cGOBJP_cXformP(&q, box, act, x);
                            cCollisionModel_GetNearFaces_cCollisionFaceCollector_cRayMatrixR(s, src, &q);
                        }
                    } else {
                        if (cGOBJ_IsActive(act)
                            && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                            cCollisionModel_GetNearFaces_cCollisionFaceCollector_cRayMatrixR(s, src, box);
                        }
                    }
                }
            }
            {
                void* c2 = act->Children();
                if (c2 != 0) {
                    cArray_cGOBJPtr_Begin(&it1, c2);
                    cArray_cGOBJPtr_End(&it2, c2);
                    while (cArray_cGOBJPtr_Iterator_opNe(&it1, &it2)) {
                        cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cRayMatrixR_cSphereR(self, src, *cArray_cGOBJPtr_Iterator_opMul(&it1), box, e0);
                        cArray_cGOBJPtr_Iterator_opInc(&it1);
                    }
                }
            }
            p++;
        } while (NeP(p, e));
        }
    }
}
