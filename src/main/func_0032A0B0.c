#include "types.h"
typedef struct { char unused; } Alloc0032A0B0; /* empty allocator object passed by value */
typedef struct { char data[44]; } Elem0032A0B0;
typedef struct { int unk0; int count; Elem0032A0B0* items; } Src0032A0B0;
typedef struct { int begin; int end; int cap; } Vec0032A0B0;
extern void func_0032A5A0(Vec0032A0B0* v, Elem0032A0B0* first, Elem0032A0B0* last, Alloc0032A0B0 alloc);
/* Construct an empty vector and fill it from src's items. */
Vec0032A0B0* func_0032A0B0(Vec0032A0B0* v, Src0032A0B0* src)
{
    Alloc0032A0B0 alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    func_0032A5A0(v, src->items, src->items + src->count, alloc);
    return v;
}
