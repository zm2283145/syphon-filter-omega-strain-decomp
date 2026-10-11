#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S2C9E20 { char pad[0x25C]; void* p25C; };
extern "C" {
extern char D_004ACF10[];
void func_0036CD80(void* p);
void func_0036D5D0(void* p, short f);
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_002C9E20(S2C9E20* s)
{
    if (s->p25C) {
        func_0036CD80(s->p25C);
        {
            void* p = s->p25C;
            AllocGuard g;
            func_0036D5D0(p, -1);
            Mem_Free(0, p, D_004ACF10, 0x639);
        }
        s->p25C = 0;
    }
}