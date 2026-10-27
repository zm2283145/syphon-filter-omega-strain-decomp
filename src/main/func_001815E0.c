/* cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR: recursive per-actor collision gather (child walk of cCollisionModelList_CollectFaces_MainCode_cArrayR_cBoxR_int).
 * The node's own shape is tested with inlined sphere/transform helpers; children go through the
 * out-of-line ones, as in cCollisionModelList_CollectFaces_MainCode_cArrayR_cBoxR_int. */
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
void* cGOBJ_GetMovementInfo(Actor*);
unsigned char cMovement_WasMovingLastFrame(void*);
void* cMovement_PrevTransform(void*);
M40* cXform_GetMatrix(Xf*);
void cBox_ctor_cBoxR(Box2*, Bnd*);
void cMatrix_Copy_InvertRotTrans(M40*, void*);
void cBox_Transform(void*, M40*);
void cBox_opAssign(Bnd*, Bnd*);
void cBox_opAddAssign(Bnd*, Box2*);
void cXform_GetInverseMatrix(M40*, Xf*);
void cCollisionFaceCollector_ResetModelInstance(Src*, Shp*);
Mesh* cCollisionModelMaster_GetData(char*);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cBoxR(Mesh*, Src*, Bnd*);
int std_vector_imp_cGOBJPtr_1_begin(void*);
int std_vector_imp_cGOBJPtr_1_end_void(void*);
void std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(It*, void*, int*);
Xf* cGOBJ_GetXform_void_2(Actor*);
Sph* cCollisionModel_BoundingSphere_LocalSpace(Shp*);
void cSphere_ctor_cSphereR(Sph*, Sph*);
void Sphere_Transform(Sph*, M40*);
int cSphere_Intersects(Sph*, Sph*);
int cGOBJ_IsActive(Actor*);
int* cArray_FixedCapacity_cGOBJPtr_2_Find(PA*, Actor**);
int* cArray_FixedCapacity_cGOBJPtr_2_End(PA*);
void cBox_ctor_void(Bnd*);
void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(Bnd*, Bnd*, Actor*, Xf*);
void cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(Shp*, Src*, Bnd*);
void cArray_cGOBJPtr_Begin(It*, void*);
void cArray_cGOBJPtr_End(It*, void*);
int cArray_cGOBJPtr_Iterator_opNe(It*, It*);
Actor** cArray_cGOBJPtr_Iterator_opMul(It*);
It* cArray_cGOBJPtr_Iterator_opInc(It*);
void cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR(Gath* self, Src* src, Actor* node, Bnd* box, Sph* e0);
}

void cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR(Gath* self, Src* src, Actor* node, Bnd* box, Sph* e0)
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
                t = cGOBJ_GetMovementInfo(node);
                if (t != 0 && cMovement_WasMovingLastFrame(t)) {
                    void* m = cMovement_PrevTransform(t);
                    M40* u = cXform_GetMatrix(xf);
                    cBox_ctor_cBoxR(&b4, box);
                    cMatrix_Copy_InvertRotTrans(&m1, m);
                    cBox_Transform(&b4, &m1);
                    cBox_opAssign(&bb, box);
                    cMatrix_Copy_InvertRotTrans(&m2, u);
                    cBox_Transform(&bb, &m2);
                    cBox_opAddAssign(&bb, &b4);
                } else {
                    cBox_opAssign(&bb, box);
                    cXform_GetInverseMatrix(&m3, xf);
                    cBox_Transform(&bb, &m3);
                }
                Src s1 = *src;
                cCollisionFaceCollector_ResetModelInstance(&s1, sh);
                cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cBoxR(cCollisionModelMaster_GetData(sh->node), &s1, &bb);
            }
        } else {
            if (Overlaps((Sph*)(sh->node + 16), e0) && Live(node) && !Has(&self->list, node)) {
                Src s2 = *src;
                cCollisionFaceCollector_ResetModelInstance(&s2, sh);
                cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cBoxR(cCollisionModelMaster_GetData(sh->node), &s2, box);
            }
        }
    }
    ch = node->Children();
    if (ch != 0) {
        /* argument pointers taken into locals first: retail sets a2 before a0 for both converter calls */
        tb = std_vector_imp_cGOBJPtr_1_begin(ch);
        { int* pt = &tb; It* pi = &ib; std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(pi, ch, pt); }
        p = ib;
        te = std_vector_imp_cGOBJPtr_1_end_void(ch);
        { int* pt = &te; It* pi = &ie; std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(pi, ch, pt); }
        e = ie;
        while (Ne(&p, &e)) {
            act = *(Actor**)p.p;
            {
                Shp* s = act->GetShape();
                if (s != 0) {
                    Xf* x = cGOBJ_GetXform_void_2(act);
                    if (x != 0) {
                        cSphere_ctor_cSphereR(&xs2, cCollisionModel_BoundingSphere_LocalSpace(s));
                        Sphere_Transform(&xs2, cXform_GetMatrix(x));
                        if ((unsigned char)cSphere_Intersects(&xs2, e0) && cGOBJ_IsActive(act)
                            && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                            cBox_ctor_void(&bnd);
                            nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(&bnd, box, act, x);
                            cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(s, src, &bnd);
                        }
                    } else {
                        if ((unsigned char)cSphere_Intersects(cCollisionModel_BoundingSphere_LocalSpace(s), e0) && cGOBJ_IsActive(act)
                            && cArray_FixedCapacity_cGOBJPtr_2_Find(&self->list, &act) == cArray_FixedCapacity_cGOBJPtr_2_End(&self->list)) {
                            cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(s, src, box);
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
                        cCollisionModelList_CollectFaces_cCollisionFaceCollectorR_cGOBJP_cBoxR_cSphereR(self, src, *cArray_cGOBJPtr_Iterator_opMul(&it1), box, e0);
                        cArray_cGOBJPtr_Iterator_opInc(&it1);
                    }
                }
            }
            p.p++;
        }
    }
}
