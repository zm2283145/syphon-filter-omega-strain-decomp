#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { char pad[0xC]; unsigned char flag; } Item0C;
extern void std_vector_cSkaTransBLEND_ctor_vectorR(Item0C* dst, Item0C* src);

/* Copies the base part with std_vector_cSkaTransBLEND_ctor_vectorR, then the flag byte; returns dst. */
Item0C* cArray_cSkaTransBLEND_ctor_cArrayR(Item0C* dst, Item0C* src)
{
    std_vector_cSkaTransBLEND_ctor_vectorR(dst, src);
    dst->flag = src->flag;
    return dst;
}
