/*
 * main/collision: range (2 files, 003C0F10-003C0F30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "collision_types.h"

/* merge_units: begin func_003C0F10 */
#pragma push /* merge_units */
typedef struct Cycle3 {
    int unk0;
    int index;
} Cycle3;

/* Returns the next index in a 0..2 cycle. */
unsigned int cCollisionModel_EdgeId_FaceVertexNumber1(Cycle3* c) {
    unsigned int next = c->index + 1;
    return next < 3 ? next : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0F10 */

/* merge_units: begin func_003C0F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vertex index i of a raw triangle. */
int cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(ColTri* tri, int i) {
    return tri->vert[i];
}

int cCollisionModel_EdgeId_FaceVertexNumber0(char* self) {
    return *(int*)(self + 4);
}

void* std_vector_deleter_cCollisionEdge_data(char* self) {
    return self + 8;
}

/* Address of the three edge flag bytes. */
unsigned char* cCollisionModel_Face_GetEdgeFlags(ColTri* tri) {
    return tri->edgeFlags;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0F30 */
