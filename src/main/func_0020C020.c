#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { int head; char rest[4]; } Pair;
extern void cPointer_cSkaNode_ctor_cPointerR(Pair* dst, Pair* src);
extern void cArray_cSkaTransBLEND_ctor_cArrayR(void* dst, void* src);

/* Copies both parts of the pair; returns dst. */
Pair* cSkaSwitchItem_ctor_cSkaSwitchItemR(Pair* dst, Pair* src)
{
    cPointer_cSkaNode_ctor_cPointerR(dst, src);
    cArray_cSkaTransBLEND_ctor_cArrayR(dst->rest, src->rest);
    return dst;
}
