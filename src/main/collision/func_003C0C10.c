#include "types.h"
typedef struct { int unk0; unsigned short verts[1]; } TriData;
typedef struct { void* mesh; } MeshRef;
typedef struct { int unk0; MeshRef* ref; } ColTri;
extern void func_003C0D90(void* ctx, int* a, int* b, int* c);
extern int func_003C0D80(void* ctx);
extern TriData* func_003C0CF0(void* mesh, int index);
extern void* func_00231EC0(void* mesh, unsigned short vert);
/* Looks up the three vertex pointers of the triangle referenced by ctx. */
void ColTri_GetVertices(ColTri* tri, void** v0, void** v1, void** v2, void* ctx)
{
    int i2, i1, i0;
    void* mesh = tri->ref->mesh;
    TriData* data;
    func_003C0D90(ctx, &i0, &i1, &i2);
    data = func_003C0CF0(mesh, func_003C0D80(ctx));
    *v0 = func_00231EC0(mesh, data->verts[i0]);
    *v1 = func_00231EC0(mesh, data->verts[i1]);
    *v2 = func_00231EC0(mesh, data->verts[i2]);
}
