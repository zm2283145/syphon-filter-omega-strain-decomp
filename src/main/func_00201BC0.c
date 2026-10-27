#include "types.h"

typedef struct { int a; int b; int c; } Elem12;
typedef struct { int unk0; int index; } ElemRef;

extern Elem12** std_vector_deleter_cSkaBlendSequenceItem_data_void_2(ElemRef* self);

/* Returns a pointer to the referenced element of the array returned by std_vector_deleter_cSkaBlendSequenceItem_data_void_2. */
Elem12* std_vector_imp_cSkaBlendSequenceItem_end_void_2(ElemRef* self)
{
    return &(*std_vector_deleter_cSkaBlendSequenceItem_data_void_2(self))[self->index];
}
