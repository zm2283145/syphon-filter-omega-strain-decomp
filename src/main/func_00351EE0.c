#include "types.h"
typedef struct { char unused; } Alloc00351EE0; /* empty allocator object passed by value */
typedef struct { char data[20]; } Elem00351EE0;
typedef struct { int unk0; int count; Elem00351EE0* items; } Src00351EE0;
typedef struct { int begin; int end; int cap; } Vec00351EE0;
extern void func_003521A0(Vec00351EE0* v, Elem00351EE0* first, Elem00351EE0* last, Alloc00351EE0 alloc);
/* Construct an empty vector and fill it from src's items. */
Vec00351EE0* func_00351EE0(Vec00351EE0* v, Src00351EE0* src)
{
    Alloc00351EE0 alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    func_003521A0(v, src->items, src->items + src->count, alloc);
    return v;
}
