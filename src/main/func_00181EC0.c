// cCollisionModel_Data::GetNearFaces<cBox>(collector, const TreeNode&, const cBox&): one recursion level of
// the child walk is inlined (as in the cRayMatrix variant, cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR). `asm volatile` on the inlined box
// test gives retail's unrotated loops and unfolded stack-handle stores.
#pragma cplusplus on
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct H { int v; H(int x) { v = x; } };
struct HO { int v; };
struct CtBox { V4 lo, hi; };
struct CtNode { CtBox box; int child[8]; };
struct CtLeaf;
struct CtMesh;
struct CtOut;

extern "C" {
int cCollisionModel_Data_IsTreeLeaf(CtMesh* m, const H& h);
CtNode* cCollisionModel_Data_GetTreeNode(CtMesh* m, const H& h);
CtLeaf* cCollisionModel_Data_GetTreeLeaf(CtMesh* m, const H& h);
unsigned char cBox_Intersects(CtBox* a, const CtBox* b);
int cCollisionModel_TreeLink_opNe(int* p, int z);
void cCollisionModel_TreeLink_ctor(HO* d, int* s);
void cCollisionModel_TreeLink_dtor(HO* h, int f);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(CtMesh* m, CtOut* out, CtLeaf* l, const CtBox* b);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(CtMesh* m, CtOut* out, CtNode* node, const CtBox* b);
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

extern "C" void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(CtMesh* m, CtOut* out, CtNode* node, const CtBox* b)
{
    if (BoxIntersects(&node->box, b)) {
        int* ref;
        unsigned int i;
        ref = node->child;
        for (i = 0; i < 8; i++, ref++) {
            if (*ref) {
                HO h1;
                HO h2;
                HO h6;
                HO* p1 = &h1;
                p1->v = *ref;
                if (!(unsigned char)cCollisionModel_Data_IsTreeLeaf(m, *(H*)p1)) {
                    CtNode* sub;
                    HO* p2 = &h2;
                    p2->v = *ref;
                    sub = cCollisionModel_Data_GetTreeNode(m, *(H*)p2);
                    if (cBox_Intersects(&sub->box, b)) {
                        int* c;
                        unsigned int j;
                        c = sub->child;
                        for (j = 0; j < 8; j++, c++) {
                            if (cCollisionModel_TreeLink_opNe(c, 0)) {
                                unsigned char leaf;
                                {
                                    HO h;
                                    cCollisionModel_TreeLink_ctor(&h, c);
                                    leaf = cCollisionModel_Data_IsTreeLeaf(m, *(H*)&h);
                                    cCollisionModel_TreeLink_dtor(&h, -1);
                                }
                                if (!leaf) {
                                    HO h;
                                    cCollisionModel_TreeLink_ctor(&h, c);
                                    cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(m, out, cCollisionModel_Data_GetTreeNode(m, *(H*)&h), b);
                                    cCollisionModel_TreeLink_dtor(&h, -1);
                                } else {
                                    HO h;
                                    cCollisionModel_TreeLink_ctor(&h, c);
                                    cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(m, out, cCollisionModel_Data_GetTreeLeaf(m, *(H*)&h), b);
                                    cCollisionModel_TreeLink_dtor(&h, -1);
                                }
                            }
                        }
                    }
                    sub = 0;
                } else {
                    HO* p6 = &h6;
                    p6->v = *ref;
                    cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(m, out, cCollisionModel_Data_GetTreeLeaf(m, *(H*)p6), b);
                }
            }
        }
    }
}
