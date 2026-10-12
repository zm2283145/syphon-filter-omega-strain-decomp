#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void func_00397F80(void* p, int flags);
void operator_delete(void* p);
}
extern "C" void* func_00397EA0(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            Mem_Free(0, b, "particle.cc", 0x11A0);
        }
        {
            void* m = (char*)self + 4;
            if (m)
                func_00397F80(m, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}