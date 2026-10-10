#include "types.h"
#pragma optimization_level 1

extern void func_00136DA0(int*);
extern void Mem_Free(int, int, int, int);
extern void func_0012F530(int*, int);

/* Runs Mem_Free(b, a, d, e) inside a scoped guard object. */
void func_00209F70(int a, int b, int c, int d, int e) {
    int guard;
    func_00136DA0(&guard);
    Mem_Free(b, a, d, e);
    func_0012F530(&guard, -1);
}
