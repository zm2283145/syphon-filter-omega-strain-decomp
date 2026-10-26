#include "types.h"
extern void opNew_uint_int_charP_int(int size, int a, char* name, int b);
/* Allocates count 36-byte records. */
#pragma optimization_level 1
void cAllocator_cSkaTransBLEND_allocate(void* unused, int count) { opNew_uint_int_charP_int(count * 36, 0, "allocator.hh", 0x5C); }
#pragma optimization_level reset
