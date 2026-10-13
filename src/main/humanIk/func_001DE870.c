#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
extern char D_004A0170[];
}

template <class T> static inline void Swap1DE870(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

extern "C" void func_001DE870(unsigned int n, float* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)Mem_Alloc(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE870(data[k], data[j]);
        Swap1DE870(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        Mem_Free(0, tmp, D_004A0170, 0x7C3);
    }
}

