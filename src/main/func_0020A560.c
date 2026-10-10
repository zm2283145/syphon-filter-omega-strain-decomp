#include "types.h"
#pragma optimization_level 1

typedef struct { int unk0; int unk4; int unk8; } Triple;
extern void func_0020A610(Triple* dst, Triple* src);
extern void func_0020A5F0(int* dst, int* src);
extern void func_0020A5D0(int* dst, int* src);

/* Assigns src to dst member by member (no-op on self-assignment). */
void func_0020A560(Triple* dst, Triple* src)
{
    if (dst != src) {
        func_0020A610(dst, src);
        func_0020A5F0(&dst->unk8, &src->unk8);
        func_0020A5D0(&dst->unk4, &src->unk4);
    }
}
