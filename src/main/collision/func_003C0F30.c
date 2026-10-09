/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "collision_types.h"

/* Vertex index i of a raw triangle. */
int ColTri_GetVertIndex(ColTri* tri, int i) {
    return tri->vert[i];
}

int func_003C0F40(char* self) {
    return *(int*)(self + 4);
}

void* func_003C0F50(char* self) {
    return self + 8;
}

/* Address of the three edge flag bytes. */
unsigned char* ColTri_GetEdgeFlags(ColTri* tri) {
    return tri->edgeFlags;
}
