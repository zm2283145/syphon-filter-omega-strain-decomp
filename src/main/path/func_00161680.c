#include "types.h"
extern char D_0049C1B8[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int flag);
extern void func_00161720(void* p, int flag);
extern void Mem_Free(int pool, void* p, char* file, int line);
extern void operator_delete(void* p);
typedef struct { char pad[0x74]; void* p; } S_1680;
S_1680* func_00161680(S_1680* self, short flag)
{
    if (self) {
        void* p = self->p;
        if (p) {
            int g[1];
            func_00136DA0(g);
            func_00161720(p, -1);
            Mem_Free(0, p, D_0049C1B8, 0x542);
            func_0012F530(g, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}