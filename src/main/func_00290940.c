/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int PtrVec_Insert(PtrVec*, int*, int, int*);

int* func_00290940(PtrVec* v) {
    return v->data + v->count;
}

void func_00290960(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_00290970(PtrVec* v) {
    return v->data;
}

int** func_00290980(PtrVec* v) {
    return &v->data;
}

void* func_00290990(char* self) {
    return self + 11856;
}

/* push_back */
int func_002909A0(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
