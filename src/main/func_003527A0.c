#include "types.h"

typedef struct { char unused; } Alloc;
typedef struct { int begin; int end; int cap; } Vec;
typedef struct { int unk0; int count; int data; } Src;
extern void func_003527F0(Vec* self, int first, int last, Alloc alloc);

/* Copy-constructs a range container from src's [data, data+count). */
Vec* func_003527A0(Vec* self, Src* src)
{
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    func_003527F0(self, src->data, src->data + src->count, alloc);
    return self;
}
