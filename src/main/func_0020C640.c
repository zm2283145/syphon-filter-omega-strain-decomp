#include "types.h"
extern void cSkaTransBLEND_dtor(void* p, int flags);
#pragma optimization_level 1
void cAllocator_cSkaTransBLEND_destroy(void* a, void* b)
{
    cSkaTransBLEND_dtor(b, -1);
}
#pragma optimization_level reset