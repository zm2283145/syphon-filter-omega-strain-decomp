#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A6FA8[];
extern void** D_004F7C70;
extern int D_004F7C78;
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00238F20(void)
{
    int i;
    for (i = 0; i < D_004F7C78; i++) {
        void* p = D_004F7C70[i];
        AllocGuard g;
        Mem_Free(0, p, D_004A6FA8, 0x69C);
    }
    void** q = D_004F7C70;
    if (q) {
        {
            AllocGuard g;
            Mem_Free(0, q, D_004A6FA8, 0x6A0);
        }
        D_004F7C70 = 0;
    }
    D_004F7C78 = 0;
}

