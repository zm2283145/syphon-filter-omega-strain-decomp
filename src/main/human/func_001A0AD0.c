/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cSkaAnimAnchorListEntry_Anchor(char* self) {
    return self + 16;
}

int cArray_cSkaAnimAnchorListEntry_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* end() over 384-byte elements. */
void cArray_cSkaAnimAnchorListEntry_End(Iter16* out, PtrVec* v) {
    int count = v->count;
    char* data = (char*)v->data;

    out->p = data + count * 384;
}

void cArray_cSkaAnimAnchorListEntry_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cSkaParams_GetAnimAnchorList(char* self) {
    return self + 160;
}
