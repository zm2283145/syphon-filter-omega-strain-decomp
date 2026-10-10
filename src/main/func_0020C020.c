#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { int head; char rest[4]; } Pair;
extern void func_00209870(Pair* dst, Pair* src);
extern void func_0020C080(void* dst, void* src);

/* Copies both parts of the pair; returns dst. */
Pair* func_0020C020(Pair* dst, Pair* src)
{
    func_00209870(dst, src);
    func_0020C080(dst->rest, src->rest);
    return dst;
}
