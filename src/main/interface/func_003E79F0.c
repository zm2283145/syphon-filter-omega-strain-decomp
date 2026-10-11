#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BDEC8[];
extern void* D_00539248;
void func_003EF120(void* p, int flags);
void func_00381260(void* p);
void operator_delete(void* p);
}
extern "C" void* func_003E79F0(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            func_003EF120(b, -1);
            Mem_Free(0, b, D_004BDEC8, 0x45);
        }
        func_00381260(D_00539248);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}