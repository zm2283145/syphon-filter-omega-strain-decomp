#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { int unk0; int count; char* data; } ByteVec;

extern void func_0033B860(ByteVec* self, char* begin, char* end, Alloc alloc);

/* Copy-constructs a byte vector from src's [data, data + count) range; returns self. */
ByteVec* func_0033AA30(ByteVec* self, ByteVec* src)
{
    Alloc alloc;
    self->unk0 = 0;
    self->count = 0;
    self->data = 0;
    func_0033B860(self, src->data, src->data + src->count, alloc);
    return self;
}
