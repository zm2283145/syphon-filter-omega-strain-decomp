#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_cAllocatorR_uint(Obj* self, int a, int b);

/* Constructor: base init then clears +4/+8. */
#pragma optimization_level 1
Obj* std_vector_deleter_cSkaTransBLEND_ctor_cAllocatorR(Obj* self, int a)
{
    compressed_pair_cAllocator_cSkaTransBLEND_int_ctor_cAllocatorR_uint(self, a, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
#pragma optimization_level reset
