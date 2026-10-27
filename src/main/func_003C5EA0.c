#pragma cplusplus on
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct H { int v; H(int x) { v = x; } };
struct HO { int v; };
struct CtNode { V4 box[2]; int child[8]; };
struct CtLeaf { V4 box[2]; unsigned int count; int idx; };
struct CtTri { char pad[4]; unsigned short v[3]; };
struct CtMesh;
struct CtOut;

extern "C" {
extern int D_00542D10;
int cCollisionModel_Data_IsTreeLeaf(CtMesh* m, const H& h);
CtNode* cCollisionModel_Data_GetTreeNode(CtMesh* m, const H& h);
unsigned char cCollisionModel_Data_TestBox(CtMesh* m, void* box);
int cCollisionModel_TreeLink_opNe(int* p, int z);
void cCollisionModel_TreeLink_ctor(HO* d, int* s);
void cCollisionModel_TreeLink_dtor(HO* h, int f);
CtLeaf* cCollisionModel_Data_GetTreeLeaf(CtMesh* m, const H& h);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(CtMesh* m, CtOut* out, CtLeaf* l, int x);
int cVU0Man_GetProgAddr(int* d, int n);
void cCollisionModel_Address_int_ctor(HO* d, int* s);
int* cCollisionModel_Data_GetFaceIndices(CtMesh* m, HO* h);
void cCollisionModel_Address_int_dtor(HO* h, int f);
CtTri* cCollisionModel_Data_GetFace(CtMesh* m, int t);
V4* cCollisionModel_Data_GetVertex(CtMesh* m, unsigned short v);
unsigned char cCollisionModel_Data_TestFace(CtMesh* m, V4* a, V4* b, V4* c);
void cCollisionFaceCollector_AddFace(CtOut* out, CtMesh* m, CtTri* t, int i);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(CtMesh* m, CtOut* out, CtNode* node, int x);
}

static inline unsigned char BoxTest(void* unused, V4* a) {
    V4* b = a + 1;
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vcallmsr vi27
        cfc2.i r, vi1
        .set reorder
    }
    return r;
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


extern "C" void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(CtMesh* m, CtOut* out, CtNode* node, int x)
{
    if (BoxTest(0, node->box)) {
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
                    if ((unsigned char)cCollisionModel_Data_TestBox(m, sub)) {
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
                                    cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(m, out, cCollisionModel_Data_GetTreeNode(m, *(H*)&h), x);
                                    cCollisionModel_TreeLink_dtor(&h, -1);
                                } else {
                                    HO h;
                                    cCollisionModel_TreeLink_ctor(&h, c);
                                    cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(m, out, cCollisionModel_Data_GetTreeLeaf(m, *(H*)&h), x);
                                    cCollisionModel_TreeLink_dtor(&h, -1);
                                }
                            }
                        }
                    }
                    sub = 0; /* dead store: keeps the failed sub-box test branching to this arm's own exit block (retail does not thread it to the loop increment) */
                } else {
                    CtLeaf* l;
                    HO* p6 = &h6;
                    p6->v = *ref;
                    l = cCollisionModel_Data_GetTreeLeaf(m, *(H*)p6);
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
        }
    }
}
