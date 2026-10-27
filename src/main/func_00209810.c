#include "types.h"

typedef struct { int unk0; int unk4; } Pair209;

extern void cPointer_cSkaNode_ctor_cPointerR(Pair209* dst, Pair209* src);
extern void cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(int* dst, int* src);

#pragma optimization_level 1
/* Copies both halves of src into dst with their helpers; returns dst (unit built at -O1). */
Pair209* cSkaBlendSequenceItem_ctor_cSkaBlendSequenceItemR(Pair209* dst, Pair209* src)
{
    cPointer_cSkaNode_ctor_cPointerR(dst, src);
    cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(&dst->unk4, &src->unk4);
    return dst;
}
#pragma optimization_level reset
