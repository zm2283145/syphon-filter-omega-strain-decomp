#include "types.h"
typedef struct { int h; } H_181CF0;
typedef struct { char pad[0x20]; int child[8]; } N_181CF0;
typedef struct { char pad0[2]; signed char kind; char pad3; int count; int root; char padC[4]; int leaf; } T_181CF0;
extern N_181CF0* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(T_181CF0* t, H_181CF0* h);
extern int cBox_Intersects(N_181CF0* n, void* b);
extern int cCollisionModel_TreeLink_opNe(int* c, int f);
extern void cCollisionModel_TreeLink_ctor(H_181CF0* out, int* c);
extern unsigned char cCollisionModel_Data_IsTreeLeaf(T_181CF0* t, H_181CF0* h);
extern void cCollisionModel_TreeLink_dtor(H_181CF0* h, int f);
extern void* cCollisionModel_Data_GetTreeNode(T_181CF0* t, H_181CF0* h);
extern void* cCollisionModel_Data_GetTreeLeaf(T_181CF0* t, H_181CF0* h);
extern void* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(T_181CF0* t, H_181CF0* h);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(T_181CF0* t, void* a, void* n, void* b);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(T_181CF0* t, void* a, void* n, void* b);
void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cBoxR(T_181CF0* t, void* a, void* b)
{
    H_181CF0 h8C;
    H_181CF0 h88;
    H_181CF0 h84;
    H_181CF0 h80;
    H_181CF0 h7C;
    if (t->kind != 'F') return;
    if (t->count > 0) {
        N_181CF0* n;
        h8C.h = t->root;
        n = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(t, &h8C);
        if (cBox_Intersects(n, b)) {
            int* c = n->child;
            unsigned int i;
            for (i = 0; i < 8; i++, c++) {
                if (cCollisionModel_TreeLink_opNe(c, 0)) {
                    unsigned char leaf;
                    cCollisionModel_TreeLink_ctor(&h84, c);
                    leaf = cCollisionModel_Data_IsTreeLeaf(t, &h84);
                    cCollisionModel_TreeLink_dtor(&h84, -1);
                    if (!leaf) {
                        cCollisionModel_TreeLink_ctor(&h80, c);
                        cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(t, a, cCollisionModel_Data_GetTreeNode(t, &h80), b);
                        cCollisionModel_TreeLink_dtor(&h80, -1);
                    } else {
                        cCollisionModel_TreeLink_ctor(&h7C, c);
                        cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(t, a, cCollisionModel_Data_GetTreeLeaf(t, &h7C), b);
                        cCollisionModel_TreeLink_dtor(&h7C, -1);
                    }
                }
            }
        }
    } else {
        h88.h = t->leaf;
        cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(t, a, cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(t, &h88), b);
    }
}