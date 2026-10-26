/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_pod_int_opAssign(void*, void*);
extern int Vec16Array_PopBack(Vec16Array*);
extern int cEdgeGroup_dtor(FlagElem16*, int);

/* End pointer of an array of 0x60-byte records. */
Elem60* std_vector_imp_cCollisionEdge_end(Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void std_vector_cCollisionEdge_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem60* std_vector_imp_cCollisionEdge_begin(Vec60Array* v) {
    return v->data;
}

int Vec16Array_PopBack_Thunk(Vec16Array* v) {
    return Vec16Array_PopBack(v);
}

/* Pop the last 16-byte element and destroy it. */
int Vec16Array_PopBack(Vec16Array* v) {
    int count;
    FlagElem16* data;

    count = v->count;
    v->count = count + -1;
    data = v->data;
    return cEdgeGroup_dtor(data + (count + -1), -1);
}

/* Copy-construct: base copy then the flag byte at +0x0C. */
FlagElem16* cEdgeGroup_opAssign(FlagElem16* d, FlagElem16* s) {
    unsigned char flag;

    std_vector_pod_int_opAssign(d, s);
    flag = s->unk0C;
    d->unk0C = flag;
    return d;
}

/* Last element of a 16-byte array. */
FlagElem16* cArray_cEdgeGroup_Back(Vec16Array* v) {
    return (v->data + v->count) + -1;
}
