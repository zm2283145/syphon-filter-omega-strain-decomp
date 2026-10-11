#include "types.h"

/* Free a block under the allocator guard. */
typedef struct { int w[1]; } Guard_3B8C50;
extern char D_004BC4D0[];
extern void func_00136DA0(Guard_3B8C50* g);
extern void func_0012F530(Guard_3B8C50* g, int flag);
extern void Mem_Free(int pool, void* p, char* file, int line);

void func_003B8C50(void* self, void* p)
{
    if (p) {
        Guard_3B8C50 g;
        func_00136DA0(&g);
        Mem_Free(0, p, D_004BC4D0, 100);
        func_0012F530(&g, -1);
    }
}