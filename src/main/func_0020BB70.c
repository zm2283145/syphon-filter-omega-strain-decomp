#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 2

extern void opNew_uint_int_charP_int(int size, int a1, const char* name, int a3);

/* Calls opNew_uint_int_charP_int for count entries of 20 bytes, tagged with "allocator.hh". */
void cAllocator_cSkaSwitchItem_allocate(void* self, int count)
{
    opNew_uint_int_charP_int(count * 20, 0, "allocator.hh", 0x5C);
}
