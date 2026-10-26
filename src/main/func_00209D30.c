#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 2

extern void opDelete_cSkaBlendSequenceItemP_int_bool_charP_etc(void* obj, int a1, int a2, const char* name, int a4);

/* Calls opDelete_cSkaBlendSequenceItemP_int_bool_charP_etc(obj, 0, 0, "allocator.hh", 100) when obj is non-null. */
void cAllocator_cSkaBlendSequenceItem_deallocate(void* self, void* obj)
{
    if (obj)
        opDelete_cSkaBlendSequenceItemP_int_bool_charP_etc(obj, 0, 0, "allocator.hh", 100);
}
