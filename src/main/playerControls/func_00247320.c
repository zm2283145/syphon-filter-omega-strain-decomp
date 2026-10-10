#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char pad[0x128]; void* buf; } E4Own;
extern "C" {
extern char D_004A75A0[];
void func_00252FB0(void* p, int n);
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00247320(E4Own* o)
{
    void* p = o->buf;
    if (p) {
        {
            AllocGuard g;
            func_00252FB0(p, -1);
            Mem_Free(0, p, D_004A75A0, 0xF29);
        }
        o->buf = 0;
    }
}
