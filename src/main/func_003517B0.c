#include "types.h"

typedef struct { char unused; } Alloc;
typedef struct { char data[0x14]; } Elem;
typedef struct { int unk0; int count; Elem* data; unsigned char flag; } Vec;
extern void func_00352460(Vec* self, Elem* first, Elem* last, Alloc alloc);

/* Copy-assigns a vector of 20-byte elements and its flag byte. */
Vec* func_003517B0(Vec* self, Vec* other)
{
    Alloc alloc;
    if (self != other) {
        func_00352460(self, other->data, other->data + other->count, alloc);
    }
    self->flag = other->flag;
    return self;
}
