/*
 * Libs/SFOLib/Source/collision: 5 files, 003C19A0-003C2210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C19A0 */
#pragma push /* merge_units */
#include "types.h"

#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(int, int *);                             
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(int, int *);                             

void cCollisionModel_Data_BoundingBox(int arg0) {
    int sp1C;
    int sp18;

    if (F_(arg0, 0x4, int) > 0) {
        sp1C = F_(arg0, 0x8, int);
        cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(arg0, &sp1C);
        return;
    }
    sp18 = F_(arg0, 0x10, int);
    cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(arg0, &sp18);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C19A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C19A0 */

/* merge_units: begin func_003C19F0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { unsigned char c[4]; } Bytes4;

typedef struct ColNode {
    char pad[0x20];
    int child[8];
} ColNode;

typedef struct ColLeaf {
    char pad[0x24];
    int p;
    char pad2[8];
} ColLeaf;

typedef struct ColTri {
    float f0;
    short idx[3];
    unsigned char col[1];
    unsigned char rgb[3];
    char pad[2];
} ColTri;

typedef struct ColTri20 {
    char pad[0x20];
} ColTri20;

typedef struct ColTri40 {
    char pad[0x40];
} ColTri40;

typedef struct ColSurf {
    char b0;
    char b1;
    char name[14];
} ColSurf;

typedef struct ColHdr {
    char magic[2];
    signed char tag;
    unsigned char version;
    unsigned int nNodes;
    int nodes;
    unsigned int nLeaves;
    int leaves;
    unsigned int nTris;
    int tris;
    int pad1C;
    int verts;
    int p24;
    unsigned int nSurf;
    int surf;
} ColHdr;

#if 0 /* merge_units */
extern void cVector_ctor_cVectorR(V4* d, V4* s);
#endif /* merge_units */
void* cVector_ctor_cVectorR(void*, void*); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((void)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern char* tFaceFlags_ctor(Bytes4* p);
#endif /* merge_units */
char * tFaceFlags_ctor(); /* merge_units */


extern Bytes4* tFaceFlags_opAssign(Bytes4* dst, Bytes4* src);
extern void cVector_opSub(V4* out, V4* a, V4* b);
#if 0 /* merge_units */
extern void cVector_Cross(V4* out, V4* a, V4* b);
#endif /* merge_units */
void cVector_Cross(void*, void*, void*); /* merge_units */
#define cVector_Cross(a0, a1, a2) (cVector_Cross((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

extern float cVector_GetLength(V4* v);
extern float cVector_Dot(V4* a, V4* b);
extern char cMaterialPropertiesTable_Lookup_charP(void* tbl, char* name);
extern char D_0053BB90[];

/* cCollisionModel_Data_FixUpPointers: fixes up offsets in a loaded collision blob and converts
 * old-format triangles (v<4: 0x40 stride, v==4: 0x20) to the packed form. */
#pragma push
#pragma opt_unroll_loops off

static inline void Col_FixTri(char* tri, V4* verts, int v)
{
    unsigned int j;
    unsigned int j2;
    unsigned int j3;
    V4 n;
    V4 e1;
    V4 e2;
    V4 c;
    int idx[3];
    Bytes4 col;
    char* p;
    int* ip;

    if (v < 5) {
        p = tri;
        cVector_ctor_cVectorR(&n, (V4*)tri);
        tFaceFlags_ctor(&col);
        if (v < 4) {
            ip = idx; p += 0x30;
            for (j = 0; j < 3; j++) {
                ip[j] = *(int*)p; p += 4;
            }
            tFaceFlags_opAssign(&col, (Bytes4*)p);
        } else {
            ip = idx; p += 0x10;
            for (j2 = 0; j2 < 3; j2++) {
                ip[j2] = *(int*)p; p += 4;
            }
            tFaceFlags_opAssign(&col, (Bytes4*)p);
        }
        cVector_opSub(&e1, &verts[idx[1]], &verts[idx[0]]);
        cVector_opSub(&e2, &verts[idx[2]], &verts[idx[0]]);
        cVector_Cross(&c, &e1, &e2);
        ((ColTri*)tri)->f0 = 1.0f / cVector_GetLength(&c);
        if (cVector_Dot(&c, &n) < 0.0f) {
            ((ColTri*)tri)->f0 = -((ColTri*)tri)->f0;
        }
        for (j3 = 0; j3 < 3; j3++) {
            ((ColTri*)tri)->idx[j3] = ip[j3];
        }
        tFaceFlags_opAssign((Bytes4*)((ColTri*)tri)->col, &col);
    }
}

void cCollisionModel_Data_FixUpPointers(ColHdr* h)
{
    unsigned int x;
    unsigned int y;
    unsigned int m;
    unsigned int k;
    unsigned int i;
    ColNode* n;
    unsigned int j;
    int v;

    if (h->tag == 'F') {
        return;
    }
    if (h->nodes) h->nodes = (int)((char*)h + h->nodes);
    if (h->leaves) h->leaves = (int)((char*)h + h->leaves);
    if (h->tris) h->tris = (int)((char*)h + h->tris);
    if (h->verts) h->verts = (int)((char*)h + h->verts);
    if (h->p24) h->p24 = (int)((char*)h + h->p24);
    if (h->version >= 3) {
        if (h->surf) h->surf = (int)((char*)h + h->surf);
    }

    for (i = 0; i < h->nNodes; i++) {
        n = &((ColNode*)h->nodes)[i];
        for (j = 0; j < 8; j++) {
            int* p = &n->child[j]; if (*p) *p = (int)((char*)h + *p);
        }
    }

    for (m = 0; m < h->nLeaves; m++) {
        ColLeaf* l = &((ColLeaf*)h->leaves)[m];
        if (l->p) l->p = (int)((char*)h + l->p);
    }

    for (k = 0; k < h->nTris; k++) {
        v = h->version;
        if (v < 4) {
            Col_FixTri((char*)&((ColTri40*)h->tris)[k], (V4*)h->verts, v);
        } else if (v < 5) {
            Col_FixTri((char*)&((ColTri20*)h->tris)[k], (V4*)h->verts, v);
        } else {
            Col_FixTri((char*)&((ColTri*)h->tris)[k], (V4*)0, v);
        }
    }

    if (h->version >= 3) {
        for (i = 0; i < h->nSurf; i++) {
            ColSurf* s = &((ColSurf*)h->surf)[i];
            s->b1 = cMaterialPropertiesTable_Lookup_charP(D_0053BB90, s->name);
        }
    }

    if (h->version < 2) {
        for (x = 0; x < h->nTris; x++) {
            for (y = 0; y < 3; y++) {
                unsigned char* p = &((ColTri*)h->tris)[x].rgb[y];
                if (h->version < 2) {
                    *p <<= 1;
                }
            }
        }
    }

    h->tag = 'F';
}

#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C19F0(void) {}
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_Cross /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C19F0 */

/* merge_units: begin func_003C21A0 */
#pragma push /* merge_units */
/* Retail loads the byte fields before storing them (copy propagation off). */
#pragma opt_propagation off


/* Copies four bytes (e.g. an RGBA color) and returns the destination. */
Bytes4* tFaceFlags_opAssign(Bytes4* dst, Bytes4* src)
{
    unsigned char g, b, a;
    dst->c[0] = src->c[0];
    g = src->c[1];
    b = src->c[2];
    a = src->c[3];
    dst->c[1] = g;
    dst->c[2] = b;
    dst->c[3] = a;
    return dst;
}
static inline void merge_flush_func_003C21A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C21A0 */

/* merge_units: begin func_003C21D0 */
#pragma push /* merge_units */
char* tFaceFlags_ctor(char* p)
{
    volatile char* q;
    *p = 0;
    q = p + 1;
    do {
        *q = 0;
        q++;
    } while (q != p + 4);
    return p;
}
static inline void merge_flush_func_003C21D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C21D0 */

/* merge_units: begin func_003C2210 */
#pragma push /* merge_units */
/* cRayMatrix::cRayMatrix(const cVector& losStartPoint, const cVector& losVector, float losRadius) (003C2210).
 * Inline-local stack order follows inline nesting depth: MakeAxes/Invert are reached through 3-deep inline wrappers.
 * The void* xx = this locals keep retail's dead addius; function-local statics are written as explicit guards. */
#pragma cplusplus on
#pragma inline_depth(4)
#pragma always_inline on

struct cMatrix;
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d);
    cVector(float a, float b, float c) : x(a), y(b), z(c), w(0.0f) {}
    cVector(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); }
    cVector& Asg0(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& operator=(const cVector& o)
    {
        void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory");
        return *this;
    }
    cVector operator+(const cVector& o) const
    {
        cVector r;
        __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    cVector operator*(float s) const
    {
        cVector r;
        __int128 t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=r"(t) : "r"(&r), "r"(this), "f"(s) : "memory");
        return r;
    }
    float Length() const
    {
        float len;
        __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2 %0, vf4" : "=r"(len) : "r"(this) : "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct cLineSegment {
    cVector p[2];
};

struct cMatrix {
    cVector row[4];
};

struct cRayMatrix {
    cMatrix m;
    cLineSegment lineSegment;
};

extern "C" {
extern signed char D_00542CE8;
extern signed char D_00542CF0;
extern signed char D_00542CF8;
extern cVector D_004BD070;
extern cVector D_004BD080;
extern cVector D_004BD090;
cVector* cVector_ctor_float_float_float_float(cVector*, float, float, float, float);
#if 0 /* merge_units */
cVector* cVector_ctor_cVectorR(cVector*, const cVector*);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((cVector *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cVector_Cross(cVector* ret, const cVector* a, const cVector* b);
#endif /* merge_units */
#define cVector_Cross(a0, a1, a2) (cVector_Cross((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

unsigned char cVector_IsZeroXYZ(const cVector*);
void cVector_GetNormalized_void(cVector* ret, const cVector*);
cVector* cVector_Normalize_void(cVector*);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix*, const cVector*, const cVector*, const cVector*, const cVector*);
void cMatrix_MakeLookAtMatrix_cVectorR(cMatrix*, const cVector*);
void cMatrix_SetUnit(cMatrix*);
void cMatrix_InvertRot(cMatrix*);
unsigned char cMatrix_IsZeroTranslation(const cMatrix*);
const cVector* func_00133EC0(const cMatrix*);
void cVector_NegateXYZ(cVector*);
void cVector_Rotate_cMatrixR(cVector*, const cMatrix*);
void cMatrix_SetTranslation(cMatrix*, const cVector*);
void cMatrix_SetAxes(cMatrix*, const cVector*, const cVector*, const cVector*);
}

#define worldX D_004BD070
#define worldY D_004BD080
#define worldZ D_004BD090
static inline float Abs(float f) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "=f"(r) : "f"(f)); return r; }
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline void Construct(cLineSegment& ls, const cVector& a, const cVector& b) { cVector* p = ls.p; do { ++p; } while (p != ls.p + 2); ls.p[0].Asg0(a); ls.p[1].Asg0(b); }
static inline void MakeAxes(cMatrix* m, const cVector& dir, const cVector& up)
{
    cVector side;
    cVector_Cross(&side, &dir, &up);
    if (!cVector_IsZeroXYZ(&side)) {
        cVector fwd; cVector x; cVector y; cVector t;
        cVector_GetNormalized_void(&fwd, &dir);
        cVector_ctor_cVectorR(&x, cVector_Normalize_void(&side));
        cVector_Cross(&y, &x, &fwd);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &x, &fwd, &y, cVector_ctor_float_float_float_float(&t, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, &dir);
    } else {
        cMatrix_SetUnit(m);
    }
}
static inline void Invert(cMatrix* m)
{
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        cVector t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
static inline void MakeAxes2(cMatrix* m, const cVector& dir, const cVector& up) { MakeAxes(m, dir, up); }
static inline void Invert2(cMatrix* m) { Invert(m); }
static inline void MakeAxes3(cMatrix* m, const cVector& dir, const cVector& up) { MakeAxes2(m, dir, up); }
static inline void Invert3(cMatrix* m) { Invert2(m); }
static inline void SetT0(cMatrix* m, const cVector& t) { m->row[3].Asg0(t); }
static inline cVector AsPoint(cVector v) { cVector* p = &v; p->w = 1.0f; return *p; }

extern "C" cRayMatrix* cRayMatrix_ctor_cVectorR_cVectorR_float(cRayMatrix* self, const cVector& losStartPoint, const cVector& losVector, float losRadius)
{
    Construct(self->lineSegment, losStartPoint, losStartPoint + losVector);
    {
        const cVector* crossVector;
        float absLosX, absLosY, absLosZ, minComponent;
        if (!D_00542CE8) { worldX.x = 1.0f; worldX.y = 0.0f; worldX.z = 0.0f; worldX.w = 0.0f; D_00542CE8 = 1; }
        if (!D_00542CF0) { worldY.x = 0.0f; worldY.y = 1.0f; worldY.z = 0.0f; worldY.w = 0.0f; D_00542CF0 = 1; }
        if (!D_00542CF8) { worldZ.x = 0.0f; worldZ.y = 0.0f; worldZ.z = 1.0f; worldZ.w = 0.0f; D_00542CF8 = 1; }
        absLosX = Abs(losVector.x);
        absLosY = Abs(losVector.y);
        absLosZ = Abs(losVector.z);
        minComponent = Min(Min(absLosX, absLosY), absLosZ);
        if (minComponent == absLosZ) {
            crossVector = &worldZ;
        } else if (minComponent == absLosY) {
            crossVector = &worldY;
        } else {
            crossVector = &worldX;
        }
        MakeAxes3(&self->m, losVector, *crossVector);
    }
    {
        cVector halfLosVector = losVector * 0.5f;
        cVector trans = AsPoint(losStartPoint + halfLosVector);
        SetT0(&self->m, trans);
        Invert3(&self->m);
        {
            float invXZScale = 1.0f / losRadius;
            float yScale = 0.0f;
            float invYScale;
            cVector xAxis, yAxis, zAxis, trans;
            yScale = halfLosVector.Length();
            invYScale = 1.0f / yScale;
            xAxis = self->m.row[0];
            yAxis = self->m.row[1];
            zAxis = self->m.row[2];
            trans = self->m.row[3];
            xAxis.x *= invXZScale;
            yAxis.x *= invXZScale;
            zAxis.x *= invXZScale;
            trans.x *= invXZScale;
            xAxis.y *= invYScale;
            yAxis.y *= invYScale;
            zAxis.y *= invYScale;
            trans.y *= invYScale;
            xAxis.z *= invXZScale;
            yAxis.z *= invXZScale;
            zAxis.z *= invXZScale;
            trans.z *= invXZScale;
            cMatrix_SetAxes(&self->m, &xAxis, &yAxis, &zAxis);
            cMatrix_SetTranslation(&self->m, &trans);
        }
    }
    return self;
}
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_Cross /* merge_units */
static inline void merge_flush_func_003C2210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C2210 */
