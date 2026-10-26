#include "types.h"
typedef struct { char c; } Tag_201B60;
extern int std_vector_imp_cSkaBlendSequenceItem_begin_void(void* o);
extern int std_vector_imp_cSkaBlendSequenceItem_end_void_2(void* o);
extern void Vector_Assign_209A20(void* self, int first, int last, Tag_201B60 t);
void* std_vector_imp_cSkaBlendSequenceItem_opAssign(void* self, void* o)
{
    if (self != o) {
        Tag_201B60 t;
        int first = std_vector_imp_cSkaBlendSequenceItem_begin_void(o);
        Vector_Assign_209A20(self, first, std_vector_imp_cSkaBlendSequenceItem_end_void_2(o), t);
    }
    return self;
}