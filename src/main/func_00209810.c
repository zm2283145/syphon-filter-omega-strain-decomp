#include "types.h"

typedef struct { int unk0; int unk4; } Pair209;

extern void func_00209870(Pair209* dst, Pair209* src);
extern void MotionSliderChild_CopyThresholds(int* dst, int* src);

#pragma optimization_level 1
/* Copies both halves of src into dst with their helpers; returns dst (unit built at -O1). */
Pair209* func_00209810(Pair209* dst, Pair209* src)
{
    func_00209870(dst, src);
    MotionSliderChild_CopyThresholds(&dst->unk4, &src->unk4);
    return dst;
}
#pragma optimization_level reset
