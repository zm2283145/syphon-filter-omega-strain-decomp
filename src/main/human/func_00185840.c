#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
int func_003FA780(int* a, unsigned char* flag, void** p);
void func_002C6B70(void* p, int a);
void func_002C6690(void* p, int a);
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_0049D8D0[];
}
extern "C" void func_00185840(void)
{
    unsigned char flag;
    void* p;
    int a;
    while (func_003FA780(&a, &flag, &p)) {
        if (flag) func_002C6B70(p, a);
        else func_002C6690(p, a);
        {
            void* q = p;
            AllocGuard guard;
            Mem_Free(0, q, D_0049D8D0, 0x447D);
        }
    }
}
