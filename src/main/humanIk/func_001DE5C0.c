#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
extern char D_004A0170[];
}

template <class T> static inline void Swap1DE5C0(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct V3 { float v[3]; float w; V3(const V3& o) { for (int i = 0; i < 3; i++) v[i] = o.v[i]; } V3& operator=(const V3& o) { v[0] = o.v[0]; v[1] = o.v[1]; v[2] = o.v[2]; return *this; } };

extern "C" void func_001DE5C0(unsigned int n, V3* data, unsigned int* order)
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
        Swap1DE5C0(data[k], data[j]);
        Swap1DE5C0(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        Mem_Free(0, tmp, D_004A0170, 0x7C3);
    }
}

