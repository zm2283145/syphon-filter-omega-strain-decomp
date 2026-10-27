#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

extern void compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(Obj3* self, int arg);

/* Constructor: base init with 0, then clears the two following words. */
Obj3* std_vector_deleter_cSkaBlendSequenceItem_ctor_void(Obj3* self) {
    compressed_pair_cAllocator_cSkaBlendSequenceItem_int_ctor_uint(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
