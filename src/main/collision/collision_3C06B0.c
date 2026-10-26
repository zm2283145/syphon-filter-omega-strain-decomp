/*
 * main/collision: range (3 files, 003C06B0-003C0850)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003C06B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, int *, int);                      
int cArrayCapacity_Int(int *);                           
int std_vector_cVector_ctor(int );                            
int Vector_Reserve_25DBD0_Thunk(int , int);                       
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int D_00542D00;

void cCollisionProbe_SphereSweptRay_InitStatics(int arg0) {
    int sp3C;
    int temp_s1;

    if (D_00542D00 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s1 = Mem_Alloc(0, 0x10, ((int*)"collision.cc"), 0x686);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s1 != NULL) {
            sp3C = arg0;
            std_vector_cVector_ctor(temp_s1);
            Vector_Reserve_25DBD0_Thunk(temp_s1, cArrayCapacity_Int(&sp3C));
            F_(temp_s1, 0xC, signed char) = 1;
        }
        D_00542D00 = temp_s1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C06B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C06B0 */

/* merge_units: begin func_003C0790 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct GV4 { float x, y, z, w; };
struct GKey { int tri; int side; };
struct EdgeRef { int tri; int side; void* mesh; };
struct GElem {
    GV4 v0;
    GV4 v1;
    GV4 v2;
    unsigned char b30;
    char pad31[3];
    float len;
    char pad38[8];
    GV4 n;
    EdgeRef ref;
    int pad5c;
    GElem() { b30 = 0; ref.tri = -1; ref.side = -1; ref.mesh = 0; }
};
struct GVec { int cap; int n; GElem* data; };
struct GTri { char pad[0x60]; int idx; void* mesh; };
struct GObj { virtual int filter(GKey*, GTri*); };
extern "C" void Col_GatherTriangleEdges(GObj* obj, GVec* vec, GTri* tri); /* gsynth: defined below */
#pragma pop
typedef struct { char data[0x70]; } TriC0790;
typedef struct { TriC0790* data; int count; } VecC0790;
extern void std_vector_deleter_cCollisionEdge_clear(void* a);
extern TriC0790** std_vector_deleter_cCollisionFace_data_void(VecC0790* v);
#if 0 /* merge_units */
extern void Col_GatherTriangleEdges(void* ctx, void* a, TriC0790* t);
#endif /* merge_units */
#define Col_GatherTriangleEdges(a0, a1, a2) (Col_GatherTriangleEdges((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

static inline int NeC0790(TriC0790* a, TriC0790* b) { return (a == b) ^ 1; }
void Col_GatherEdges(void* ctx, void* a, VecC0790* v) {
    TriC0790* it;
    TriC0790* end;
    std_vector_deleter_cCollisionEdge_clear(a);
    it = *std_vector_deleter_cCollisionFace_data_void(v);
    end = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
    while (NeC0790(it, end)) {
        Col_GatherTriangleEdges(ctx, a, it);
        it++;
    }
}
#undef Col_GatherTriangleEdges /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0790 */

/* merge_units: begin func_003C0850 */
#pragma push /* merge_units */
#pragma cplusplus on







struct GObj;


struct GImg { int a; };

extern "C" {
void* cCollisionFace_FaceLocator(GTri*);
void* cCollisionModel_FaceLocator_Face(void*);
unsigned char* ColTri_GetEdgeFlags(void*);
GElem** std_vector_deleter_cCollisionEdge_data(GVec*);
int ColEdge_IsDuplicate(EdgeRef*, GKey*, void*);
int std_vector_cCollisionEdge_capacity(GVec*);
void Vector_Reserve_1EF6C0(GVec*, int);
void std_vector_imp_cCollisionEdge_resize(GVec*, int, GElem*);
void ColTri_GetVertices(void*, GV4**, GV4**, GV4**, GKey*);
void Vec4_Copy(GV4*, GV4*);
void* cCollisionModel_GetXform(void*);
GV4* Transform_GetUpdated(void*);
void Mtx_Multiply4(GV4*, GV4*);
void cCollisionModel_GetEdgeFlags(GImg*, void*, GKey*);
void tEdgeFlags_opAssign(unsigned char*, GImg*);
void Sphere_FromCenter(GV4*, GV4*, GV4*);
GV4* Vec4_NormalizeXYZ_1D10C0(GV4*, float*);
void cCollisionModel_EdgeLocator_Set(EdgeRef*, GKey*, void*);
}

struct GIt {
    GElem* p;
    GIt(GElem* q) : p(q) {}
    bool operator!=(const GIt& o) const { return !(p == o.p); }
};

extern "C" void Col_GatherTriangleEdges(GObj* obj, GVec* vec, GTri* tri)
{
    int i;
    bool dup;
    GV4* m;
    GElem* e;
    void* mesh = tri->mesh;
    unsigned char* fp = ColTri_GetEdgeFlags(cCollisionModel_FaceLocator_Face(cCollisionFace_FaceLocator(tri))) + 2;
    for (i = 2; i >= 0; i--, fp--) {
        if ((*fp & ~0x80) == 0)
            continue;
        GKey key;
        key.tri = tri->idx;
        key.side = i;
        if (!obj->filter(&key, tri))
            continue;
        dup = false;
        GIt it(*std_vector_deleter_cCollisionEdge_data(vec));
        GIt end(*std_vector_deleter_cCollisionEdge_data(vec) + vec->n);
        for (; it != end; it.p++) {
            if (!!ColEdge_IsDuplicate(&it.p->ref, &key, mesh)) {
                dup = true;
                break;
            }
        }
        if (dup)
            continue;
        if (vec->n >= vec->cap)
            Vector_Reserve_1EF6C0(vec, std_vector_cCollisionEdge_capacity(vec) * 3 / 2);
        GElem def;
        std_vector_imp_cCollisionEdge_resize(vec, vec->n + 1, &def);
        e = vec->data + vec->n - 1;
        GV4* a;
        GV4* b;
        GV4* c;
        ColTri_GetVertices(mesh, &a, &b, &c, &key);
        Vec4_Copy(&e->v0, a);
        Vec4_Copy(&e->v1, b);
        Vec4_Copy(&e->v2, c);
        void* x = cCollisionModel_GetXform(mesh);
        if (x) {
            m = Transform_GetUpdated(x);
            Mtx_Multiply4(&e->v0, m);
            Mtx_Multiply4(&e->v1, m);
            Mtx_Multiply4(&e->v2, m);
        }
        GImg GImg;
        cCollisionModel_GetEdgeFlags(&GImg, mesh, &key);
        tEdgeFlags_opAssign(&e->b30, &GImg);
        GV4 d;
        Sphere_FromCenter(&d, &e->v1, &e->v0);
        Vec4_Copy(&e->n, Vec4_NormalizeXYZ_1D10C0(&d, &e->len));
        cCollisionModel_EdgeLocator_Set(&e->ref, &key, mesh);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0850 */
