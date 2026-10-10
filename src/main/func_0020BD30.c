#include "types.h"

typedef struct { int unk0; int unk4; } Pair209;

extern void func_00209ED0(Pair209* dst, Pair209* src);
extern void func_0020BD90(int* dst, int* src);

#pragma optimization_level 1
/* Copies both halves of src into dst with their helpers; returns dst (unit built at -O1). */
Pair209* func_0020BD30(Pair209* dst, Pair209* src)
{
    func_00209ED0(dst, src);
    func_0020BD90(&dst->unk4, &src->unk4);
    return dst;
}
#pragma optimization_level reset
