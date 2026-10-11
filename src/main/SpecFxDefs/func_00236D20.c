#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char pad[0xC]; void* buf; } E4Own;
extern "C" {
extern char D_004A6E38[];
void func_003A2BA0(void* p, int n);
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00236D20(E4Own* o)
{
    void* p = o->buf;
    if (p) {
        {
            AllocGuard g;
            func_003A2BA0(p, -1);
            Mem_Free(0, p, D_004A6E38, 0x12C);
        }
        o->buf = 0;
    }
}
