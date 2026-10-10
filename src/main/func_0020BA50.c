#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { int head; int mid; int tail; } Triple;
extern void func_0020BAE0(Triple* dst, Triple* src);
extern void func_0020BAC0(int* dst, int* src);
extern void func_0020A5D0(int* dst, int* src);

/* Assignment: copies the three parts unless dst == src. */
void func_0020BA50(Triple* dst, Triple* src)
{
    if (dst != src) {
        func_0020BAE0(dst, src);
        func_0020BAC0(&dst->tail, &src->tail);
        func_0020A5D0(&dst->mid, &src->mid);
    }
}
