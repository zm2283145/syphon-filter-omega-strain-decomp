#include "types.h"
typedef struct { char c; } Tag_201B60;
extern int func_00201C10(void* o);
extern int func_00201BC0(void* o);
extern void Vector_Assign_209A20(void* self, int first, int last, Tag_201B60 t);
void* func_00201B60(void* self, void* o)
{
    if (self != o) {
        Tag_201B60 t;
        int first = func_00201C10(o);
        Vector_Assign_209A20(self, first, func_00201BC0(o), t);
    }
    return self;
}