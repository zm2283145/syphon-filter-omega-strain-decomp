#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_00267740(void);
void func_00138350(void* self, int flags);
}
extern "C" void func_0040A290(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            __destroy_array((char*)allocation + 0xC, (void*)func_00267740, 0x38, 5);
            func_00138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
}