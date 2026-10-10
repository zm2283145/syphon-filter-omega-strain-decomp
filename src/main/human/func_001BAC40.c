#include "types.h"
typedef struct { int f0; unsigned int count; int* data; } D2_PtrVec;
typedef struct { int f0; int count; int* data; } D2_PtrVecI;
extern int PtrVec_Insert(D2_PtrVec* v, int* pos, int n, int value);
extern void PtrVector_Erase(D2_PtrVec* v, int* first, int* last);
#pragma opt_common_subs off
void PtrVector_Resize(D2_PtrVec* v, unsigned int n, int value) {
    unsigned int c = v->count;
    if (c < n) {
        PtrVec_Insert(v, v->data + v->count, n - c, value);
    } else if (n < c) {
        int* d = v->data;
        PtrVector_Erase(v, d + n, d + v->count);
    }
}
#pragma opt_common_subs reset
