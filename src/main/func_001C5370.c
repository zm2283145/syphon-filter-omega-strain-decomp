#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { int* begin; int* end; int* cap; } IntVec;
extern void func_001C53C0(IntVec* v, int* first, int* last, Alloc alloc);
/* Constructs a vector as a copy of the range held by src. */
IntVec* func_001C5370(IntVec* v, PtrVec* src)
{
    Alloc alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    func_001C53C0(v, src->data, src->data + src->count, alloc);
    return v;
}
