/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_00183B60(void* self, int* it);

/* Iterator dereferences (return *it). */
int func_00183AF0(void* self, int* it) {
    return it[0];
}

/* Surface index of a collision triangle (research COL_GATHER_NATIVE.md). */
unsigned char Triangle_GetSurface(Tri* t) {
    return t->b10 >> 1;
}

int func_00183B10(void* self, int* it) {
    return it[0];
}

int func_00183B20(void* self, int* it) {
    return it[0];
}

/* Pass a copy of the iterator to func_00183B60. */
int func_00183B30(void* self, int* it) {
    int copy[1];

    copy[0] = it[0];
    return func_00183B60(self, copy);
}
