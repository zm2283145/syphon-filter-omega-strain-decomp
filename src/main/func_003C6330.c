#include "types.h"
typedef struct F1V3_6330 { float x, y, z; } F1V3_6330;
typedef struct F1Shape6330 { char pad0[2]; signed char kind; char pad3; int count; } F1Shape6330;
typedef struct F1Holder6330 { F1Shape6330* shape; } F1Holder6330;
typedef struct F1Obj6330 { int pad0; F1Holder6330* holder; } F1Obj6330;
extern char D_00542D10[];
extern void* cVU0Man_GetWritableMemory(void* tab, int n);
extern void cRayMatrix_opAssign(void* p, int arg);
extern void nCollision_SyncAfterTransferDataToVu0(void);
extern int cCollisionModel_Data_GetTreeRootNode(F1Shape6330* s);
extern int cCollisionModel_Data_GetTreeSoleLeaf(F1Shape6330* s);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(F1Shape6330* s, F1V3_6330* v, int n, int arg);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(F1Shape6330* s, F1V3_6330* v, int n, int arg);
void cCollisionModel_GetNearFaces_cCollisionFaceCollector_cRayMatrixR(F1Obj6330* obj, F1V3_6330* pos, int arg)
{
    F1V3_6330 v;
    F1Shape6330* s;
    v = *pos;
    *(F1Obj6330**)&v.y = obj;
    s = obj->holder->shape;
    if (s->kind == 0x46) {
        cRayMatrix_opAssign(cVU0Man_GetWritableMemory(D_00542D10, 0), arg);
        nCollision_SyncAfterTransferDataToVu0();
        if (s->count > 0) {
            cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cRayMatrixR(s, &v, cCollisionModel_Data_GetTreeRootNode(s), arg);
        } else {
            cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cRayMatrixR(s, &v, cCollisionModel_Data_GetTreeSoleLeaf(s), arg);
        }
    }
}