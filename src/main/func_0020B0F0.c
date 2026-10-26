#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct {
    char base[0x10];
    float f10;
    float f14;
    int i18;
    unsigned char b1C;
    unsigned char b1D;
    char pad1E[2];
    int i20;
} Node24;
extern void cSkaTrans_opAssign(Node24* dst, Node24* src);
extern void cArray_cSkaBlendSequenceItem_opAssign(Node24* dst, Node24* src);

/* Copy: base parts via cSkaTrans_opAssign and cArray_cSkaBlendSequenceItem_opAssign, then the remaining fields; returns dst. */
Node24* cSkaTransBLEND_opAssign(Node24* dst, Node24* src)
{
    cSkaTrans_opAssign(dst, src);
    cArray_cSkaBlendSequenceItem_opAssign(dst, src);
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->i18 = src->i18;
    dst->b1C = src->b1C;
    dst->b1D = src->b1D;
    dst->i20 = src->i20;
    return dst;
}
