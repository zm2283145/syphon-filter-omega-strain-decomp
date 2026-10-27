/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cArray_cTerrainPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void cArray_cTerrainPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void* cObjList_cTerrainPtr_GetList(char* self) {
    return self + 4;
}
