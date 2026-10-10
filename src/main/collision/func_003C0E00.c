#include "types.h"
typedef struct { int tri; int side; void* mesh; } ColEdge_f3;
extern void* func_001E1E60(void* mesh, int tri);
extern int func_003C0F40(ColEdge_f3* e);
extern int func_003C0F10(ColEdge_f3* e);
extern int ColTri_GetVertIndex(void* tri, int i);
int ColEdge_IsDuplicate(ColEdge_f3* a, ColEdge_f3* b, void* mesh)
{
    void* t;
    int a0;
    int a1;
    int b0;
    int b1;
    if (a->mesh == mesh) {
        t = func_001E1E60(a->mesh, a->tri);
        a0 = ColTri_GetVertIndex(t, func_003C0F40(a));
        a1 = ColTri_GetVertIndex(t, func_003C0F10(a));
        t = func_001E1E60(mesh, b->tri);
        b0 = ColTri_GetVertIndex(t, func_003C0F40(b));
        b1 = ColTri_GetVertIndex(t, func_003C0F10(b));
        return (a0 == b0 && a1 == b1) || (a0 == b1 && a1 == b0);
    }
    return 0;
}