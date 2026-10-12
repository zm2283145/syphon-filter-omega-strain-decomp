/* func_0021C260: 16-byte-element vector erase(first, last). Hand-matched (auto1 family seed). */
#include "types.h"
#pragma opt_unroll_loops off
#pragma opt_dead_assignments off
#pragma opt_rotateloops off
typedef struct { int x[4]; } __attribute__((aligned(16))) E16_C190;
typedef struct { int pad; int size; E16_C190* data; } Vec_C190;
E16_C190* func_0021C260(Vec_C190* v, E16_C190* first, E16_C190* last)
{
    E16_C190* end;
    int n;
    E16_C190* p;
    if (first == last) return first;
    end = v->data + v->size;
    n = end - last;
    if (n != 0) {
        E16_C190* s;
        E16_C190* d;
        d = first; s = last;
        while (s < end) *d++ = *s++;
    }
    p = first + n;
    while (p < end) p = (E16_C190*)((char*)p + 16);
    v->size -= last - first;
    return first;
}

