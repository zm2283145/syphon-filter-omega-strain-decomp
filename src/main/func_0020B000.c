#include "types.h"
#pragma optimization_level 1
typedef struct { int w0; } Item0B000;
extern void cAllocator_cSkaTransBLEND_ctor_cAllocatorR(Item0B000* dst);
Item0B000* details_compressed_pair_imp_cAllocator_cSkaTransBLEND_int_1_ctor_cAllocatorR_uint(Item0B000* dst, int unused, int v)
{
    cAllocator_cSkaTransBLEND_ctor_cAllocatorR(dst);
    dst->w0 = v;
    return dst;
}