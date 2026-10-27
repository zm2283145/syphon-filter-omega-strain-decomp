/*
 * Libs/SFOLib/Source/collision: 3 files, 003C0D90-003C0E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C0D90 */
#pragma push /* merge_units */
#include "types.h"

void cCollisionModel_EdgeId_GetIndicesIntoFaceVertexList(int a0, int a1, int a2, int a3) {
    int v1;
    int cond;

    v1 = *(int*)((char*)a0 + 4);
    cond = v1 != 0;
    if (cond) goto L003C0DB8;
    *(int*)(char*)a1 = 0;
    v1 = 0 + 1;
    *(int*)(char*)a2 = v1;
    v1 = 0 + 2;
    *(int*)(char*)a3 = v1;
    goto L003C0DE8;
L003C0DB8:;
    a0 = 0 + 1;
    cond = v1 != a0;
    if (cond) goto L003C0DD8;
    *(int*)(char*)a1 = a0;
    v1 = 0 + 2;
    *(int*)(char*)a2 = v1;
    *(int*)(char*)a3 = 0;
    goto L003C0DE8;
L003C0DD8:;
    v1 = 0 + 2;
    *(int*)(char*)a1 = v1;
    *(int*)(char*)a2 = 0;
    *(int*)(char*)a3 = a0;
L003C0DE8:;
    goto ret;
ret:;
}
static inline void merge_flush_func_003C0D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0D90 */

/* merge_units: begin func_003C0DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int std_vector_cCollisionEdge_capacity(char* self) {
    return *(int*)(self + 0);
}
static inline void merge_flush_func_003C0DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0DF0 */

/* merge_units: begin func_003C0E00 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003C0E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0E00 */
