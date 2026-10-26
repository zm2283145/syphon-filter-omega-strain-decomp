#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { int unk0; int count; char* data; } ByteVec;

extern void std_vector_pod_eRequirementState_init(ByteVec* self, char* begin, char* end, Alloc alloc);

/* Copy-constructs a byte vector from src's [data, data + count) range; returns self. */
ByteVec* std_vector_pod_eRequirementState_ctor(ByteVec* self, ByteVec* src)
{
    Alloc alloc;
    self->unk0 = 0;
    self->count = 0;
    self->data = 0;
    std_vector_pod_eRequirementState_init(self, src->data, src->data + src->count, alloc);
    return self;
}
