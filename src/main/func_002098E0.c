#include "types.h"

extern void opNew_uint_int_charP_int(int size, int a1, const char* name, int line);

/* Allocates count 12-byte entries (tagged with "allocator.hh", line 0x5C). */
#pragma optimization_level 1
void cAllocator_cSkaBlendSequenceItem_allocate(void* self, int count)
{
    opNew_uint_int_charP_int(count * 12, 0, "allocator.hh", 0x5C);
}
#pragma optimization_level reset
