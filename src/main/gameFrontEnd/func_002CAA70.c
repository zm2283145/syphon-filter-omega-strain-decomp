#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct F2CAA70 { char c[0x2D]; };
extern "C" {
extern F2CAA70 D_0048C0D0;
void* Mem_Alloc(int pool, void* p, char* file, int line);
}
extern "C" void* func_002CAA70(void* p)
{
    AllocGuard g;
    F2CAA70 f = D_0048C0D0;
    return Mem_Alloc(2, p, f.c, 0);
}