#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(Obj* self, int a);

/* Constructor: base init then clears +4/+8. */
Obj* std_vector_deleter_cSkaSwitchItem_ctor_void(Obj* self)
{
    compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_uint(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
