/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int Vector_Reserve_139920(int, int);
extern int std_vector_imp_cCollisionFace_resize(int, int, int);

/* Last element of an array of 0x70-byte records. */
Elem70* cArray_cCollisionFace_Back(Vec70Array* v) {
    return (v->data + v->count) + -1;
}

int cArray_cCollisionFace_ResizeActual(int a0, int a1, int a2) {
    return std_vector_imp_cCollisionFace_resize(a0, a1, a2);
}

int Vector_Reserve_139920_Thunk_1839C0(int a0, int a1) {
    return Vector_Reserve_139920(a0, a1);
}

int cArray_cCollisionFace_Capacity(IntPair* p) {
    return p->a;
}

int cArray_cCollisionFace_Size(IntPair* p) {
    return p->b;
}
