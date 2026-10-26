/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

unsigned char cLosRequest_cCollisionModelList_Game_IsInUse(unsigned char* self) {
    return self[32];
}

ElemE0* cArray_cLosRequest_cCollisionModelList_Game_Iterator_opArrow(ElemE0Iter* it) {
    return it->p;
}

/* End iterator of an array of 0xE0-byte records. */
void cArray_cLosRequest_cCollisionModelList_Game_End(ElemE0Iter* out, VecE0Array* v) {
    out->p = v->data + v->count;
}

void cArray_cLosRequest_cCollisionModelList_Game_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
