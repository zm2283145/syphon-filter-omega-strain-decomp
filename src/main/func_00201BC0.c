#include "types.h"

typedef struct { int a; int b; int c; } Elem12;
typedef struct { int unk0; int index; } ElemRef;

extern Elem12** MotionChildArr_GetData(ElemRef* self);

/* Returns a pointer to the referenced element of the array returned by MotionChildArr_GetData. */
Elem12* std_vector_imp_cSkaBlendSequenceItem_end_void_2(ElemRef* self)
{
    return &(*MotionChildArr_GetData(self))[self->index];
}
