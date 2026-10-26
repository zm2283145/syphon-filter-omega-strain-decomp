/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int Vector_Insert_1EEF30(Vec16Array* v, FlagElem16* pos, int n, int value);

/* push_back(value) on an array of 16-byte elements. */
int cArray_cEdgeGroup_PushBackActual(Vec16Array* v, int value) {
    int count;
    FlagElem16* data;

    count = v->count;
    data = v->data;
    return Vector_Insert_1EEF30(v, data + count, 1, value);
}
