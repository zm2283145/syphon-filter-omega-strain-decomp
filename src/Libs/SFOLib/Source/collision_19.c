/*
 * main/collision: range (3 files, 003C26D0-003C2DE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_003C26D0 */
#pragma push /* merge_units */
/* nCollision_DetectForIntersectionBetweenRayAndFaces */
#pragma opt_propagation off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x60]; } __attribute__((aligned(16))) Bnd26;
typedef struct {
    V4 v[3];
    V4 n;
    char part40[0x10];
    unsigned char flag50;
    unsigned char flag51;
    unsigned char flag52;
    char pad53[0xD];
    int part60[4];
} Tri26;
typedef struct {
    unsigned char hit;
    V4 a;
    V4 b;
    char part30[0x10];
    V4 to;
    V4 from;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    void* p64;
} Q26;
extern int D_00542CC8;
extern int D_00542D38;
extern int D_00542D48;
extern int D_00542D1C;
extern int D_004937C0[];
extern int D_004937D0[];
extern void std_vector_deleter_cCollisionFace_clear(int s);
extern void cRayMatrix_ctor_cVectorR_cVectorR_float(float r, Bnd26* b, V4* from, V4* to);
extern void cCollisionModelList_CollectFaces_MainCode_cArrayR_cRayMatrixR_int(int g, int s, Bnd26* b, int a3);
extern V4* cVector_GetZero(void);
extern void cVector_ctor_cVectorR(V4* d, V4* s);
extern void cVector_Get0001(V4* d);
extern void cVector_opAssign(V4* d, V4* s);
extern void cCollisionModel_FaceLocator_ctor(void* p);
extern void cCollisionModel_FaceProperties_ctor(void* p);
extern void cCollisionProbe_Ray_DetectForCollision_cArrayR_4(Q26* q, int s);
extern void cCollisionProbe_Ray_DetectForCollision_cArrayR_3(Q26* q, int s);
extern void cCollisionProbe_Ray_DetectForCollision_cArrayR_2(Q26* q, int s);
extern void cCollisionProbe_Ray_DetectForCollision_cArrayR(Q26* q, int s);
extern void* cVector_ctor_void(void* p);
extern void cCollisionFace_Set_cCollisionModelFaceLocatorR(Tri26* t, void* p);
extern void cCollisionModel_FaceProperties_opAssign(void* d, void* s);
extern void cCollisionModel_FaceLocator_opAssign(void* d, void* s);

static inline void Tri_Init(Tri26* t) {
    V4* p;
    p = t->v;
    do {
        cVector_ctor_void(p);
        p++;
    } while (p != t->v + 3);
    cVector_ctor_void(&t->n);
    cCollisionModel_FaceProperties_ctor(t->part40);
    cCollisionModel_FaceLocator_ctor(t->part60);
}
static inline unsigned char HasCtx(Q26* q) { return q->b62 != 0; }
static inline void SetMpg26(int a) {
    asm {
        .set noreorder
        ctc2.ni a, vi27
        vnop
        vnop
        .set reorder
    }
}
static inline void Q_Init(Q26* q, V4* to, V4* from) {
    V4 org;
    q->hit = 0;
    cVector_ctor_cVectorR(&q->a, cVector_GetZero());
    cVector_Get0001(&org);
    cVector_ctor_cVectorR(&q->b, &org);
    cCollisionModel_FaceLocator_ctor(q->part30);
    cVector_ctor_cVectorR(&q->to, to);
    cVector_ctor_cVectorR(&q->from, from);
    q->b60 = 0;
    q->b61 = 0;
    q->b62 = 0;
    q->p64 = 0;
}
unsigned char nCollision_DetectForIntersectionBetweenRayAndFaces(V4* out, Tri26* tri, V4* from, V4* to, int g, unsigned char m0, unsigned char m1, unsigned char m2, void* ctx, unsigned char under)
{
    int s;
    Bnd26 bnd;
    Q26 q;
    Q26* qp;
    Tri26 t;
    Tri26* tp;
    unsigned char res;

    {
        int k, f, r;
        asm {
            .set noreorder
            lqc2 vf1, 0(to)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        if ((unsigned char)r)
            return 0;
    }
    s = D_00542CC8;
    std_vector_deleter_cCollisionFace_clear(s);
    cRayMatrix_ctor_cVectorR_cVectorR_float(0.01f, &bnd, from, to);
    if (D_00542D38 != D_00542D48) {
        int i = D_00542D38;
        int e = D_004937D0[i];
        int st = D_004937C0[i];
        *(unsigned int*)0x10008020 = (unsigned int)(e - st) >> 4;
        *(int*)0x10008010 = st;
        *(int*)0x10008000 = 0x101;
        asm __volatile__("sync");
        D_00542D48 = i;
    }
    SetMpg26(D_00542D1C);
    {
        unsigned char busy;
        do {
            unsigned char tt;
            busy = 1;
            tt = busy;
            if (!(*(volatile int*)0x10008000 & 0x100) && !(*(volatile int*)0x10003800 & 3)) tt = 0;
            if (!tt && !(*(volatile int*)0x10003800 & 0x0F000000)) busy = 0;
        } while (busy);
        asm __volatile__("vnop");
        asm __volatile__("sync");
    }
    cCollisionModelList_CollectFaces_MainCode_cArrayR_cRayMatrixR_int(g, s, &bnd, m1);
    qp = &q;
    Q_Init(qp, to, from);
    q.b60 = m0;
    q.b61 = m1;
    if (ctx) {
        q.b62 = m2;
        q.p64 = *(void* volatile*)&ctx; /* retail reloads the stack argument */
    }
    if (HasCtx(&q)) {
        if (under) cCollisionProbe_Ray_DetectForCollision_cArrayR_4(&q, s);
        else cCollisionProbe_Ray_DetectForCollision_cArrayR_3(&q, s);
    } else {
        if (under) cCollisionProbe_Ray_DetectForCollision_cArrayR_2(&q, s);
        else cCollisionProbe_Ray_DetectForCollision_cArrayR(&q, s);
    }
    if (q.hit) {
        *out = q.b;
        tp = &t;
        Tri_Init(tp);
        cCollisionFace_Set_cCollisionModelFaceLocatorR(tp, q.part30);
        cVector_opAssign(&tri->v[0], &t.v[0]);
        cVector_opAssign(&tri->v[1], &t.v[1]);
        cVector_opAssign(&tri->v[2], &t.v[2]);
        cVector_opAssign(&tri->n, &t.n);
        tri->flag50 = t.flag50;
        cCollisionModel_FaceProperties_opAssign(tri->part40, t.part40);
        cCollisionModel_FaceLocator_opAssign(tri->part60, t.part60);
        tri->flag51 = t.flag51;
        tri->flag52 = t.flag52;
        res = 1;
    } else {
        res = 0;
    }
    return res;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C26D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C26D0 */

/* merge_units: begin func_003C2A80 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VObj_3C2A80 { virtual void dtor(int f); };
extern "C" {
extern char D_004BD0A0[];
#if 0 /* merge_units */
extern void* D_00542CC8;
#endif /* merge_units */
#define D_00542CC8 (*(void **)&D_00542CC8) /* merge_units */

extern void* D_00542CD0;
extern void* D_00542CD8;
extern VObj_3C2A80* D_00542CE0;
extern void* D_00542D00;
void func_00139DF0(void* p, int f);
void std_vector_deleter_cVector_dtor(void* p, int f);
void std_vector_deleter_cCollisionEdge_dtor(void* p, int f);
}
static inline void A3_3C2A80(void* p) { if (p) func_00139DF0(p, 0); }
static inline void A2_3C2A80(void* p) { if (p) A3_3C2A80(p); }
static inline void A1_3C2A80(void* p) { if (p) A2_3C2A80(p); }
static inline void B3_3C2A80(void* p) { if (p) std_vector_deleter_cCollisionEdge_dtor(p, 0); }
static inline void B2_3C2A80(void* p) { if (p) B3_3C2A80(p); }
static inline void B1_3C2A80(void* p) { if (p) B2_3C2A80(p); }
static inline void C3_3C2A80(void* p) { if (p) std_vector_deleter_cVector_dtor(p, 0); }
static inline void C2_3C2A80(void* p) { if (p) C3_3C2A80(p); }
static inline void C1_3C2A80(void* p) { if (p) C2_3C2A80(p); }

extern "C" void nCollision_UnInitStatics(void)
{
    void* p;
    if ((p = D_00542CC8) != 0) { { AllocGuard g; A1_3C2A80(p); cMemMan_Deallocate(0, p, D_004BD0A0, 0x41); } D_00542CC8 = 0; }
    if ((p = D_00542CD0) != 0) { { AllocGuard g; A1_3C2A80(p); cMemMan_Deallocate(0, p, D_004BD0A0, 0x47); } D_00542CD0 = 0; }
    if ((p = D_00542CD8) != 0) { { AllocGuard g; B1_3C2A80(p); cMemMan_Deallocate(0, p, D_004BD0A0, 0x4D); } D_00542CD8 = 0; }
    { VObj_3C2A80* v; if ((v = D_00542CE0) != 0) { { AllocGuard g; v->dtor(-1); cMemMan_Deallocate(0, v, D_004BD0A0, 0x53); } D_00542CE0 = 0; } }
    if ((p = D_00542D00) != 0) { { AllocGuard g; C1_3C2A80(p); cMemMan_Deallocate(0, p, D_004BD0A0, 0x68E); } D_00542D00 = 0; }
}
#undef D_00542CC8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C2A80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C2A80 */

/* merge_units: begin func_003C2DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004D9140[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void std_vector_cCollisionFace_ctor(void* p);
int cArrayCapacity_Int(int* n);
void std_vector_cCollisionFace_reserve(void* p, int n);
void std_vector_cCollisionEdge_ctor(void* p);
void std_vector_cCollisionEdge_reserve(void* p, int n);
void cArray_cGOBJPtr_ctor(void* p, int* n, int k);
void cArray_FixedCapacity_cGOBJPtr_2_ctor(void* p);
void cCollisionProbe_SphereSweptRay_InitStatics(int a);
}
struct ScrA { int w[3]; unsigned char bC; };
struct ScrB { void* vt; int w[4]; int x[3]; };
#if 0 /* merge_units */
extern "C" ScrA* D_00542CC8;
#endif /* merge_units */
#define D_00542CC8 (*(ScrA **)&D_00542CC8) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrA* D_00542CD0;
#endif /* merge_units */
#define D_00542CD0 (*(ScrA **)&D_00542CD0) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrA* D_00542CD8;
#endif /* merge_units */
#define D_00542CD8 (*(ScrA **)&D_00542CD8) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrB* D_00542CE0;
#endif /* merge_units */
#define D_00542CE0 (*(ScrB **)&D_00542CE0) /* merge_units */

static inline void* AllocL(int size, int line) {
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BD0A0, line);
}
extern "C" void nCollision_InitStatics(int a0, int a1, int a2, int a3) {
    if (!D_00542CC8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x2E);
        if (p) {
            int n = a0;
            std_vector_cCollisionFace_ctor(p);
            std_vector_cCollisionFace_reserve(p, cArrayCapacity_Int(&n));
            p->bC = 1;
        }
        D_00542CC8 = p;
    }
    if (!D_00542CD0) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x31);
        if (p) {
            int n = a0;
            std_vector_cCollisionFace_ctor(p);
            std_vector_cCollisionFace_reserve(p, cArrayCapacity_Int(&n));
            p->bC = 1;
        }
        D_00542CD0 = p;
    }
    if (!D_00542CD8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x34);
        if (p) {
            int n = a1;
            std_vector_cCollisionEdge_ctor(p);
            std_vector_cCollisionEdge_reserve(p, cArrayCapacity_Int(&n));
            p->bC = 1;
        }
        D_00542CD8 = p;
    }
    if (!D_00542CE0) {
        ScrB* p = (ScrB*)AllocL(0x20, 0x37);
        if (p) {
            int n = a2;
            p->vt = D_004D9140;
            cArray_cGOBJPtr_ctor(p->w, &n, 1);
            cArray_FixedCapacity_cGOBJPtr_2_ctor(p->x);
        }
        D_00542CE0 = p;
    }
    cCollisionProbe_SphereSweptRay_InitStatics(a3);
}
#undef D_00542CC8 /* merge_units */
#undef D_00542CD0 /* merge_units */
#undef D_00542CD8 /* merge_units */
#undef D_00542CE0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C2DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C2DE0 */
