/*
 * main/collision: range (2 files, 003C19A0-003C19F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003C19A0 */
#pragma push /* merge_units */
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

extern void Vec4_Assign(V4* d, V4* s);
extern char* tFaceFlags_ctor(Bytes4* p);
extern Bytes4* tFaceFlags_opAssign(Bytes4* dst, Bytes4* src);
extern void Sphere_FromCenter(V4* out, V4* a, V4* b);
extern void Vec4_Cross(V4* out, V4* a, V4* b);
extern float Vec4_Length(V4* v);
extern float Vec4_Dot3(V4* a, V4* b);
extern char MaterialProps_Find(void* tbl, char* name);
extern char D_0053BB90[];

/* Col_Relocate: fixes up offsets in a loaded collision blob and converts
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
        Vec4_Assign(&n, (V4*)tri);
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
        Sphere_FromCenter(&e1, &verts[idx[1]], &verts[idx[0]]);
        Sphere_FromCenter(&e2, &verts[idx[2]], &verts[idx[0]]);
        Vec4_Cross(&c, &e1, &e2);
        ((ColTri*)tri)->f0 = 1.0f / Vec4_Length(&c);
        if (Vec4_Dot3(&c, &n) < 0.0f) {
            ((ColTri*)tri)->f0 = -((ColTri*)tri)->f0;
        }
        for (j3 = 0; j3 < 3; j3++) {
            ((ColTri*)tri)->idx[j3] = ip[j3];
        }
        tFaceFlags_opAssign((Bytes4*)((ColTri*)tri)->col, &col);
    }
}

void Col_Relocate(ColHdr* h)
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
            s->b1 = MaterialProps_Find(D_0053BB90, s->name);
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
#pragma pop /* merge_units */
/* merge_units: end func_003C19F0 */
