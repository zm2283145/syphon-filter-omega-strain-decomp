/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer-vector helpers (iterator copy, end(), push_back).
 */

#include "loose03_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int* value);

Word* func_0032D040(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end() */
void func_0032D050(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

/* push_back */
int std_vector_GuiWidgetPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

void func_0032D090(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
int* func_0032D0A0(PtrVec* v) {
    return v->data;
}

/* push_back */
int func_0032D0B0(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
