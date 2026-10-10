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
extern void MotionSlider_CopyChildren(Node24* dst, Node24* src);

/* Copy: base part via MotionSlider_CopyChildren, then the remaining fields; returns dst. */
Node24* func_0020B270(Node24* dst, Node24* src)
{
    MotionSlider_CopyChildren(dst, src);
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->i18 = src->i18;
    dst->b1C = src->b1C;
    dst->b1D = src->b1D;
    dst->i20 = src->i20;
    return dst;
}
