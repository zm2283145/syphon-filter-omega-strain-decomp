#include "types.h"
typedef struct { int tri; int side; void* mesh; } ColEdge_f3;
extern void* cCollisionModel_GetFace(void* mesh, int tri);
extern int cCollisionModel_EdgeId_FaceVertexNumber0(ColEdge_f3* e);
extern int cCollisionModel_EdgeId_FaceVertexNumber1(ColEdge_f3* e);
extern int cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(void* tri, int i);
int cCollisionModel_EdgeLocator_IsSameEdge(ColEdge_f3* a, ColEdge_f3* b, void* mesh)
{
    void* t;
    int a0;
    int a1;
    int b0;
    int b1;
    if (a->mesh == mesh) {
        t = cCollisionModel_GetFace(a->mesh, a->tri);
        a0 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber0(a));
        a1 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber1(a));
        t = cCollisionModel_GetFace(mesh, b->tri);
        b0 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber0(b));
        b1 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber1(b));
        return (a0 == b0 && a1 == b1) || (a0 == b1 && a1 == b0);
    }
    return 0;
}