#include "types.h"
extern char D_004C3460[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int del);
extern void Mem_Free(int heap, void* p, const char* file, int line);
void func_00472820(void* self, void* p)
{
    if (p) {
        int g[1];
        func_00136DA0(g);
        Mem_Free(0, p, D_004C3460, 100);
        func_0012F530(g, -1);
    }
}