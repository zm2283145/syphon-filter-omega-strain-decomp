#pragma cplusplus on
#include "types.h"

/* cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR: collision-tree box query root - upload the query box to VU0, then walk the root
 * node's children (cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR / cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR) or test the single leaf's triangles. */

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct H { int v; H(int x) { v = x; } };
struct HO { int v; };
struct CtNode { V4 box[2]; int child[8]; };
struct CtLeaf { V4 box[2]; unsigned int count; int idx; };
struct CtTri { char pad[4]; unsigned short v[3]; };
struct CtMeshS { char pad0[2]; signed char kind; char pad3; int nNodes; int root; char padC[4]; int leaf; };
typedef CtMeshS CtMesh;
struct CtBox { V4 v[6]; };
struct CtOut;

extern "C" {
extern int D_00542D10;
int ColTree_IsLeaf(CtMesh* m, const H& h);
CtNode* cCollisionModel_Data_GetTreeNode(CtMesh* m, const H& h);
unsigned char cCollisionModel_Data_TestBox(CtMesh* m, void* box);
int cCollisionModel_TreeLink_opNe(int* p, int z);
void cCollisionModel_TreeLink_ctor(HO* d, int* s);
void cCollisionModel_TreeLink_dtor(HO* h, int f);
CtLeaf* cCollisionModel_Data_GetTreeLeaf(CtMesh* m, const H& h);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(CtMesh* m, CtOut* out, CtLeaf* l, CtBox* box);
int cVU0Man_GetProgAddr(int* d, int n);
void cCollisionModel_Address_int_ctor(HO* d, int* s);
int* cCollisionModel_Data_GetFaceIndices(CtMesh* m, HO* h);
void cCollisionModel_Address_int_dtor(HO* h, int f);
CtTri* cCollisionModel_Data_GetFace(CtMesh* m, int t);
V4* cCollisionModel_Data_GetVertex(CtMesh* m, unsigned short v);
unsigned char cCollisionModel_Data_TestFace(CtMesh* m, V4* a, V4* b, V4* c);
void cCollisionFaceCollector_AddFace(CtOut* out, CtMesh* m, CtTri* t, int i);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(CtMesh* m, CtOut* out, CtNode* node, CtBox* box);
CtNode* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(CtMesh* m, H* h);
CtLeaf* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(CtMesh* m, H* h);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR(CtMesh* m, CtOut* out, CtBox* box);
}

static inline void SetMpg(int a) {
    asm {
        .set noreorder
        ctc2 a, vi27
        vnop
        vnop
        .set reorder
    }
}


extern "C" void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cRayMatrixR(CtMesh* m, CtOut* out, CtBox* box)
{
    HO hr;
    HO hl;
    if (m->kind != 'F') return;
    {
        CtBox* d = (CtBox*)0x11004000;
        __int128 a;
        __int128 b;
        /* upload the query box to VU0 data memory (hand-scheduled quad copy), then wait for VU0 */
        asm volatile {
            lq a, 0(box)
            lq b, 16(box)
            sq a, 0(d)
            lq a, 32(box)
            sq b, 16(d)
            lq b, 48(box)
            sq a, 32(d)
            lq a, 64(box)
            sq b, 48(d)
            lq b, 80(box)
            sq a, 64(d)
            sq b, 80(d)
            vnop
            sync
        }
    }
    if (m->nNodes > 0) {
        CtNode* node;
        hr.v = m->root;
        node = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(m, (H*)&hr);
        if ((unsigned char)cCollisionModel_Data_TestBox(m, node)) {
            int* c;
            unsigned int j;
            c = node->child;
            for (j = 0; j < 8; j++, c++) {
                if (cCollisionModel_TreeLink_opNe(c, 0)) {
                    unsigned char leaf;
                    {
                        HO h;
                        cCollisionModel_TreeLink_ctor(&h, c);
                        leaf = ColTree_IsLeaf(m, *(H*)&h);
                        cCollisionModel_TreeLink_dtor(&h, -1);
                    }
                    if (!leaf) {
                        HO h;
                        cCollisionModel_TreeLink_ctor(&h, c);
                        cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(m, out, cCollisionModel_Data_GetTreeNode(m, *(H*)&h), box);
                        cCollisionModel_TreeLink_dtor(&h, -1);
                    } else {
                        HO h;
                        cCollisionModel_TreeLink_ctor(&h, c);
                        cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(m, out, cCollisionModel_Data_GetTreeLeaf(m, *(H*)&h), box);
                        cCollisionModel_TreeLink_dtor(&h, -1);
                    }
                }
            }
        }
    } else {
        CtLeaf* l;
        hl.v = m->leaf;
        l = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(m, (H*)&hl);
        if (cCollisionModel_Data_TestBox(m, l)) {
            unsigned int n;
            int* ip;
            unsigned int k;
            SetMpg(cVU0Man_GetProgAddr(&D_00542D10, 4));
            n = l->count;
            {
                HO h;
                cCollisionModel_Address_int_ctor(&h, &l->idx);
                ip = cCollisionModel_Data_GetFaceIndices(m, &h);
                cCollisionModel_Address_int_dtor(&h, -1);
            }
            for (k = 0; k < n; k++, ip++) {
                int t = *ip;
                CtTri* tr = cCollisionModel_Data_GetFace(m, t);
                V4* a = cCollisionModel_Data_GetVertex(m, tr->v[0]);
                V4* b = cCollisionModel_Data_GetVertex(m, tr->v[1]);
                V4* c = cCollisionModel_Data_GetVertex(m, tr->v[2]);
                if (cCollisionModel_Data_TestFace(m, a, b, c)) cCollisionFaceCollector_AddFace(out, m, tr, t);
            }
            SetMpg(cVU0Man_GetProgAddr(&D_00542D10, 3));
        }
    }
}
