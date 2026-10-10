#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { char pad[0xC]; unsigned char flag; } Item0C;
extern void func_0020BDE0(Item0C* dst, Item0C* src);

/* Copies the base part with func_0020BDE0, then the flag byte; returns dst. */
Item0C* func_0020BD90(Item0C* dst, Item0C* src)
{
    func_0020BDE0(dst, src);
    dst->flag = src->flag;
    return dst;
}
