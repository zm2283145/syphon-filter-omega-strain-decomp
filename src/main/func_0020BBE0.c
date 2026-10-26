#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

extern void compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_cAllocatorR_uint(Obj3* self, int arg, int flags);

/* Constructor: base init with (arg, 0), then clears the two following words. */
Obj3* std_vector_deleter_cSkaSwitchItem_ctor_cAllocatorR(Obj3* self, int arg) {
    compressed_pair_cAllocator_cSkaSwitchItem_int_ctor_cAllocatorR_uint(self, arg, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
