#include "types.h"

typedef struct { char b[20]; } Elem20;
typedef struct { int unk0; int count; Elem20* data; } Vec20;
typedef struct { void* begin; void* end; void* cap; } VecImpl;
typedef struct { char unused; } Allocator;
extern void func_003B6F80(VecImpl* self, Elem20* first, Elem20* last, Allocator alloc);

/* Copy-constructs the vector from the range of src. */
VecImpl* func_003B4EB0(VecImpl* self, Vec20* src)
{
    Allocator alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    func_003B6F80(self, src->data, src->data + src->count, alloc);
    return self;
}
