// cCollisionModel_Data::GetNearFaces<cBox>(collector, const TreeLeaf&, const cBox&). Box tests are inlined
// `asm volatile` blocks (leaf box vs test box, then triangle bounds vs test box).
#pragma cplusplus on
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct CtBox { V4 lo, hi; };
struct CtLeaf { CtBox box; int faceCount; int faceIndices; };
struct CtMesh { char pad0[3]; unsigned char versionNumber; char pad4[0x14]; int faceList; char pad1C[4]; int vertexList; };
struct CtOut { int vec; int model; unsigned char mask; };
struct CtFace { float scale; unsigned short v[3]; char flags[2]; };
struct CtRec { char pad[0x74]; };

extern "C" {
int* cCollisionModel_Data_GetFaceIndices(CtMesh* m, int* p);
char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(CtMesh* m, int* p);
char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(CtMesh* m, int* p);
int cCollisionModel_Face_GetPropertiesIndex(CtFace* t);
int cCollisionModel_Data_GetFaceProperties(CtMesh* m, int s);
int tFaceFlags_GetMaskedBits(void* f, unsigned char mask);
int cCollisionModel_FaceProperties_GetMaskedBits(int s, unsigned char mask);
int cArray_cCollisionFace_Size(int v);
int cArray_cCollisionFace_Capacity(int v);
void cArray_cCollisionFace_ReserveActual(int v, int n);
void cArray_cCollisionFace_ResizeActual(int v, int n, CtRec* r);
int cArray_cCollisionFace_Back(int v);
void cCollisionFace_ctor_void(CtRec* r);
void cCollisionFace_dtor(CtRec* r, int f);
void cCollisionFace_SetWithoutCalculatingNormal(int p, CtFace* t, int i, int s, int x);
}

static inline unsigned char BoxIntersects(const CtBox* a, const CtBox* b)
{
    const V4* ahi = &a->hi;
    const V4* bhi = &b->hi;
    int r;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(bhi)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(ahi)
        lqc2 vf2, 0(b)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}

static inline unsigned char TriIntersects(const V4* a, const V4* b, const V4* c, const CtBox* t)
{
    const V4* thi = &t->hi;
    int r;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmax.xyz vf5, vf1, vf2
        vmini.xyz vf4, vf1, vf2
        lqc2 vf3, 0(c)
        vmax.xyz vf5, vf5, vf3
        vmini.xyz vf4, vf4, vf3
        lqc2 vf6, 0(t)
        vsub.xyz vf7, vf5, vf6
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf6, 0(thi)
        vsub.xyz vf7, vf6, vf4
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}

static inline int* GetIdx(CtMesh* m, int o) { return cCollisionModel_Data_GetFaceIndices(m, &o); }
static inline char* GetFaces(CtMesh* m) { int o = m->faceList; return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(m, &o); }
static inline V4* GetVert(CtMesh* m, int i) { int o = m->vertexList; return (V4*)cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(m, &o) + i; }

extern "C" void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(CtMesh* m, CtOut* out, CtLeaf* leaf, const CtBox* b)
{
    if (BoxIntersects(&leaf->box, b)) {
        unsigned int faceCount = leaf->faceCount;
        int* currFace = GetIdx(m, leaf->faceIndices);
        unsigned int i;
        for (i = 0; i < faceCount; i++, currFace++) {
            unsigned int faceIndex = *currFace;
            CtFace* face;
            V4* v0;
            V4* v1;
            V4* v2;
            if (m->versionNumber < 4) {
                face = (CtFace*)(GetFaces(m) + (faceIndex << 6));
            } else if (m->versionNumber < 5) {
                face = (CtFace*)(GetFaces(m) + (faceIndex << 5));
            } else {
                face = (CtFace*)(GetFaces(m) + (faceIndex << 4));
            }
            v0 = GetVert(m, face->v[0]);
            v1 = GetVert(m, face->v[1]);
            v2 = GetVert(m, face->v[2]);
            if (TriIntersects(v0, v1, v2, b)) {
                int props = cCollisionModel_Data_GetFaceProperties(m, cCollisionModel_Face_GetPropertiesIndex(face));
                if (!(unsigned char)tFaceFlags_GetMaskedBits(face->flags, out->mask) && !(unsigned char)cCollisionModel_FaceProperties_GetMaskedBits(props, out->mask)) {
                    CtRec rec;
                    if (cArray_cCollisionFace_Size(out->vec) >= cArray_cCollisionFace_Capacity(out->vec)) {
                        cArray_cCollisionFace_ReserveActual(out->vec, cArray_cCollisionFace_Capacity(out->vec) * 3 / 2);
                    }
                    cCollisionFace_ctor_void(&rec);
                    cArray_cCollisionFace_ResizeActual(out->vec, cArray_cCollisionFace_Size(out->vec) + 1, &rec);
                    cCollisionFace_dtor(&rec, -1);
                    cCollisionFace_SetWithoutCalculatingNormal(cArray_cCollisionFace_Back(out->vec), face, faceIndex, props, out->model);
                }
            }
        }
    }
}
