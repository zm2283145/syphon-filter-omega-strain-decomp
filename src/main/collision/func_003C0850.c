#pragma cplusplus on
#include "types.h"

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
struct GObj;

struct GObj { virtual int filter(GKey*, GTri*); };
struct GImg { int a; };

extern "C" {
void* func_003C1010(GTri*);
void* func_003C0F70(void*);
unsigned char* ColTri_GetEdgeFlags(void*);
GElem** func_003C0F50(GVec*);
int ColEdge_IsDuplicate(EdgeRef*, GKey*, void*);
int func_003C0DF0(GVec*);
void func_001EF6C0(GVec*, int);
void func_003C3190(GVec*, int, GElem*);
void ColTri_GetVertices(void*, GV4**, GV4**, GV4**, GKey*);
void Vec4_Copy(GV4*, GV4*);
void* func_001E1D60(void*);
GV4* Transform_GetUpdated(void*);
void Mtx_Multiply4(GV4*, GV4*);
void func_003C0B50(GImg*, void*, GKey*);
void func_003C0B40(unsigned char*, GImg*);
void Sphere_FromCenter(GV4*, GV4*, GV4*);
GV4* Vec4_NormalizeXYZ_1D10C0(GV4*, float*);
void func_003C0B30(EdgeRef*, GKey*, void*);
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
    unsigned char* fp = ColTri_GetEdgeFlags(func_003C0F70(func_003C1010(tri))) + 2;
    for (i = 2; i >= 0; i--, fp--) {
        if ((*fp & ~0x80) == 0)
            continue;
        GKey key;
        key.tri = tri->idx;
        key.side = i;
        if (!obj->filter(&key, tri))
            continue;
        dup = false;
        GIt it(*func_003C0F50(vec));
        GIt end(*func_003C0F50(vec) + vec->n);
        for (; it != end; it.p++) {
            if (!!ColEdge_IsDuplicate(&it.p->ref, &key, mesh)) {
                dup = true;
                break;
            }
        }
        if (dup)
            continue;
        if (vec->n >= vec->cap)
            func_001EF6C0(vec, func_003C0DF0(vec) * 3 / 2);
        GElem def;
        func_003C3190(vec, vec->n + 1, &def);
        e = vec->data + vec->n - 1;
        GV4* a;
        GV4* b;
        GV4* c;
        ColTri_GetVertices(mesh, &a, &b, &c, &key);
        Vec4_Copy(&e->v0, a);
        Vec4_Copy(&e->v1, b);
        Vec4_Copy(&e->v2, c);
        void* x = func_001E1D60(mesh);
        if (x) {
            m = Transform_GetUpdated(x);
            Mtx_Multiply4(&e->v0, m);
            Mtx_Multiply4(&e->v1, m);
            Mtx_Multiply4(&e->v2, m);
        }
        GImg GImg;
        func_003C0B50(&GImg, mesh, &key);
        func_003C0B40(&e->b30, &GImg);
        GV4 d;
        Sphere_FromCenter(&d, &e->v1, &e->v0);
        Vec4_Copy(&e->n, Vec4_NormalizeXYZ_1D10C0(&d, &e->len));
        func_003C0B30(&e->ref, &key, mesh);
    }
}
