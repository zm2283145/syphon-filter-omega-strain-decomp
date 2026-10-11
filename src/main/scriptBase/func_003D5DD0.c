#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BD3B0[];
void func_00397F80(void* p, int flags);
void operator_delete(void* p);
}
extern "C" void* func_003D5DD0(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            Mem_Free(0, b, D_004BD3B0, 0x222);
        }
        {
            void* m = (char*)self + 8;
            if (m)
                func_00397F80(m, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}